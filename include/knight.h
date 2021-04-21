#pragma once

#include "piece.h"

namespace chess {

    class Knight: public Piece {
    public:
        bool Move(int new_x_position, int new_y_position, Board board) override;
        bool CheckPossibleMove(int new_x_position, int new_y_position, Board board) override;
    };
}  // namespace chess
