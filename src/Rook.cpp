#include "Rook.h"
#include <vector>
#include <string>

// Default Constructor
Rook::Rook(){
	this->SetColor(true);
	this->SetValue(5);
	this->SetType(PieceType::R);
}
// Constructor
Rook::Rook(bool color){
	this->SetColor(color);
	this->SetValue(5);
	this->SetType(PieceType::R);
}
// Destructor
Rook::~Rook() {
}

void Rook::SetPossibleMoves(Board* board, int file, int rank)
{
	this->possibleMoves.clear();
	SetPerpendicularMoves(board, file, rank);
	this->PrintPossibleMoves(file, rank);
}

Rook* Rook::clone() const {
	return new Rook(*this);
}
