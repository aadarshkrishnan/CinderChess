#include <board.h>
#include "game.h"
#include "rook.h"

namespace chess {

    using glm::vec2;

    Game::Game() {
        ci::app::setWindowSize(750, 750);
        game_board_.SetBoard();
//        for (size_t row = 0; row < 8; ++row) {
//            for (size_t col = 0; col < 8; ++col) {
//                std::cout << game_board_.getBoard()[row][col]->getColor();
//            }
//            std::cout << std::endl;
//        }
    }

    void Game::draw() {
        for (size_t row = 0; row < 8; ++row) {
            for (size_t col = 0; col < 8; ++col) {

//                if (game_board_.getBoard()[row][col]->getColor() == 2) {
//                    ci::gl::color((ci::Color::gray(0.3f)));
//                } else if (game_board_.getBoard()[row][col]->getColor() == 1){
//                    ci::gl::color(ci::Color("white"));
//                } else {
//                    ci::gl::color(ci::Color("black"));
//                }

                ci::gl::color(ci::Color("white"));




                vec2 pixel_top_left = vec2(100,100) + vec2(col * 70,
                                                              row * 70);

                vec2 pixel_bottom_right =
                        pixel_top_left + vec2(70, 70);
                ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);

                ci::gl::drawSolidRect(pixel_bounding_box);


                ci::gl::color(ci::Color("black"));
//                std::cout << typeid(game_board_.getBoard()[row][col]).name() << std::endl;
//                if (typeid(game_board_.getBoard()[row][col]) == typeid(game_board_.getBoard()[0][0])) {
//                    ci::gl::drawStringCentered(("♖︎"), vec2(120 + col * 40, 110 + row * 40),
//                                               ci::Color("black"), ci::Font("Arial", 30));
//                } else {
                    ci::gl::drawString((game_board_.getBoard()[row][col]->getPicture()), vec2(115 + col * 70, 110 + row * 70),
                                               ci::Color("black"), ci::Font("Arial", 60));
//                }
                ci::gl::drawStrokedRect(pixel_bounding_box);
            }
        }
    }

    void Game::update() {
        AppBase::update();
    }
}

