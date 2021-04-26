#pragma once

#include <vector>
#include "piece.h"

namespace chess {
    class Piece;
    class Board {

    public:
        std::vector<std::vector<Piece*>> getBoard() const;
        void SetBoard();
        ~Board();
    private:
        std::vector<std::vector<Piece*>> board_;
    };
}  // namespace chess
