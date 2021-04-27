#include "rook.h"
#include "space.h"

namespace chess {

    bool Rook::Move(int new_x_position, int new_y_position, const Board& board) {
        if (current_position_x_ != new_x_position || current_position_y_ != new_y_position) {
            return false;
        }
        return true;
    }

    bool Rook::CheckPossibleMove(int new_x_position, int new_y_position, const Board& board) {
        if (current_position_x_ == new_x_position) {
            int y_increment = (new_y_position - current_position_y_) / (abs(new_y_position - current_position_y_));
            for (int i = current_position_y_ + y_increment; i != new_y_position; i += y_increment) {
                if (board.getBoard()[new_x_position][i]->getColor() != 2) {
                    return false;
                }
            }
        }
        if (current_position_y_ == new_y_position) {

            int x_increment = (new_x_position - current_position_x_) / (abs(new_x_position - current_position_x_));
            for (int i = current_position_x_ + x_increment; i != new_x_position; i += x_increment) {
                if (board.getBoard()[i][new_y_position]->getColor() != 2) {
                    return false;
                }
            }
        }
        return true;
    }
}