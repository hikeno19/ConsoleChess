#include "King.h"
#include "Board.h"

#include <vector>
#include <string>

class Board;

//Default Constructor
King::King() {
	this->SetColor(true);
	this->SetValue(-1);
	this->SetType(PieceType::K);
	this->SetMoveIncrements({
		{ -1, 0 },   // N
		{ -1, 1 },   // NE
		{ 0, 1 },    // E
		{ 1, 1 },    // SE
		{ 1, 0 },    // S
		{ 1, -1 },   // SW
		{ 0, -1 },   // W
		{ -1, -1 }   // NW
		}
	);
}
King::King(bool color) {
	this->SetColor(color);
	this->SetValue(-1);
	this->SetType(PieceType::K);
	this->SetMoveIncrements({
		{ -1, 0 },   // N
		{ -1, 1 },   // NE
		{ 0, 1 },    // E
		{ 1, 1 },    // SE
		{ 1, 0 },    // S
		{ 1, -1 },   // SW
		{ 0, -1 },   // W
		{ -1, -1 }   // NW
		}
	);
}
//Destructor
King::~King() {
}


void King::SetPossibleMoves(Board* board, int file, int rank)
{
	this->possibleMoves.clear();
	this->AddPossibleMove(board, file, rank);
	this->PrintPossibleMoves(file, rank);
}

King* King::clone() const
{
	return new King(*this);
}

