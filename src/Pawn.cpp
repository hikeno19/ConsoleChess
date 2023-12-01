#include "Pawn.h"
#include "Board.h"
#include <vector>
#include <string>
#include <iostream>

// Default Constructor
Pawn::Pawn() {
	this->SetColor(true);
	this->SetValue(1);
	this->SetName("Pawn");
	this->moved = false;
}
// Constructor
Pawn::Pawn(bool color) {
	this->SetColor(color);
	this->SetValue(1);
	this->SetName("Pawn");
	this->moved = false;
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
	Board* b = board;
	int increment = this->GetColor() ? 1 : -1;
	if (b->inRange(file + increment)) {
		if (!b->isOccupied(file + increment, rank)) {
			possibleMoves.push_back(to_string(file + increment) + to_string(rank));
		}
		if (b->inRange(rank+1) && b->isOccupied(file + increment, rank+1) && b->GetColorOfPosition(file+increment, rank+1) != this->GetColor()) {
			if (b->TestPawnMove(b, file, rank, file + increment, rank, this->GetColor())) {
				possibleMoves.push_back(to_string(file + increment) + to_string(rank - 1));
			}
		}
		if (b->inRange(rank-1) && b->isOccupied(file + increment, rank-1) && b->GetColorOfPosition(file + increment, rank-1) != this->GetColor()) {
			if (b->TestPawnMove(b, file, rank, file + increment, rank + 1, this->GetColor())) {
				possibleMoves.push_back(to_string(file + increment) + to_string(rank-1));
			}
		}
	}
	if (!this->GetMoved()) {
		if (b->inRange(file + (increment * 2))) {
			if (!b->isOccupied(file + (increment * 2), rank)) {
				possibleMoves.push_back(to_string(file + (increment * 2)) + to_string(rank));
			}
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
