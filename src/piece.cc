#include "piece.h"
#include "space.h"

namespace chess {

    Piece::Piece(int color, int x_position, int y_position) {
        color_ = color;
        current_position_x_ = x_position;
        current_position_y_ = y_position;
    }

    bool Piece::CheckSameColor(int new_x_position, int new_y_position, Board board) {
        if (board.getBoard()[new_x_position][new_y_position].getColor() == 2) {
            return true;
        } else if (board.getBoard()[new_x_position][new_y_position].getColor() == 0 &&
        board.getBoard()[current_position_x_][current_position_y_].getColor() == 1) {
            return true;
        } else if (board.getBoard()[new_x_position][new_y_position].getColor() == 1 &&
                   board.getBoard()[current_position_x_][current_position_y_].getColor() == 0) {
            return true;
        }
        return false;
    }

    int Piece::getColor() const {
        return color_;
    }
}
