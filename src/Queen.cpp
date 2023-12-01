#include "Queen.h"
#include <vector>
#include <string>

//Default Constructor
Queen::Queen() {
	this->SetColor(true);
	this->SetValue(9);
	this->SetName("Queen");
}
Queen::Queen(bool color) {
	this->SetColor(color);
	this->SetValue(9);
	this->SetName("Queen");
}
//Destructor
Queen::~Queen() {

}

void Queen::SetPossibleMoves(Board* board, int file, int rank)
{
	return vector<string>();
}
