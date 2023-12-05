#include "Bishop.h"

//Default Constructor
Bishop::Bishop() {
	this->SetColor(true);
	this->SetValue(3);
	this->SetType(PieceType::B);
}
Bishop::Bishop(bool color) {
	this->SetColor(color);
	this->SetValue(3);
	this->SetType(PieceType::B);
}
//Destructor
Bishop::~Bishop() {

}

void Bishop::SetPossibleMoves(Board* board, int file, int rank)
{
	this->possibleMoves.clear();
	//SetDiagonalMoves(board, file, rank);
	this->PrintPossibleMoves(file, rank);
}

Bishop* Bishop::clone() const {
	return new Bishop(*this);
}