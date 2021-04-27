#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "board.h"

namespace chess {
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

        void update() override;

        void mouseDown(ci::app::MouseEvent event) override;

    private:
        Board game_board_;
        std::vector<std::string> notation_;
        int current_x = -1;
        int current_y = -1;

    };
}  // namespace chess
