#pragma once

namespace chess {
    // Base class
    class Piece {
    public:
        //https://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm
        virtual void Move();

        boolean CheckPossibleMove();
        boolean CheckSameColor();
        boolean CheckBoardBounds();

    protected:
        int color_;
        int current_position_x_;
        int current_position_y_;
    };
}