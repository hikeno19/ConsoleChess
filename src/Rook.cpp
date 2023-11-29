#include "Rook.h"
#include <vector>
#include <string>

// Default Constructor
Rook::Rook(){
	this->SetColor(true);
	this->SetValue(5);
	this->SetName("Rook");
}
// Constructor
Rook::Rook(bool color){
	this->SetColor(color);
	this->SetValue(5);
	this->SetName("Rook"); 
}
// Destructor
Rook::~Rook() {
}

vector<string> Rook::GetPossibleMoves(Board* board, int file, int rank)
{
	Board* testBoard = board;
	vector<string> moves;
	return moves;
}
