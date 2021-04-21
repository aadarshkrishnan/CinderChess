#include "queen.h"
#include "space.h"


namespace chess {

    bool Queen::Move(int new_x_position, int new_y_position, Board board) {
        //if it's not a straight move
        if (current_position_x_ != new_x_position || current_position_y_ != new_y_position) {
            //it has to be diagonal
            if (abs(current_position_x_ - new_x_position) != abs(current_position_y_ - new_y_position)) {
                return false;
            }
        }
        return true;
    }

    bool Queen::CheckPossibleMove(int new_x_position, int new_y_position, Board board) {
        // horizontal movement
        if (current_position_x_ == new_x_position) {
            int yIncrement = (new_y_position - current_position_y_) / (abs(new_y_position - current_position_y_));
            for (int i = current_position_y_ + yIncrement; i != new_y_position; i += yIncrement) {
                if (board.getBoard()[new_x_position][i].getColor() != 2) {
                    return false;
                }
            }
            //vertical movement
        } else if (current_position_y_ == new_y_position) {

            int xIncrement = (new_x_position - current_position_x_) / (abs(new_x_position - current_position_x_));
            for (int i = current_position_x_ + xIncrement; i != new_x_position; i += xIncrement) {
                if (board.getBoard()[i][new_y_position].getColor() != 2) {
                    return false;
                }
            }
        }
        //diagonal movement
        int xIncrement = (current_position_x_ - new_x_position) / (abs(current_position_x_ - new_x_position));
        int yIncrement = (current_position_y_ - new_y_position) / (abs(current_position_y_ - new_y_position));

        for (int i = 1; i < abs(new_x_position - current_position_x_); i++) {
            if (board.getBoard()[new_x_position + xIncrement*i][new_y_position + yIncrement*i].getColor() != 2) {
                return false;
            }
        }
        return true;
    }
}