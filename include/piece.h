#pragma once

#include <string>
#include "board.h"

namespace chess {
    class Board;
    // Base class
    class Piece {
    public:
        Piece(int color, int x_position, int y_position, std::string picture);
        virtual ~Piece();

        //https://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm
        virtual bool Move(int new_x_position, int new_y_position, Board board) = 0;
        virtual bool CheckPossibleMove(int new_x_position, int new_y_position, Board board) = 0;

        bool CheckSameColor(int new_x_position, int new_y_position, Board board);

        int getColor() const;

        const std::string &getPicture() const;

        void SetPosition(int x, int y);

    protected:
        //0 is black piece 1 is white piece 2 is empty
        int color_;
        int current_position_x_;
        int current_position_y_;
        std::string picture_;
    };
}  // namespace chess