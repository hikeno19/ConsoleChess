#include "Piece.h"
#include <vector>
#include <string>

class Board;

using namespace std;
 
//Default Constructor
Piece::Piece() {
	this->color = true;
	this->value = 0;
	this->name = "Piece";
}
//Constructor
Piece::Piece(bool color, int value) {
	this->color = color;
	this->value = value;
}
//Getters
bool Piece::GetColor() const{
	return this->color;
}
int Piece::GetValue() const{
	return this->value;
}
string Piece::GetName() const {
	return this->name;
}
//Setters
void Piece::SetColor(bool color) {
	this->color = color;
}
void Piece::SetValue(int value) {
	this->value = value;
}
void Piece::SetName(string name) {
	this->name = name;
}
// To String
string Piece::ToString() {
	string str = "[";
	str += (this->color) ? "\033[37m" : "\033[31m";
	str += string(1, this->name.at(0)) + "\033[0m" + "]";
	return str;
}

string Piece::HighlightToString() {
	string str = "[";
	str += "\033[33m";
	str += string(1, this->name.at(0)) + "\033[0m" + "]";
	return str;
}

vector<string> Piece::GetPossibleMoves(Board* board, int file, int rank)
{
    return vector<string>();
}
