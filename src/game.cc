#include <board.h>
#include "game.h"

namespace chess {

    using glm::vec2;

    Game::Game() {
        ci::app::setWindowSize(750, 750);
        game_board_.SetBoard();
    }

    void Game::draw() {
        for (size_t row = 0; row < 8; ++row) {
            for (size_t col = 0; col < 8; ++col) {

                if ((row + col) % 2 == 0) {
                    ci::gl::color(ci::Color("white"));
                } else {
                    ci::gl::color(ci::Color("gray"));
                }


                vec2 pixel_top_left = vec2(100, 100) + vec2(col * 70,row * 70);
                vec2 pixel_bottom_right = pixel_top_left + vec2(70, 70);
                ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);
                ci::gl::drawSolidRect(pixel_bounding_box);

                ci::gl::color(ci::Color("black"));
                ci::gl::drawString((game_board_.getBoard()[row][col]->getPicture()),
                                   vec2(115 + col * 70, 110 + row * 70),
                                   ci::Color("black"),
                                   ci::Font("Arial", 60));

                ci::gl::drawStrokedRect(pixel_bounding_box);
            }
        }
    }

    void Game::update() {

    }

    void Game::mouseDown(ci::app::MouseEvent event) {
        vec2 position = event.getPos();
        position -= vec2(100,100);
        position /= 70;

        for (size_t row = 0; row < 8; ++row) {
            for (size_t col = 0; col < 8; ++col) {
                vec2 pixel_center = {col + 0.5, row + 0.5};

                if (glm::distance(position, pixel_center) <= 0.5) {
                    if (current_x == -1) {
                        current_x = row;
                        current_y = col;
                    } else {
                        //if (game_board_.getBoard()[current_x][current_y]->CheckPossibleMove(row, col, game_board_)) {
                            game_board_.getBoard()[current_x][current_y]->SetPosition(row, col);
                            game_board_.getBoard()[row][col]->SetPosition(current_x,current_y);
                            game_board_.SwitchPositions(current_x, current_y, row, col);
                            notation_.push_back(game_board_.getBoard()[row][col]->getPicture() + std::to_string(row) + std::to_string(col));
                            current_x = -1;
                            current_y = -1;
                        //}
                    }
                    for (const std::string& x: notation_) {
                        std::cout << x << " ";
                    }
//                    std::cout << row <<  " " << col << std::endl;
//                    std::cout << current_x <<  " " << current_y << std::endl << std::endl;

                }
            }
        }
    }
}

