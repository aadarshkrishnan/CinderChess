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

        /**
         * Castles white on the king side.
         */
        void HandleWhiteKingSideCastle();

        /**
         * Castles black on the king side.
         */
        void HandleBlackKingSideCastle();

        /**
         * Castles white on the queen side.
         */
        void HandleWhiteQueenSideCastle();

        /**
         * Castles black on the queen side.
         */
        void HandleBlackQueenSideCastle();

        /**
         * Handles castling in general
         * @param row the row of board
         * @param col the column of board
         */
        void HandleCastling(int row, int col);

        /**
         * Checks if the king had moved before, which would no longer allow it to castle.
         * @return if the king had moved before
         */
        bool CheckPreviousKingMove();

        /**
         * Checks if there is an opposing color piece in attacking in between the king side castle.
         * @param color the row the castling is occurring on
         * @param opposing_color the other color's color
         * @return if there is an opposing color piece in attacking in between the king side castle
         */
        bool CheckKingCastleIntersection(int color, int opposing_color);

        /**
         * Checks if there is an opposing color piece in attacking in between the queen side castle.
         * @param color the row the castling is occurring on
         * @param opposing_color the other color's color
         * @return if there is an opposing color piece in attacking in between the queen side castle
         */
        bool CheckQueenCastleIntersection(int color, int opposing_color);

        /**
         * Checks if a pawn is on the last rank.
         * @param row the row of the board
         * @param col the column of the board
         * @return if there is a pawn that needs to be promoted
         */
        bool CheckPawnPromotion(int row, int col);

    private:
        Board game_board_;
        std::vector<std::string> notation_;
        int current_x = -1;
        int current_y = -1;

    };
}  // namespace chess
