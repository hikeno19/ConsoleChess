#include "Queen.h"
#include <vector>
#include <string>

//Default Constructor
Queen::Queen() {
	this->SetColor(true);
	this->SetValue(9);
	this->SetType(PieceType::Q);
	this->possibleMoves = vector<string>();
}
Queen::Queen(bool color) {
	this->SetColor(color);
	this->SetValue(9);
	this->SetType(PieceType::Q);
	this->possibleMoves = vector<string>();
}
//Destructor
Queen::~Queen() {

}

void Queen::SetPossibleMoves(Board* board, int file, int rank)
{

}

// Clone
Queen* Queen::clone() const {
	return new Queen(*this);
}