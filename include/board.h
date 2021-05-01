#pragma once

#include <vector>
#include "piece.h"

namespace chess {
    class Piece;

    /**
     * The 2d board that contains all the piece objects.
     */
    class Board {
    public:
        /**
         * Returns the board.
         * @return the board.
         */
        std::vector<std::vector<Piece *>> get_board() const;

        /**
         * Sets all the pieces in their starting positions.
         */
        void SetStartingPosition();

        /**
         * Board deconstructor.
         */
        ~Board();

        /**
         * Switches the positions of two pieces.
         * @param x1 the x coordinate of the first piece
         * @param y1 the y coordinate of the first piece
         * @param x2 the x coordinate of the second piece
         * @param y2 the y coordinate of the second piece
         */
        void SwitchPositions(int x1, int y1, int x2, int y2);

        void Promote(int row, int col);

    private:
        std::vector<std::vector<Piece *>> board_;
    };
}  // namespace chess
