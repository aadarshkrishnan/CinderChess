#include <cmath>
#include "bishop.h"

namespace chess {
    bool Bishop::Move(int new_x_position, int new_y_position, Board board) {
        if (abs(current_position_x_ - new_x_position) == abs(current_position_y_ - new_y_position)) {
            return true;
        }
        return false;
    }

    bool Bishop::CheckPossibleMove(int new_x_position, int new_y_position, Board board) {
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