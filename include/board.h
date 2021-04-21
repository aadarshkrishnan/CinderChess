#pragma once

#include <vector>
#include "piece.h"

namespace chess {

    class Board {

    public:
        const std::vector<std::vector<Piece>> &getBoard() const;


    private:
        std::vector<std::vector<Piece>> board_;
    };
}  // namespace chess
