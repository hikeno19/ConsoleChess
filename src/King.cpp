﻿#include "King.h"
#include <vector>
#include <string>

//Default Constructor
King::King() {
	this->SetColor(true);
	this->SetValue(-1);
	this->SetName("King");
}
King::King(bool color) {
	this->SetColor(color);
	this->SetValue(-1);
	this->SetName("King");
}
//Destructor
King::~King() {

}

vector<string> King::GetPossibleMoves(Board* board, int file, int rank)
{
	return vector<string>();
}
