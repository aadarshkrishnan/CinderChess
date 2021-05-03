
#include <catch2/catch.hpp>

#include <game.h>
#include <board.h>
#include <piece.h>

using chess::Game;
using chess::Board;
using chess::Piece;

TEST_CASE("Basic Movements") {

    Game game;
    //std::cout << game.get_game_board().get_board()[0][0]->get_picture();

    SECTION("Valid Moves") {
        SECTION("Black") {
            REQUIRE(1 == 1);
        }
        SECTION("White") {
            REQUIRE(1 == 1);
        }
    }
}

//TEST_CASE("Captures") {
//    SECTION("Invalid Capture") {
//        SECTION("Black") {
//
//        }
//        SECTION("White") {
//
//        }
//    }
//    SECTION("Take Pawn") {
//        SECTION("Black") {
//
//        }
//        SECTION("White") {
//
//        }
//    }
//    SECTION("Take other piece") {
//        SECTION("Black") {
//
//        }
//        SECTION("White") {
//
//        }
//    }
//}
//
//TEST_CASE("Promotion") {
//    SECTION("Black") {
//
//    }
//    SECTION("White") {
//
//    }
//}
