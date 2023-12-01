#include "Board.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"

using namespace std;

// constructor
Board::Board() {
    this->whiteKingPosition = "-1-1";
    this->blackKingPosition = "-1-1";
    this->board.resize(8);
    for (int i = 0; i < 8; ++i) {
        board[i].resize(8, nullptr);
    }
    this->previousBoard = nullptr;
}

// destructor
Board::~Board() {
}

void Board::NewBoard() {
    // Create a new board
    this->board.resize(8);
    for (int i = 0; i < 8; ++i) {
        board[i].resize(8, nullptr);
    }

    // Initializes White Pieces onto Board
    this->board[0][0] = new Rook(true);
    this->board[0][1] = new Knight(true);
    this->board[0][2] = new Bishop(true);
    this->board[0][3] = new Queen(true);
    this->board[0][4] = new King(true);
    this->whiteKingPosition = to_string(0) + to_string(4); /* Setting king's initial position to variables */
    this->board[0][5] = new Bishop(true);
    this->board[0][6] = new Knight(true);
    this->board[0][7] = new Rook(true);
    this->board[1][0] = new Pawn(true);
    this->board[1][1] = new Pawn(true);
    this->board[1][2] = new Pawn(true);
    this->board[1][3] = new Pawn(true);
    this->board[1][4] = new Pawn(true);
    this->board[1][5] = new Pawn(true);
    this->board[1][6] = new Pawn(true);
    this->board[1][7] = new Pawn(true);

    // Initializes Black Pieces onto Board
    this->board[7][0] = new Rook(false);
    this->board[7][1] = new Knight(false);
    this->board[7][2] = new Bishop(false);
    this->board[7][3] = new Queen(false);
    this->board[7][4] = new King(false);
    this->blackKingPosition = to_string(7) + to_string(4); /* Setting king's initial position to variables */
    this->board[7][5] = new Bishop(false);
    this->board[7][6] = new Knight(false);
    this->board[7][7] = new Rook(false);
    this->board[6][0] = new Pawn(false);
    this->board[6][1] = new Pawn(false);
    this->board[6][2] = new Pawn(false);
    this->board[6][3] = new Pawn(false);
    this->board[6][4] = new Pawn(false);
    this->board[6][5] = new Pawn(false);
    this->board[6][6] = new Pawn(false);
    this->board[6][7] = new Pawn(false);
}

// Get Board
vector<vector<Piece*>> Board::GetBoard() const{
    return this->board;
}

Board* Board::GetPreviousBoard()
{
    return this->previousBoard;
}

// Set Board
void Board::SetBoard(vector<vector<Piece*>> board) {
    this->board = board;
}

// Set Board Overload
void Board::SetBoard(Board* b) {
    this->blackKingPosition = b->GetKingPosition(false);
    this->whiteKingPosition = b->GetKingPosition(true);
    this->board = b->GetBoard();
}

// Set Previous Board
void Board::SetPreviousBoard(Board* b) {
    this->previousBoard = b;
}
void Board::SetKingPositions(string whiteKing, string blackKing)
{
    this->blackKingPosition = blackKing;
    this->whiteKingPosition = whiteKing;
}
// Get's King's position.
string Board::GetKingPosition(bool color) const
{
    return color ? whiteKingPosition : blackKingPosition;
}

// Get King's Possible Moves 
vector<string> Board::GetKingPossibleMoves(bool color) {
    return GetPiecePossibleMoves(GetKingPosition(color));
}

vector<string> Board::GetPiecePossibleMoves(string position)
{
    return vector<string>();
}

// Checks for checkmate
bool Board::CheckCheckmate(Board* boardState, bool currentSide){
    if (CheckCheck(boardState, currentSide)) {
        if (GetKingPossibleMoves(currentSide).empty()) {
            return true;
        }
    }
    return false;
}

// Checks if the current player is in check. 
bool Board::CheckCheck(Board* boardState, bool currentSide){
    for (size_t i = 0; i < 8; ++i) {
        for (size_t j = 0; j < 8; ++j) {
            if (this->board[i][j] != nullptr && this->board[i][j]->GetColor() != currentSide) {
                vector<string> moves = GetPossibleMovesAt(boardState, static_cast<int>(i), static_cast<int>(j));
                auto it = find(moves.begin(), moves.end(), GetKingPosition(currentSide));

                if (it != moves.end()) {
                    return true;  // The king is in check
                }
            }
        }
    }

    return false;  // The king is not in check after checking all pieces
}

// Make Move.
bool Board::MakeMove(vector<int> move)
{
    this->previousBoard = clone();
    delete this->board[move[2]][move[3]];
    if (this->board[move[0]][move[1]]->GetName() == "Pawn" && !dynamic_cast<Pawn*>(this->board[move[0]][move[1]])->GetMoved()) {
        dynamic_cast<Pawn*>(this->board[move[0]][move[1]])->SetMoved();
    }
    this->board[move[2]][move[3]] = this->board[move[0]][move[1]];
    this->board[move[0]][move[1]] = nullptr;
    PrintBoard();
    return true;
}

// Returns all moves that enemy pieces can move to. Enemy based on currentSide boolean. 
vector<string> Board::GetEnemyPossibleMoves(Board* b, bool currentSide){
    vector<string> output;
    size_t i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
                if (isOccupied(i, j) && GetColorOfPosition(static_cast<int>(i), static_cast<int>(j)) != currentSide) {
                    vector<string> moves = GetPossibleMovesAt( static_cast<int>(i), static_cast<int>(j));
                    output.insert(output.end(), moves.begin(), moves.end());
                }
        }
    }
    return output;
}

// Gets pointer to Piece at Position.
Piece* Board::GetPieceAt(int file, int rank)
{
    return this->board[file][rank];
}

string Board::GetPieceNameAt(int file, int rank) const
{
    this->board[file][rank]->GetName();
    return this->board[file][rank]->GetName();
}

// Checks if position is occupied, null or not.
bool Board::isOccupied(int file, int rank) {
    if (this->board[file][rank] != nullptr) {
        return true;
    }
    else {
        return false;
    }
}

// Checks the color of the piece on position.
bool Board::GetColorOfPosition(int file, int rank) {
    std::cout << "Checking Color of Position at file:" << file << "  rank:" << rank << endl;
    Piece* test = nullptr;
    if (this->board[file][rank] == nullptr) {
        std::cout << "Null" << endl;
    }
    else {
        test = this->board[file][rank];
    }
    bool color = this->board[file][rank]->GetColor();
    std::cout << "Color Of Position: " << color << endl;
    return color;
}

// Checks if the number is in range of the board.
bool Board::inRange(int n) {
    if (n >= 0 && n <= 7) {
        return true;
    }
    return false;
}

// Checks if the coordinate is in range of the board.
bool Board::inRangeCoordinates(int x, int y) {
    if (inRange(x) && inRange(y)) {
        return true;
    }
    return false;
}

// Tests Move. 
bool Board::TestMove(Board* boardState, int sfile, int srank, int efile, int erank, bool currentSide) {
       if (!isOccupied(efile, erank)) {
            boardState->MakeMove({ sfile, srank, efile, erank });
            if (!boardState->CheckCheck(boardState, currentSide)) {
                boardState->undoMove();
                return true;
            }
            else {
                boardState->undoMove();
            }
        } else if (this->GetColorOfPosition(efile, erank) != currentSide) {
           boardState->MakeMove({ sfile, srank, efile, erank });
           if (!boardState->CheckCheck(boardState, currentSide)) {
               boardState->undoMove();
               return true;
           }
           else {
               boardState->undoMove();
           }
       }
    return false;
}

// Tests Move. 
bool Board::TestPawnMove(Board* boardState, int sfile, int srank, int efile, int erank, bool currentSide) {
    if (isOccupied(efile, erank) && GetColorOfPosition(efile, erank) != currentSide) {
        boardState->MakeMove({ sfile, srank, efile, erank });
        if (!boardState->CheckCheck(boardState, currentSide)) {
            boardState->undoMove();
            return true;
        }
        else {
            boardState->undoMove();
            return false;
        }
    }
    return false;
}


// Sets all piece Possible Moves
void Board::SetPossibleMovesAllPieces(Board* boardState) {
    for (int i = 0; i < this->board.size(); i++) {
        for (int j = 0; j < this->board.size(); j++) {
            if (isOccupied(i, j)) {
                this->board[i][j]->SetPossibleMoves(boardState, i, j);
            }
        }
    }
}


// GetPossibleMovesAt(file, rank)
vector<string> Board::GetPossibleMovesAt( int file, int rank) {
    return this->board[file][rank]->GetPossibleMoves();
}

// Print Board
void Board::PrintBoard() {
    std::cout << "Board:" << endl;
    for (int i = 7; i >= 0; i--) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < 8; j++) {
            if (this->board[i][j] != nullptr) {
                std::cout << this->board[i][j]->ToString() << " ";
            }
            else {
                std::cout << "[ ]" << " ";
            }
        }
        std::cout << endl;
    }
    std::cout << "  ";
    for (char ch = 'A'; ch <= 'H'; ++ch) {
        std::cout << " " << ch << ' ' << " ";
    }
    std::cout << endl;
}

// Print Board with Highlighted Piece
void Board::HighlightPrintBoard(int file, int rank) {
    std::cout << this->board[file][rank]->GetName() << " " << "Selected" << endl;
    std::cout << "Board:" << endl;
    for (int i = 7; i >= 0; i--) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < 8; j++) {
            if (this->board[i][j] != nullptr) {
                if (i == file && j == rank) {
                    std::cout << "\033[0m" << this->board[i][j]->HighlightToString() << "\033[0m ";
                }
                else {
                    std::cout << "\033[0m" << this->board[i][j]->ToString() << "\033[0m ";
                }
            }
            else {
                std::cout << "[ ]" << " ";
            }
        }
        std::cout << endl;
    }
    std::cout << "  ";
    for (char ch = 'A'; ch <= 'H'; ++ch) {
        std::cout << " " << ch << ' ' << " ";
    }
    std::cout << endl;
}

void Board::undoMove() {
    SetBoard(this->previousBoard);
}

// Clone Function
Board* Board::clone() const{
    Board* clonedObject = new Board();
    clonedObject->SetBoard(GetBoard());
    clonedObject->SetKingPositions(this->whiteKingPosition, this->blackKingPosition);
    clonedObject->SetPreviousBoard(this->previousBoard);
    return clonedObject;
}