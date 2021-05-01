#include <queen.h>
#include "board.h"
#include "game.h"

namespace chess {

    using glm::vec2;

    Game::Game() {
        ci::app::setWindowSize(750, 750);
        game_board_.SetStartingPosition();
    }

    void Game::draw() {
        for (size_t row = 0; row < 8; ++row) {
            for (size_t col = 0; col < 8; ++col) {

                if ((row + col) % 2 == 0) {
                    ci::gl::color(ci::Color("white"));
                } else {
                    ci::gl::color(ci::Color("gray"));
                }


                vec2 pixel_top_left = vec2(100, 100) + vec2(col * 70, row * 70);
                vec2 pixel_bottom_right = pixel_top_left + vec2(70, 70);
                ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);
                ci::gl::drawSolidRect(pixel_bounding_box);

                ci::gl::color(ci::Color("black"));
                ci::gl::drawString((game_board_.get_board()[row][col]->get_picture()),
                                   vec2(115 + col * 70, 110 + row * 70),
                                   ci::Color("black"),
                                   ci::Font("Arial", 60));

                ci::gl::drawStrokedRect(pixel_bounding_box);
            }
        }
    }

    void Game::mouseDown(ci::app::MouseEvent event) {

        vec2 position = event.getPos();
        position -= vec2(100, 100);
        position /= 70;

        for (size_t row = 0; row < 8; ++row) {
            for (size_t col = 0; col < 8; ++col) {
                vec2 pixel_center = {col + 0.5, row + 0.5};

                if (glm::distance(position, pixel_center) <= 0.5) {
                    if (current_x == -1) {
                        // ignore if the first click is an empty tile
                        if (game_board_.get_board()[row][col]->get_color() == 2) {
                            break;
                        }
                        // if it's the first part of a move then white must play
                        if (notation_.size() % 2 == 0 && game_board_.get_board()[row][col]->get_color() != 1) {
                            break;
                        }
                        // if it's the second part of a move then black must play
                        if (notation_.size() % 2 == 1 && game_board_.get_board()[row][col]->get_color() != 0) {
                            break;
                        }
                        current_x = row;
                        current_y = col;
                    } else {

                        if (game_board_.get_board()[current_x][current_y]->get_picture() == "♔" ||
                            game_board_.get_board()[current_x][current_y]->get_picture() == "♚") {
                            if (current_y - col == 2 || col - current_y == 2) {
                                if (CheckPreviousKingMove()) {
                                    current_x = -1;
                                    current_y = -1;
                                    break;
                                } else {
                                    HandleCastling(row, col);
                                    current_x = -1;
                                    current_y = -1;
                                    break;
                                }
                            }
                        }

                        if (game_board_.get_board()[current_x][current_y]->Move(row, col, game_board_) &&
                            game_board_.get_board()[current_x][current_y]->CheckPossibleMove(row, col,
                                                                                             game_board_) &&
                            game_board_.get_board()[current_x][current_y]->CheckSameColor(row, col, game_board_)) {
                            game_board_.get_board()[current_x][current_y]->SetPosition(row, col);
                            game_board_.get_board()[row][col]->SetPosition(current_x, current_y);
                            game_board_.SwitchPositions(current_x, current_y, row, col);

                            if (CheckPawnPromotion(row,col)) {
                                game_board_.Promote(row, col);
                            }

                            notation_.push_back(game_board_.get_board()[row][col]->get_picture() + std::to_string(row) +
                                                std::to_string(col));
                            for (const std::string &x: notation_) {
                                std::cout << x << " ";
                            }
                        }
                        current_x = -1;
                        current_y = -1;
                    }
                    std::cout << std::endl;
                }
            }
        }
    }

    void Game::HandleWhiteKingSideCastle() {

        if (game_board_.get_board()[7][5]->get_color() == 2 && game_board_.get_board()[7][6]->get_color() == 2) {
            if (game_board_.get_board()[7][7]->get_picture() == "♖") {
                game_board_.get_board()[7][4]->SetPosition(7, 6);
                game_board_.get_board()[7][7]->SetPosition(7, 5);
                game_board_.SwitchPositions(7, 4, 7, 6);
                game_board_.SwitchPositions(7, 7, 7, 5);
            }
        }
    }

    void Game::HandleBlackKingSideCastle() {
        if (game_board_.get_board()[0][5]->get_color() == 2 && game_board_.get_board()[0][6]->get_color() == 2) {
            if (game_board_.get_board()[0][7]->get_picture() == "♜") {
                game_board_.get_board()[0][4]->SetPosition(0, 6);
                game_board_.get_board()[0][7]->SetPosition(0, 5);
                game_board_.SwitchPositions(0, 4, 0, 6);
                game_board_.SwitchPositions(0, 7, 0, 5);
            }
        }
    }

    void Game::HandleWhiteQueenSideCastle() {
        if (game_board_.get_board()[7][3]->get_color() == 2 && game_board_.get_board()[7][2]->get_color() == 2
            && game_board_.get_board()[7][1]->get_color() == 2) {
            if (game_board_.get_board()[7][0]->get_picture() == "♖") {
                game_board_.get_board()[7][4]->SetPosition(7, 2);
                game_board_.get_board()[7][0]->SetPosition(7, 3);
                game_board_.SwitchPositions(7, 4, 7, 2);
                game_board_.SwitchPositions(7, 0, 7, 3);
            }
        }
    }

    void Game::HandleBlackQueenSideCastle() {
        if (game_board_.get_board()[0][3]->get_color() == 2 && game_board_.get_board()[0][2]->get_color() == 2
            && game_board_.get_board()[0][1]->get_color() == 2) {
            if (game_board_.get_board()[0][0]->get_picture() == "♜") {
                game_board_.get_board()[0][4]->SetPosition(0, 2);
                game_board_.get_board()[0][0]->SetPosition(0, 3);
                game_board_.SwitchPositions(0, 4, 0, 2);
                game_board_.SwitchPositions(0, 0, 0, 3);
            }
        }

    }

    void Game::HandleCastling(int row, int col) {
        if (game_board_.get_board()[current_x][current_y]->get_picture() == "♔" && row == 7 &&
            col == 6) {
            if (CheckKingCastleIntersection(7, 0)) {
                HandleWhiteKingSideCastle();
                notation_.emplace_back("♔0-0");
            }
        } else if (game_board_.get_board()[current_x][current_y]->get_picture() == "♚" && row == 0 &&
                   col == 6) {
            if (CheckKingCastleIntersection(0, 1)) {
                HandleBlackKingSideCastle();
                notation_.emplace_back("♚0-0");
            }
        } else if (game_board_.get_board()[current_x][current_y]->get_picture() == "♔" && row == 7 &&
                   col == 2) {
            if (CheckQueenCastleIntersection(7, 0)) {
                HandleWhiteQueenSideCastle();
                notation_.emplace_back("♔0-0");
            }
        } else if (game_board_.get_board()[current_x][current_y]->get_picture() == "♚" && row == 0 &&
                   col == 2) {
            if (CheckQueenCastleIntersection(0, 1)) {
                HandleBlackQueenSideCastle();
                notation_.emplace_back("♚0-0");
            }
        }
    }

    bool Game::CheckPreviousKingMove() {
        if (notation_.size() % 2 == 0) {
            for (const std::string &move: notation_) {
                if (move.find("♔") < move.length()) {
                    return true;
                }
            }
        }

        if (notation_.size() % 1 == 0) {
            for (const std::string &move: notation_) {
                if (move.find("♚") < move.length()) {
                    return true;
                }
            }
        }
        return false;
    }

    bool Game::CheckQueenCastleIntersection(int color, int opposing_color) {
        for (size_t x = 0; x < 8; ++x) {
            for (size_t y = 0; y < 8; ++y) {
                if (game_board_.get_board()[x][y]->get_color() == opposing_color) {
                    if ((game_board_.get_board()[x][y]->Move(color, 3, game_board_) &&
                         game_board_.get_board()[x][y]->CheckPossibleMove(color, 3, game_board_)) ||
                        (game_board_.get_board()[x][y]->Move(color, 2, game_board_) &&
                         game_board_.get_board()[x][y]->CheckPossibleMove(color, 2, game_board_)) ||
                        (game_board_.get_board()[x][y]->Move(color, 1, game_board_) &&
                         game_board_.get_board()[x][y]->CheckPossibleMove(color, 1, game_board_))) {
                        return false;
                    }
                }
            }
        }
        return true;
    }


    bool Game::CheckKingCastleIntersection(int color, int opposing_color) {
        for (size_t x = 0; x < 8; ++x) {
            for (size_t y = 0; y < 8; ++y) {
                if (game_board_.get_board()[x][y]->get_color() == opposing_color) {
                    if ((game_board_.get_board()[x][y]->Move(color, 5, game_board_) &&
                         game_board_.get_board()[x][y]->CheckPossibleMove(color, 5, game_board_)) ||
                        (game_board_.get_board()[x][y]->Move(color, 6, game_board_) &&
                         game_board_.get_board()[x][y]->CheckPossibleMove(color, 6, game_board_))) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool Game::CheckPawnPromotion(int row, int col) {
        if (game_board_.get_board()[row][col]->get_picture() == "♟" ||
            game_board_.get_board()[row][col]->get_picture() == "♙") {
            if (row == 0 || row == 7) {
                return true;
            }
        }
        return false;
    }
}

