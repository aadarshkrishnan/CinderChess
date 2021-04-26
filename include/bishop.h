#pragma once

#include "piece.h"
#include "board.h"

namespace chess {

    class Bishop: public Piece {
    public:
        Bishop (int color, int x_position, int y_position) : Piece(color, x_position, y_position) {}
        bool Move(int new_x_position, int new_y_position, Board board) override;
        bool CheckPossibleMove(int new_x_position, int new_y_position, Board board) override;
    };
}  // namespace chess