#include "king.h"
#include "rook.h"

namespace chess {

    bool King::CheckPossibleMove(int new_x_position, int new_y_position, Board board) {
        if (board.getBoard()[new_x_position][new_y_position]->getColor() != 2) {
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

    bool King::CheckCastle(int new_x_position, int new_y_position, const Board& board) {
        if (current_position_x_ == 0 || current_position_x_ == 7) {
            if (current_position_y_ == 3 && abs(current_position_y_ - new_y_position) == 2) {
                //Queenside castle have to check queenside back rank
                if (new_y_position < current_position_y_) {
                    //empty spaces
                    if (board.getBoard()[current_position_x_][2]->getColor() == 2 &&
                            board.getBoard()[current_position_x_][1]->getColor() == 2) {
                        //roock to castle with is present
                        if (typeid(board.getBoard()[current_position_x_][0]) == typeid(Rook())) {
                            return true;
                        }
                    }
                }
                //Kingside castle have to check kingside back rank
                else if (new_y_position > current_position_y_) {
                    //empty spaces
                    if (board.getBoard()[current_position_x_][4]->getColor() == 2 &&
                            board.getBoard()[current_position_x_][5]->getColor() == 2 &&
                            board.getBoard()[current_position_x_][6]->getColor() == 2) {
                        //rook to castle with is present
                        if (typeid(board.getBoard()[current_position_x_][7]) == typeid(Rook())) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
}