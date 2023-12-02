#include "Bishop.h"

//Default Constructor
Bishop::Bishop() {
	this->SetColor(true);
	this->SetValue(3);
	this->SetType(PieceType::B);
	this->possibleMoves = vector<string>();
}
Bishop::Bishop(bool color) {
	this->SetColor(color);
	this->SetValue(3);
	this->SetType(PieceType::B);
	this->possibleMoves = vector<string>();
}
//Destructor
Bishop::~Bishop() {

}

void Bishop::SetPossibleMoves(Board* board, int file, int rank)
{
}

Bishop* Bishop::clone() const {
	return new Bishop(*this);
}