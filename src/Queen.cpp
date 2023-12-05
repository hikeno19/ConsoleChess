#include "Queen.h"
#include <vector>
#include <string>

//Default Constructor
Queen::Queen() {
	this->SetColor(true);
	this->SetValue(9);
	this->SetType(PieceType::Q);
}
Queen::Queen(bool color) {
	this->SetColor(color);
	this->SetValue(9);
	this->SetType(PieceType::Q);
}
//Destructor
Queen::~Queen() {

}

void Queen::SetPossibleMoves(Board* board, int file, int rank)
{
	this->possibleMoves.clear();
	SetPerpendicularMoves(board, file, rank);
	SetDiagonalMoves(board, file, rank);
	this->PrintPossibleMoves(file, rank);
}

// Clone
Queen* Queen::clone() const {
	return new Queen(*this);
}