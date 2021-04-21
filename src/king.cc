#include "king.h"

namespace chess {

    bool King::CheckPossibleMove(int new_x_position, int new_y_position, Board board) {
        if (board.getBoard()[new_x_position][new_y_position].getColor() != 2) {
            return false;
        }
        return true;
    }

    bool King::Move(int new_x_position, int new_y_position, Board board) {
        if (abs(current_position_x_ - new_x_position) <= 1 && abs(current_position_y_ - new_y_position) <= 1) {
            return true;
        }
        return false;
    }

    bool King::CheckCastle(int new_x_position, int new_y_position, Board board) {
        if (current_position_x_ == 0 || current_position_x_ == 7) {
            if (current_position_y_ == 4) {
                //Queenside castle have to check queenside back rank

                //Kingside castle have to check kingside back rank
            }
        }
    }
}