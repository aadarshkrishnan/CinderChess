#pragma once

#include "piece.h"

namespace chess {

    class Rook: public Piece {
    public:
        bool Move(int new_x_position, int new_y_position);
        bool CheckCastle();
    };
}  // namespace chess
