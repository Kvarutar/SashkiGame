#include "Game.h"
#include <iostream>
#include <stdlib.h>

Game::Game() : mBlackScore(0), mWhiteScore(0), mCurrentPlayer(Player::NONE), bIsSurrender(false)
{
}

Game::~Game()
{
}

int color;

Game::Player Game::GetWinner() const
{
    Player winner(Player::NONE);

    if (bIsSurrender)//если один из игроков сдается
    {
        if (mCurrentPlayer == Player::WHITE)
        {
            winner = Player::BLACK;
        }
        else if (mCurrentPlayer == Player::BLACK)
        {
            winner = Player::WHITE;
        }
    }
    else
    {
        if (mWhiteScore == 12)//если у одного из игроков срублено 12 фишек, то он победитель
        {
            winner = Player::WHITE;
        }
        else if (mBlackScore == 12)
        {
            winner = Player::BLACK;
        }
    }
    return winner;
}

void Game::Start()
{
    mBoard.ResetMap();
    while (GetWinner() == Player::NONE)//проверка конца игры
    {
        Board::MoveResult moveResult(Board::MoveResult::PROHIBITED);
        while (moveResult == Board::MoveResult::PROHIBITED)
        {
            if (mCurrentPlayer == Player::BLACK)
            {
                color = 1;
            }
            else if (mCurrentPlayer == Player::WHITE)
            {
                color = 2;
            }
            else { color = 0; }

            //WScore = mWhiteScore;
            bool direction = GetDirection();
            auto newMove = MakeIO();
            auto moveResult = mBoard.MakeMove(newMove.first, newMove.second, direction, false);
            // SwitchPlayer();

            if (moveResult != Board::MoveResult::PROHIBITED)
            {
                SwitchPlayer();
            }

            if (moveResult == Board::MoveResult::SUCCESSFUL_COMBAT)
            {
                UpdateScore();
            }

        }

    }
};


bool Game::GetDirection() const
{
    bool direction;

    if (mCurrentPlayer == Player::WHITE)
    {
        direction = false;
    }
    else { direction = true; }
    return direction;
};

movePos Game::MakeIO()
{
    int* Wcount = &mWhiteScore;
    int* Bcount = &mBlackScore;
    int* CurPlay = &color;
    IO* mIO = new IO(*Wcount, *Bcount, *CurPlay);
    //отрисовка карты
    system("cls"); //очистка для винды
    //system("clear"); // очистка для мака
    if (system("CLS")) system("clear");
    auto mape = mBoard.GetMap();
    mIO->DrawBoard(mape);

    //запрос хода
    auto newMove = mIO->GetMove();
    return std::move(newMove);
};

void Game::SwitchPlayer()
{

    switch (mCurrentPlayer)
    {
    case Player::WHITE:
        mCurrentPlayer = Player::BLACK;
        break;
    default:
        mCurrentPlayer = Player::WHITE;
        break;
    }
};

void Game::UpdateScore()
{
    if (mCurrentPlayer == Player::WHITE)
    {
        mWhiteScore++;
    }
    else
    {
        mBlackScore++;
    }
}