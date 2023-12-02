#include "King.h"
#include <vector>
#include <string>

//Default Constructor
King::King() {
	this->SetColor(true);
	this->SetValue(-1);
	this->SetType(PieceType::K);
	this->possibleMoves = vector<string>();
}
King::King(bool color) {
	this->SetColor(color);
	this->SetValue(-1);
	this->SetType(PieceType::K);
	this->possibleMoves = vector<string>();
}
//Destructor
King::~King() {

}

void King::SetPossibleMoves(Board* board, int file, int rank)
{

}

King* King::clone() const
{
	return new King(*this);
}

