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
    this->board->NewBoard();
	while (this->GameIsOn) {
        testBoard->SetBoard(this->board->clone());
        this->board->SetPossibleMovesAllPieces(testBoard);
        this->board->PrintBoard();
        PromptMove();
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
void GameLogic::PromptMove() {
    cout << "Current Player: " << GetCurrentPlayer() << endl;
    if (board->CheckCheckmate( testBoard, currentSide)) {
        cout << "Checkmate! " << GetOppositePlayer() << " Wins!" << endl;
        this->GameIsOn = false;
        return;
    }
    if (board->CheckCheck( testBoard, currentSide)) {
        cout << "In Check!" << endl;
    }
    string start, end;
    bool entering = true;
    int startfile = -1;
    int startrank = -1;
    int endfile = -1;
    int endrank = -1;
    vector<int> output;
    vector<string> possibleMoves;
    while (entering) {
        cout << "Enter Piece Location:" << endl;;
        cin >> start;
        if (start == "END" || start == "end") {
            entering = false;
            this->GameIsOn = false;
            return;
        }
        possibleMoves = CheckValidStartEntry(start);
        if (!possibleMoves.empty()) {
            startrank = LetterToInteger(start.at(0));
            startfile = start.at(1) - '0' - 1;
            cout << this->board->GetBoard()[startfile][startrank]->GetName() << " At " << start << " Selected." << endl << endl;
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
            this->GameIsOn = false;
            return;
        }
        if (!CheckValidEntry(end)) {
            cout << "Invalid Move Entered. Try Again!" << endl;
            continue;
        }
        else {
            endrank = LetterToInteger(end.at(0));
            endfile = end.at(1) - '0' - 1;
            string str = to_string(endfile) + to_string(endrank);
            if (CheckValidEndEntry(possibleMoves, str) && this->board->TestMove(testBoard, startfile, startrank, endfile, endrank, currentSide)) {
                output.push_back(endfile);
                output.push_back(endrank);
                if (this->board->isOccupied(endfile, endrank)) {
                    cout << GetCurrentPlayer() << " " << this->board->GetPieceAt(output[0], output[1])->GetName() << " On " << start << " Takes ";
                    cout << GetOppositePlayer() << " " << this->board->GetPieceAt(output[2], output[3])->GetName() << " On " << end << endl << endl;
                }
                else {
                    cout << GetCurrentPlayer() << " " << this->board->GetPieceAt(startfile, startrank)->GetName() << " At " << start;
                    cout << " Moved To " << end << endl;
                }
                break;  
            }
            else {
                cout << "Invalid Move Entered. Try Again!" << endl;
            }
        }
    }
    if (this->board->MakeMove(output)) {
        moveCount++;
        currentSide = !currentSide;
    }
}

bool GameLogic::CheckValidEntry(string entry) {
    if (entry.length() != 2) {
        return false;
    }
    else if (isalpha(entry.at(0)) != 0 && isdigit(entry.at(1))) {
        if ((entry.at(0) >= 'A' && entry.at(0) <= 'H') || (entry.at(0) >= 'a' && entry.at(0) <= 'h')) {
            if (entry.at(1)-'0' >= 1 && entry.at(1)-'0' <= 8) {
                return true;
            }
        }
    }
    return false;
}

// Checks If The User Entered Coordinate is Valid Start Point.
vector<string> GameLogic::CheckValidStartEntry(string start) {
    if (CheckValidEntry(start)) {
        int rank = LetterToInteger(start.at(0));
        int file = start.at(1) - '0' - 1;
        // cout << "Checking file: " << file << "   rank: " << rank << endl;
        if (this->board->isOccupied(file, rank)) {
            // cout << "  Piece:  " << this->board->GetPieceAt(file, rank)->GetName() << endl;
            if (this->board->GetColorOfPosition(file, rank) == currentSide) {
                vector<string> possibleMoves = this->board->GetPossibleMovesAt(file, rank);
                if (!possibleMoves.empty()) {
                    return possibleMoves;
                }
            }
        }
        else {
            return {};
        }
    }
    return {};
}

// Checks If the User Entered Coordinate is Valid End Point. 
bool GameLogic::CheckValidEndEntry( vector<string> moves, string coord ) {
        auto it = find(moves.begin(), moves.end(), coord);
        // cout << "Searching For Move: " << coord << endl;
        if (it != moves.end()) {
            // cout << "Found Move!" << endl;
            return true;
        }
        // cout << "Failed to Find Move!" << endl;
        return false;
}

// Convert Coordinate String to Integer Coordinates
int GameLogic::LetterToInteger(char ch) {
    int output = tolower(ch) - 'a';
    // cout << "Letter To Integer: " << ch << "   " << output << endl;
    return output;
}

string GameLogic::CoordinateIntegerToString(int file, int rank) {
    return to_string(file) + to_string(rank);
}

