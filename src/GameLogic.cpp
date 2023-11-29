#include "GameLogic.h"
#include "Piece.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <cctype>

using namespace std;

// Constructor
GameLogic::GameLogic() {
    this->board = new Board();
    this->testBoard = new Board();
    this->currentSide = true;
    this->moveCount = 0;
    this->GameIsOn = false;
}

// Destructor
GameLogic::~GameLogic() {
}

// Initiate New Game. Where while loop will lie. 
void GameLogic::Initiate() {
	this->GameIsOn = true;
    board->NewBoard();
    board->PrintBoard();
	while (this->GameIsOn) {
        vector<int> move = PromptMove();
        if (move.size() == 1) {
            cout << "Game Over!" << endl;
            break;
        }
        if (move.empty()) {
            cout << "Checkmate! " << GetOppositePlayer() << " Wins!" << endl;
            this->GameIsOn = false;
            break;
        }
        if (this->board->MakeMove(move)) {
            moveCount++;
            currentSide = !currentSide;
        }
	}
}

// Get Current Player
string GameLogic::GetCurrentPlayer() {
    return currentSide ? "White" : "Black";
}

string GameLogic::GetOppositePlayer() {
    return  currentSide ? "Black" : "White";
}

// Prompts User For Move
vector<int> GameLogic::PromptMove() {
    cout << "Current Player: " << GetCurrentPlayer() << endl;
    testBoard->SetBoard(this->board);
    if (board->CheckCheckmate(testBoard, currentSide)) {
        cout << "Checkmate!" << endl;
        return {};
    }
    if (board->CheckCheck(testBoard, currentSide)) {
        cout << "In Check!" << endl;
    }
    string start, end;
    bool entering = true;
    int startfile = -1;
    int startrank = -1;
    int endfile = -1;
    int endrank = -1;
    vector<int> output;
    while (entering) {
        cout << "Enter Piece Location:" << endl;;
        cin >> start;
        if (start == "END" || start == "end") {
            entering = false;
            return { -1 };
        }
        if (CheckValidStartEntry(start)) {
            startrank = LetterToInteger(start.at(0));
            startfile = start.at(1) - '0' - 1;
            cout << this->board->GetPieceNameAt(startfile, startrank) << " At " << start << " Selected." << endl << endl;
            this->board->HighlightPrintBoard(startfile, startrank);
            output.push_back(startfile);
            output.push_back(startrank);
            break;
        }
        else {
            cout << "Invalid Piece Location Entered. Try Again!" << endl;
        }
    }
    while (entering) {
        cout << "Enter Move Location:";
        cin >> end;
        if (end == "END" || end == "end") {
            entering = false;
            return { -1 };
        }
        if (CheckValidEndEntry( testBoard, startfile, startrank, end)) {
            endrank = LetterToInteger(end.at(0));
            endfile = end.at(1) - '0' - 1;
            output.push_back(endfile); 
            output.push_back(endrank);
            break;
        }
        else {
            cout << "Invalid Move Entered. Try Again!" << endl;
        }
    }
    cout << "Moved " << this->board->GetPieceAt(startfile, startrank)->GetName() << " At " << start;
    cout << " To " << end << endl;
    this->board->PrintBoard();
    return { startfile, startrank, endfile, endrank };
}

bool GameLogic::CheckValidEntry(string entry) {
    if (entry.length() != 2) {
        return false;
    }
    else if (isalpha(entry.at(0)) != 0 && isdigit(entry.at(1))) {
        if ((entry.at(0) >= 'A' && entry.at(0) <= 'H') || (entry.at(0) >= 'a' && entry.at(0) <= 'h')) {
            if (entry.at(1)-'0' >= 1 && entry.at(1)-'0' <= 7) {
                return true;
            }
        }
    }
    return false;
}

// Checks If The User Entered Coordinate is Valid Start Point.
bool GameLogic::CheckValidStartEntry(string start) {
    if (CheckValidEntry(start)) {
        int rank = LetterToInteger(start.at(0));
        int file = start.at(1) - '0' - 1;
        cout << "Checking file: " << file << "   rank: " << rank << endl;
        if (this->board->isOccupied(file, rank)) {
            cout << "  Piece:  " << this->board->GetPieceAt(file, rank)->GetName() << endl;
        }
        else {
            return false;
        }
        if (this->board->GetColorOfPosition(file, rank) == currentSide) {
            vector<string> possibleMoves = this->board->GetPossibleMovesAt( testBoard, file, rank);
            if (!possibleMoves.empty()) {
                return true;
            }
        }
    }
    return false;
}

// Checks If the User Entered Coordinate is Valid End Point. 
bool GameLogic::CheckValidEndEntry( Board* boardState, int file, int rank, string end) {
    if (CheckValidEntry(end)) {
        if (this->board->TestMove( boardState, rank, file, end.at(1) - '0' - 1, LetterToInteger(end.at(0)), this->currentSide)) {
            return true;
        }
    }
    return false;
}

// Convert Coordinate String to Integer Coordinates
int GameLogic::LetterToInteger(char ch) {
    int output = tolower(ch) - 'a';
    cout << "Letter To Integer: " << ch << "   " << output << endl;
    return output;
}

string GameLogic::CoordinateIntegerToString(int file, int rank) {
    return to_string(file) + to_string(rank);
}
// Print Board
void GameLogic::PrintBoard() {
    this->board->PrintBoard();
}
