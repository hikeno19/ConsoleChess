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
}
// Constructor
Pawn::Pawn(bool color) {
	this->SetColor(color);
	this->SetValue(1);
	this->SetName("Pawn");
}
// Destructor
Pawn::~Pawn() {
}

vector<string> Pawn::GetPossibleMoves(Board* board, int file, int rank) {
	Board* b = board;
	vector<string> output;
	int increment = this->GetColor() ? 1 : -1;
	if (b->inRange(file + increment)) {
		if (!b->isOccupied(file + increment, rank)) {
			output.push_back(to_string(file + increment) + to_string(rank));
		}
		if (b->inRange(rank+1) && b->isOccupied(file + increment, rank+1) && b->GetColorOfPosition(file+increment, rank+1) != this->GetColor()) {
			if (b->TestPawnMove(b, file, rank, file + increment, rank, this->GetColor())) {
				output.push_back(to_string(file + increment) + to_string(rank - 1));
			}
		}
		if (b->inRange(rank-1) && b->isOccupied(file + increment, rank-1) && b->GetColorOfPosition(file + increment, rank-1) != this->GetColor()) {
			if (b->TestPawnMove(b, file, rank, file + increment, rank + 1, this->GetColor())) {
				output.push_back(to_string(file + increment) + to_string(rank-1));
			}
		}
	}
	cout << GetName() << " On File: " << file << "  Rank: " << rank << "  Possible Moves:" << endl;
	if (!output.empty()) {
	for (size_t i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}
	}
	cout << " End of Possible Moves." << endl << endl;
	return output;
}
