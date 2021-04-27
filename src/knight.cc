#include "knight.h"

namespace chess {

    bool Knight::Move(int new_x_position, int new_y_position, const Board& board) {
        if ((abs(current_position_x_ - new_x_position) == 2 && abs(current_position_y_ - new_y_position) == 1) ||
        (abs(current_position_x_ - new_x_position) == 1 && abs(current_position_y_ - new_y_position) == 2))
        {
            return true;
        }
        return false;
    }

    bool Knight::CheckPossibleMove(int new_x_position, int new_y_position, Board board) {
        if (board.getBoard()[new_x_position][new_y_position]->getColor() != board.getBoard()[current_position_x_][current_position_y_]->getColor()) {
            return true;
        }
        return false;
    }
}