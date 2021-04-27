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
        void SwitchPositions(int x1, int y1, int x2, int y2);
    private:
        std::vector<std::vector<Piece*>> board_;
    };
}  // namespace chess
