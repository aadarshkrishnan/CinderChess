#pragma once

#include "piece.h"
#include "board.h"

namespace chess {

    class King : public Piece {
    public:
        King (int color, int x_position, int y_position, std::string picture) : Piece(color, x_position, y_position, picture) {}
        bool Move(int new_x_position, int new_y_position, Board board) override;
        bool CheckPossibleMove(int new_x_position, int new_y_position, Board board) override;

        bool CheckCastle(int new_x_position, int new_y_position, const Board& board);
    };
}  // namespace chess