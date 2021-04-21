#include "board.h"

namespace chess {

    const std::vector<std::vector<Piece>> &Board::getBoard() const {
        return board_;
    }
}