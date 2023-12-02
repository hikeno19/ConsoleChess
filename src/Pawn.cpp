#include "Pawn.h"
#include "Board.h"
#include <vector>
#include <string>
#include <iostream>

// Default Constructor
Pawn::Pawn() {
	this->SetColor(true);
	this->SetValue(1);
	this->SetType(PieceType::P);
	this->moved = false;
	this->possibleMoves = vector<string>();
}
// Constructor
Pawn::Pawn(bool color) {
	this->SetColor(color);
	this->SetValue(1);
	this->SetType(PieceType::P);
	this->moved = false;
	this->possibleMoves = vector<string>();
}
// Destructor
Pawn::~Pawn() {
}

bool Pawn::GetMoved()
{
	return this->moved;
}

void Pawn::SetMoved()
{
	this->moved = true;
}

void Pawn::SetPossibleMoves(Board* board, int file, int rank) {
	this->possibleMoves.clear();
	int increment = this->GetColor() ? 1 : -1;
	int targetFile = file + increment;

	if (board->inRange(targetFile)) {
		if (!board->isOccupied(targetFile, rank)) {
			possibleMoves.push_back(to_string(targetFile) + to_string(rank));
		}

		auto checkAndAddMove = [&](int targetRank) {
			if (board->inRange(targetRank) && board->isOccupied(targetFile, targetRank) && board->GetColorOfPosition(targetFile, targetRank) != this->GetColor()) {
				if (board->TestPawnMove(board, file, rank, targetFile, targetRank, this->GetColor())) {
					possibleMoves.push_back(to_string(targetFile) + to_string(targetRank));
				}
			}
			};

		checkAndAddMove(rank + 1);
		checkAndAddMove(rank - 1);
	}

	if (!this->GetMoved()) {
		int doubleMoveFile = file + (increment * 2);
		if (board->inRange(doubleMoveFile) && !board->isOccupied(doubleMoveFile, rank)) {
			possibleMoves.push_back(to_string(doubleMoveFile) + to_string(rank));
		}
	}
	cout << GetName() << " On File: " << file << "  Rank: " << rank << "  Possible Moves:" << endl;
	if (!possibleMoves.empty()) {
		for (size_t i = 0; i < possibleMoves.size(); i++) {
			cout << possibleMoves[i] << endl;
		}
	}
	cout << " End of Possible Moves." << endl << endl;
}

Pawn* Pawn::clone() const {
	// Create a new instance of the derived class (Pawn)
	return new Pawn(*this);
}