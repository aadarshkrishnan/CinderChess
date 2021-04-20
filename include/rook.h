#pragma once

namespace chess {

    class Rook: public Piece {
        bool Move();
        bool CheckCastle();
    };
}
