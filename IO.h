#ifndef IO_H
#define IO_H
#include <utility>
#include <map>
#include "Cell.h"
#include <iostream>
#include "Game.h"


class Cell;
using movePos = std::pair<pos, pos>;
using map = std::map<pos, Cell>;

class IO
{
public:
    IO(int& mWhiteScore, int& mBlackScore, int& mCurrentPlayer);
    ~IO();
    static movePos GetMove();
    static void DrawBoard(const map& board);
private:
    static std::string CastState(Cell::State state);
};

#endif //IO_H