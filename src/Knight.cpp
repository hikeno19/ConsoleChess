﻿#include "Knight.h"
#include <vector>
#include <string>


//Default Constructor
Knight::Knight() {
	this->SetColor(true);
	this->SetValue(3);
	this->SetName("Knight");
}
Knight::Knight(bool color) {
	this->SetColor(color);
	this->SetValue(3);
	this->SetName("Knight");
}
//Destructor
Knight::~Knight() {

}

void Knight::SetPossibleMoves(Board* boardState, int file, int rank)
{
}

string Knight::ToString()
{
		string str = "[";
		str += (this->GetColor()) ? "\033[37m" : "\033[31m";
		str += "H";
		str += "\033[0m";
		str += "]";
		return str;
}
