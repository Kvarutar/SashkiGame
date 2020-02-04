#include "IO.h"
#include <iostream>
#include "Cell.h"
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>

int Wscore;
int Bscore;
int Player;

IO::IO(int& mWhiteScore, int& mBlackScore, int& mCurrentPlayer)
{
    Wscore = mWhiteScore;
    Bscore = mBlackScore;
    Player = mCurrentPlayer;
}

IO::~IO()
{
}

movePos IO::GetMove()
{

    bool Choose = true;
    movePos position;
    int x1, x2, x = 0, y = 40;
    int p1 = 0, p2 = 0;
    //((Player == 1) || (Player == 0)) {
    std::cin >> p1;
    std::cin >> p2;

    p1 = p1 - 11;
    p2 = p2 - 11;

    /*if (Player == 2)
    {
        for (int i = 50; i < 80; i++)
        {
            for (int i = 50; i < 80; i++){
                x1 = i;
                x2 = y;
                int ten1 = x1 / 10;
                int one1 = x1 - 10 * ten1;
                int ten2 = x2 / 10;
                int one2 = x2 - 10 * ten2;
                const int dY = ten2 - ten1;
                const int dX = one2 - one1;
                if ((abs(dX) == 2 && abs(dY) == 2) || ((abs(dX) == 1 && dY == -1))) { p1 = i; p2 = y; x = -1; break; } //goto GoForward;  };
                y++;
            }
            if (x == -1) { break; }
        }
    };*/

    position.first.first = p1 / 10;
    position.first.second = p1 - 10 * position.first.first;

    position.second.first = p2 / 10;
    position.second.second = p2 - 10 * position.second.first;

    return std::move(position);
}


void IO::DrawBoard(const map& board)
{
    size_t boardSize = pow(board.size(), 0.5);

    std::cout << "  ";
    for (size_t i = 0; i < boardSize; i++)
    {
        std::cout << i + 1 << " ";
    }

    std::cout << std::endl;

    for (size_t i = 0; i < boardSize; i++)
    {
        std::cout << i + 1 << "|";

        for (size_t j = 0; j < boardSize; j++)
        {
            std::string cellValue = CastState(board.at(pos(i, j)).GetState());
            std::cout << cellValue;
            std::cout << "|";
        }
        std::cout << i + 1 << std::endl;
    }

    std::cout << "  ";

    for (size_t i = 0; i < boardSize; i++)
    {
        std::cout << i + 1 << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "WHITE: " << Wscore << std::endl;
    std::cout << "BLACK: " << Bscore << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    switch (Player)
    {
    case 1:
        std::cout << "WHITE TURN: " << std::endl;
        break;
    case 2:
        std::cout << "BLACK TURN: " << std::endl;
        break;
    default:
        std::cout << "WHITE TURN: " << std::endl;
    }

}

std::string IO::CastState(Cell::State state)
{
    std::string result;

    if (state == Cell::State::BLACK)
    {
        result = "B";
    }
    else if (state == Cell::State::WHITE)
    {
        result = "W";
    }
    else { result = " "; }

    return std::move(result);
}