#include "Piece.h"

#include "Board.h"
#include <vector>
#include <string>
#include <utility>
#include <iostream>

class Board;

using namespace std;
 
//Default Constructor
Piece::Piece() {
	this->color = true;
	this->value = 0;
	this->type = PieceType::E;
    this->possibleMoves = vector<string>();
}
//Constructor
Piece::Piece(bool color, int value) {
	this->color = color;
	this->value = value;
	this->type = PieceType::E;
    this->possibleMoves = vector<string>();
}
//Getters
bool Piece::GetColor() const{
	return this->color;
}
int Piece::GetValue() const{
	return this->value;
}
PieceType Piece::GetType() const {
    if (!this->type) {
        return PieceType::E;
    }
    return this->type;
	return this->type;
}

string Piece::GetName() const {
	switch (this->type) {
		case B:
			return "Bishop";
			break;
		case K:
			return "King";
			break;
		case N:
			return "Knight";
			break;
		case R:
 			return "Rook";
			break;
		case Q:
			return "Queen";
			break;
		case P:
			return "Pawn";
			break;
		default:
			return "Piece";
			break;
	}
}

//Setters
void Piece::SetColor(bool color) {
	this->color = color;
}
void Piece::SetValue(int value) {
	this->value = value;
}
void Piece::SetType(PieceType type) {
	this->type = type;
}
// To String
string Piece::ToString() {
	string str = "[";
	str += (this->color) ? "\033[37m" : "\033[31m";
	str += string(1, GetType()) + "\033[0m" + "]";
	return str;
}

string Piece::HighlightToString() {
	string str = "[";
	str += "\033[33m";
	str += string(1, GetType()) + "\033[0m" + "]";
	return str;
}

void Piece::SetPossibleMoves(Board* board, int file, int rank)
{
}

void Piece::SetPerpendicularMoves(Board* board, int file, int rank) {
    int increment;
    // Check Up 
    increment = 1;
    while (board->inRange(file + increment)) {
        if (board->isOccupied(file + increment, rank)) {
            if (board->GetColorOfPosition(file + increment, rank) != this->GetColor()) {
                //if (TestMove(board, file, rank, file + increment, rank)){
                    this->possibleMoves.push_back(to_string(file + increment) + to_string(rank));
                    break;
                //}
                //else {
                    //break;
                //}
            }
            else {
                break;
            }
        }
        else {
            //if (TestMove(board, file, rank, file + increment, rank)) {
                this->possibleMoves.push_back(to_string(file + increment) + to_string(rank));
                increment++;
            //}
        }
    }

    // Check Left
    increment = 1;
    while (board->inRange(rank - increment)) {
        if (board->isOccupied(file, rank - increment)) {
            if (board->GetColorOfPosition(file, rank - increment) != this->GetColor()) {
                //if (TestMove(board, file, rank, file + increment, rank)) {
                    this->possibleMoves.push_back(to_string(file) + to_string(rank - increment));
                    break;
                //}
                //else {
                    //break;
                //}
            }
            else {
                break;
            }
        }
        else 
        {
            //if (TestMove(board, file, rank, file, rank - increment)) {
                this->possibleMoves.push_back(to_string(file) + to_string(rank - increment));
                increment++;
           // }
        }
    }

    // Check Left
    increment = 1;
    while (board->inRange(rank + increment)) {
        if (board->isOccupied(file, rank + increment)) {
            if (board->GetColorOfPosition(file, rank + increment) != this->GetColor()) {
                //if (TestMove(board, file, rank, file, rank + increment)) {
                    this->possibleMoves.push_back(to_string(file) + to_string(rank + increment));
                    break;
                //}
                //else {
                   //break;
                //}
            }
            else {
                break;
            }
        }
        else 
        {
            //if (TestMove(board, file, rank, file, rank + increment)) {
                this->possibleMoves.push_back(to_string(file) + to_string(rank + increment));
                increment++;
            //}
        }
    }

    // Check Down
    while (board->inRange(file - increment)) {
        if (board->isOccupied(file - increment, rank)) {
            if (board->GetColorOfPosition(file - increment, rank) != this->GetColor()) {
                //if (TestMove(board, file, rank, file - increment, rank)) {
                    this->possibleMoves.push_back(to_string(file - increment) + to_string(rank));
                    break;
                //}
                //else {
                    //break;
                //}
            }
            else {
                break;
            }
        }
        else {
            //if (TestMove(board, file, rank, file - increment, rank)) {
                this->possibleMoves.push_back(to_string(file - increment) + to_string(rank));
                increment++;
            //}
        }
    }
}

void Piece::SetDiagonalMoves(Board* board, int file, int rank) {
    int increment;
    // Check Diagonal Up-Left
    increment = 1;
    while (board->inRangeCoordinates(file - increment, rank - increment)) {
        if (board->isOccupied(file - increment, rank - increment)) {
            if (board->GetColorOfPosition(file - increment, rank - increment) != this->GetColor()) {
                //if (TestMove(board, file, rank, file - increment, rank - increment)) {
                    this->possibleMoves.push_back(to_string(file - increment) + to_string(rank - increment));
                    break;
                //}
                //else {
                    //break;
                //}
            }
            else {
                break;
            }
        }
        else {
            //if (TestMove(board, file, rank, file - increment, rank - increment)) {
            this->possibleMoves.push_back(to_string(file - increment) + to_string(rank - increment));
            increment++;
            //}
        }
    }

        // Check Diagonal Up-Right
        increment = 1;
        while (board->inRangeCoordinates(file - increment, rank + increment)) {
            if (board->isOccupied(file - increment, rank + increment)) {
                if (board->GetColorOfPosition(file - increment, rank + increment) != this->GetColor()) {
                    //if (TestMove(board, file, rank, file - increment, rank + increment)) {
                        this->possibleMoves.push_back(to_string(file - increment) + to_string(rank + increment));
                        break;
                    //}
                    //else {
                        //break;
                    //}
                }
                else {
                    break;
                }
            }
            else {
                //if (TestMove(board, file, rank, file - increment, rank + increment)) {
                    this->possibleMoves.push_back(to_string(file - increment) + to_string(rank + increment));
                    increment++;
                //}
            }
        }

        // Check Diagonal Down-Left
        increment = 1;
        while (board->inRangeCoordinates(file + increment, rank - increment)) {
            if (board->isOccupied(file + increment, rank - increment)) {
                if (board->GetColorOfPosition(file + increment, rank - increment) != this->GetColor()) {
                    //if (TestMove(board, file, rank, file + increment, rank - increment)) {
                        this->possibleMoves.push_back(to_string(file + increment) + to_string(rank - increment));
                        break;
                    //}
                    //else {
                        //break;
                   // }
                }
                else {
                    break;
                }
            }
            else {
                //if (TestMove(board, file, rank, file + increment, rank - increment)) {
                    this->possibleMoves.push_back(to_string(file + increment) + to_string(rank - increment));
                    increment++;
                //}
            }
        }

        // Check Diagonal Down-Right
        increment = 1;
        while (board->inRangeCoordinates(file + increment, rank + increment)) {
            if (board->isOccupied(file + increment, rank + increment)) {
                if (board->GetColorOfPosition(file + increment, rank + increment) != this->GetColor()) {
                    //if (TestMove(board, file, rank, file + increment, rank + increment)) {
                        this->possibleMoves.push_back(to_string(file + increment) + to_string(rank + increment));
                        break;
                    //}
                }
                else {
                    break;
                }
            }
            else {
                //if (TestMove(board, file, rank, file + increment, rank + increment)) {
                    this->possibleMoves.push_back(to_string(file + increment) + to_string(rank + increment));
                    increment++;
                //}
            }
        }
}

void Piece::SetMoveIncrements(vector<pair<int, int>> increments) {
    this->increments = increments;
}

vector<string> Piece::GetPossibleMoves()
{
	return this->possibleMoves;
}

bool Piece::TestMove(Board* board, int file, int rank, int endFile, int endRank) const{
    return board->TestMove(board, file, rank, endFile, endRank, this->GetColor());
}

void Piece::AddPossibleMove(Board* board, int file, int rank) {
    for (const auto& move : this->increments) {
        int endFile = file + move.first;
        int endRank = rank + move.second;
        if (board->inRangeCoordinates(endFile, endRank)) {
            if (board->isOccupied(endFile, endRank)) {
                if (board->GetColorOfPosition(endFile, endRank) != this->GetColor()) {
                    //if (TestMove(board, file, rank, endFile, endRank)) {
                    this->possibleMoves.push_back(to_string(endFile) + to_string(endRank));
                    //}
                }
            }
            else {
                //if (TestMove(board, file, rank, endFile, endRank)) {
                this->possibleMoves.push_back(to_string(endFile) + to_string(endRank));
                //}
            }
        }
    }
}

void Piece::PrintPossibleMoves(int file, int rank) {
    /*cout << GetName() << " On File: " << file << "  Rank: " << rank << "  Possible Moves:" << endl;
    if (!possibleMoves.empty()) {
        for (size_t i = 0; i < possibleMoves.size(); i++) {
            cout << possibleMoves[i] << endl;
        }
    }
    cout << " End of Possible Moves." << endl << endl;
    */
}

Piece* Piece::clone() const {
	return new Piece(*this);
}
