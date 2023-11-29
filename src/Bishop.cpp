#include "Bishop.h"

//Default Constructor
Bishop::Bishop() {
	this->SetColor(true);
	this->SetValue(3);
	this->SetName("Bishop");
}
Bishop::Bishop(bool color) {
	this->SetColor(color);
	this->SetValue(3);
	this->SetName("Bishop");
}
//Destructor
Bishop::~Bishop() {

}

vector<string> Bishop::GetPossibleMoves(Board* board, int file, int rank)
{
	return vector<string>();
}
