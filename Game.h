#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "IO.h"

using movePos = std::pair<pos, pos>;

class Game
{
public:
    enum class Player { NONE, BLACK, WHITE };
    Game();
    ~Game();
    Player GetWinner() const;
    void Start();
private:
    bool GetDirection() const;
    movePos MakeIO();
    void SwitchPlayer();
    void UpdateScore();
    int mWhiteScore;
    int mBlackScore;
    Player mCurrentPlayer;
    bool bIsSurrender;
    Board mBoard;
};

#endif // GAME_H
