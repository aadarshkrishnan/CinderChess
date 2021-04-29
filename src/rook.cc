#include "rook.h"

namespace chess {

    bool Rook::Move(int new_x_position, int new_y_position, const Board &board) {
        // horizontal movement
        if (current_position_x_ == new_x_position) {
            if (current_position_y_ != new_y_position) {
                return true;
            }
        }
        // vertical movement
        if (current_position_y_ == new_y_position) {
            if (current_position_x_ != new_x_position) {
                return true;
            }
        }
        return false;
    }

    bool Rook::CheckPossibleMove(int new_x_position, int new_y_position, const Board &board) {
        if (current_position_x_ == new_x_position) {
            int y_increment = (new_y_position - current_position_y_) / (abs(new_y_position - current_position_y_));
            for (int i = current_position_y_ + y_increment; i != new_y_position; i += y_increment) {
                if (board.get_board()[new_x_position][i]->get_color() != 2) {
                    return false;
                }
            }
        }
        if (current_position_y_ == new_y_position) {
            int x_increment = (new_x_position - current_position_x_) / (abs(new_x_position - current_position_x_));
            for (int i = current_position_x_ + x_increment; i != new_x_position; i += x_increment) {
                if (board.get_board()[i][new_y_position]->get_color() != 2) {
                    return false;
                }
            }
        }
        return true;
    }
}