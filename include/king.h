#pragma once

namespace chess {

    class King: public Piece {
        bool Move();
        bool CheckCastle();
    };
}