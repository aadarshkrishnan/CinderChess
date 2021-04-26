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
         * The visual of the simulation.
         */
        void draw() override;

        /**
         * Changing the object the visual uses for each frame.
         */
        void update() override;

    private:
        Board game_board_;

    };
}  // namespace chess
