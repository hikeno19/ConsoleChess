#include "Knight.h"
#include <vector>
#include <string>


//Default Constructor
Knight::Knight() {
	this->SetColor(true);
	this->SetValue(3);
	this->SetType(PieceType::N);
	this->possibleMoves = vector<string>();
}
Knight::Knight(bool color) {
	this->SetColor(color);
	this->SetValue(3);
	this->SetType(PieceType::N);
	this->possibleMoves = vector<string>();
}
//Destructor
Knight::~Knight() {

}

void Knight::SetPossibleMoves(Board* boardState, int file, int rank)
{
}

Knight* Knight::clone() const
{
	return new Knight(*this);
}
