#include "pawn.h"

namespace chess {

    bool Pawn::Move(int new_x_position, int new_y_position, Board board) {
        //black
        if (board.getBoard()[current_position_x_][current_position_y_]->getColor() == 0) {
            // regular movement
            if (current_position_y_ == 1) {
                if (new_y_position - current_position_y_ <= 2) {
                    return true;
                }
            } else {
                if (new_y_position - current_position_y_ == 1) {
                    return true;
                }
            }
            //pawn takes
            if (abs(current_position_x_ - new_x_position) == 1 && (new_y_position - current_position_y_ == 1)) {
                if (board.getBoard()[new_x_position][new_y_position]->getColor() != 0) {
                    return true;
                }
            }
        }
        //white
        else if (board.getBoard()[current_position_x_][current_position_y_]->getColor() == 1) {
            // regular movement
            if (current_position_y_ == 6) {
                if (current_position_y_ - new_y_position <= 2) {
                    return true;
                }
            } else {
                if (current_position_y_ - new_y_position == 1) {
                    return true;
                }
            }
            //pawn takes
            if (abs(current_position_x_ - new_x_position) == 1 && (current_position_y_ - new_y_position == 1)) {
                if (board.getBoard()[new_x_position][new_y_position]->getColor() != 1) {
                    return true;
                }
            }
        }

        return false;
    }

    bool Pawn::CheckPossibleMove(int new_x_position, int new_y_position, Board board) {
        return true;
    }
}