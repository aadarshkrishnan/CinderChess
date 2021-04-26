#include <board.h>
#include "game.h"

namespace chess {

    using glm::vec2;

    Game::Game() {
        game_board_.SetBoard();
        for (size_t row = 0; row < 8; ++row) {
            for (size_t col = 0; col < 8; ++col) {
                std::cout << game_board_.getBoard()[row][col]->getColor();
            }
            std::cout << std::endl;
        }
    }

    void Game::draw() {
        for (size_t row = 0; row < 8; ++row) {
            for (size_t col = 0; col < 8; ++col) {

                if (game_board_.getBoard()[row][col]->getColor() == 2) {
                    ci::gl::color((ci::Color::gray(0.3f)));
                } else if (game_board_.getBoard()[row][col]->getColor() == 1){
                    ci::gl::color(ci::Color("white"));
//                    auto img = loadImage(ci::loadUrl(
//                            "https://e7.pngegg.com/pngimages/82/550/png-clipart-chess-piece-black-white-pawn-white-and-black-in-chess-pisces-king-black-white.png"
//                    ));
//                    ci::gl::draw(ci::gl::Texture2d::create(img));
                } else {
                    ci::gl::color(ci::Color("black"));
                }

                vec2 pixel_top_left = vec2(100,100) + vec2(col * 40,
                                                              row * 40);

                vec2 pixel_bottom_right =
                        pixel_top_left + vec2(40, 40);
                ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);

                ci::gl::drawSolidRect(pixel_bounding_box);


                ci::gl::color(ci::Color("red"));

                ci::gl::drawStrokedRect(pixel_bounding_box);
            }
        }
    }

    void Game::update() {
        AppBase::update();
    }
}

