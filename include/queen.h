#pragma once

#include "piece.h"

namespace chess {

    class Queen: public Piece {
    public:
        bool Move(int new_x_position, int new_y_position);
    };
}  // namespace chess
