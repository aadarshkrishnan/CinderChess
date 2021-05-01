#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "board.h"

namespace chess {

    /**
     * The game that is being run by the cinder application.
     */
    class Game : public ci::app::App {
    public:

        /**
         * The game simulation.
         */
        Game();

        /**
         * The visual of the game.
         */
        void draw() override;

        /**
         * Takes place of mouse click and uses that data to edit the board.
         * @param event mouse click
         */
        void mouseDown(ci::app::MouseEvent event) override;

        void HandleWhiteKingSideCastle();

        void HandleBlackKingSideCastle();

        void HandleWhiteQueenSideCastle();

        void HandleBlackQueenSideCastle();

        void HandleCastling(int row, int col);

        bool CheckPreviousKingMove();

        bool CheckKingCastleIntersection(int color, int opposing_color);

        bool CheckQueenCastleIntersection(int color, int opposing_color);

        bool CheckPawnPromotion(int row, int col);

    private:
        Board game_board_;
        std::vector<std::string> notation_;
        int current_x = -1;
        int current_y = -1;

    };
}  // namespace chess
