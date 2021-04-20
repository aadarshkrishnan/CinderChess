#pragma once

namespace chess {

    class Pawn: public Piece {
        bool Move();
        bool CheckEnPassant();
    };
}  // namespace chess