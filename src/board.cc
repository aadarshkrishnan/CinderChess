#include "space.h"
#include "board.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"

namespace chess {

    std::vector<std::vector<Piece *>> Board::get_board() const {
        return board_;
    }

    void Board::SetStartingPosition() {
        board_.resize(8);
        for (size_t i = 0; i < 8; i++) {
            board_[i].resize(8);
        }

        //white back row
        board_[7][0] = new Rook(1, 7, 0, "♖");
        board_[7][1] = new Knight(1, 7, 1, "♘");
        board_[7][2] = new Bishop(1, 7, 2, "♗");
        board_[7][3] = new Queen(1, 7, 3, "♕");
        board_[7][4] = new King(1, 7, 4, "♔");
        board_[7][5] = new Bishop(1, 7, 5, "♗");
        board_[7][6] = new Knight(1, 7, 6, "♘");
        board_[7][7] = new Rook(1, 7, 7, "♖");
        //white pawns
        for (size_t i = 0; i < 8; i++) {
            board_[6][i] = new Pawn(1, 6, i, "♙");
        }

        //black back row
        board_[0][0] = new Rook(0, 0, 0, "♜");
        board_[0][1] = new Knight(0, 0, 1, "♞");
        board_[0][2] = new Bishop(0, 0, 2, "♝");
        board_[0][3] = new Queen(0, 0, 3, "♛");
        board_[0][4] = new King(0, 0, 4, "♚");
        board_[0][5] = new Bishop(0, 0, 5, "♝");
        board_[0][6] = new Knight(0, 0, 6, "♞");
        board_[0][7] = new Rook(0, 0, 7, "♜");
        //black pawns
        for (size_t i = 0; i < 8; i++) {
            board_[1][i] = new Pawn(0, 1, i, "♟︎");
        }

        //empty space
        for (size_t i = 2; i < 6; i++) {
            for (size_t j = 0; j < 8; j++) {
                board_[i][j] = new Space(2, i, j, "");
            }
        }
    }

    Board::~Board() {
        for (size_t i = 0; i < 8; i++) {
            for (size_t j = 0; j < 8; j++) {
                delete board_[i][j];
            }
        }
    }

    void Board::SwitchPositions(int x1, int y1, int x2, int y2) {
        if (board_[x2][y2]->get_color() == 2) {
            auto temp = board_[x1][y1];
            board_[x1][y1] = board_[x2][y2];
            board_[x2][y2] = temp;
        } else if (board_[x1][y1] != board_[x2][y2]) {
            delete board_[x2][y2];
            board_[x2][y2] = board_[x1][y1];
            board_[x1][y1] = new Space(2, x1, y1, "");
        }
    }

    void Board::Promote(int row, int col) {
        if (board_[row][col]->get_color() == 0) {
            delete board_[row][col];
            board_[row][col] = new Queen(0, row, col, "♛");
        } else {
            delete board_[row][col];
            board_[row][col] = new Queen(1, row, col, "♕");
        }
    }

    void Board::BringBackPiece(int color, int row, int col, std::string image) {
        delete board_[row][col];
        if (image == "") {
            board_[row][col] = new Space(color, row, col, image);
        } else if (image == "♛" || image == "♕") {
            board_[row][col] = new Queen(color, row, col, image);
        } else if (image == "♟︎" || image == "♙") {
            board_[row][col] = new Pawn(color, row, col, image);
        } else if (image == "♜" || image == "♖") {
            board_[row][col] = new Rook(color, row, col, image);
        } else if (image == "♞" || image == "♘") {
            board_[row][col] = new Knight(color, row, col, image);
        } else if (image == "♝" || image == "♗") {
            board_[row][col] = new Bishop(color, row, col, image);
        } else if (image == "♚" || image == "♔") {
            board_[row][col] = new King(color, row, col, image);
        }

    }
}