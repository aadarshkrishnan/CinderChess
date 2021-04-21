#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

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

        /**
         * The action taken when a certain key is pressed.
         * up
         * down
         * space
         * left
         * right
         * @param event a key movement
         */
    };
}  // namespace chess
