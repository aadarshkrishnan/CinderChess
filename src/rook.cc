#include "rook.h"
#include "space.h"

namespace chess {

    bool Rook::Move(int new_x_position, int new_y_position, Board board) {
        if (current_position_x_ != new_x_position || current_position_y_ != new_y_position) {
            return false;
        }
        return true;
    }

    bool Rook::CheckPossibleMove(int new_x_position, int new_y_position, Board board) {
        if (current_position_x_ == new_x_position) {
            int yIncrement = (new_y_position - current_position_y_) / (abs(new_y_position - current_position_y_));
            for (int i = current_position_y_ + yIncrement; i != new_y_position; i += yIncrement) {
                if (typeid(board.getBoard()[new_x_position][i].getColor()) != typeid(Space())) {
                    return false;
                }
            }
        }
        if (current_position_y_ == new_y_position) {

            int xIncrement = (new_x_position - current_position_x_) / (abs(new_x_position - current_position_x_));
            for (int i = current_position_x_ + xIncrement; i != new_x_position; i += xIncrement) {
                if (typeid(board.getBoard()[i][new_y_position].getColor()) != typeid(Space())) {
                    return false;
                }
            }
        }
        return true;
    }
}