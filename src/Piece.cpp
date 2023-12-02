#include "Piece.h"
#include <vector>
#include <string>

class Board;

using namespace std;
 
//Default Constructor
Piece::Piece() {
	this->color = true;
	this->value = 0;
	this->type = PieceType::E;
	this->possibleMoves = vector<string>();
}
//Constructor
Piece::Piece(bool color, int value) {
	this->color = color;
	this->value = value;
	this->possibleMoves = vector<string>();
	this->type = PieceType::E;
}
//Getters
bool Piece::GetColor() const{
	return this->color;
}
int Piece::GetValue() const{
	return this->value;
}
PieceType Piece::GetType() const {
	return this->type;
}

string Piece::GetName() const {
	switch (this->type) {
		case B:
			return "Bishop";
			break;
		case K:
			return "King";
			break;
		case N:
			return "Knight";
			break;
		case R:
 			return "Rook";
			break;
		case Q:
			return "Queen";
			break;
		case P:
			return "Pawn";
			break;
		default:
			return "Piece";
			break;
	}
}

//Setters
void Piece::SetColor(bool color) {
	this->color = color;
}
void Piece::SetValue(int value) {
	this->value = value;
}
void Piece::SetType(PieceType type) {
	this->type = type;
}
// To String
string Piece::ToString() {
	string str = "[";
	str += (this->color) ? "\033[37m" : "\033[31m";
	str += string(1, GetType()) + "\033[0m" + "]";
	return str;
}

string Piece::HighlightToString() {
	string str = "[";
	str += "\033[33m";
	str += string(1, GetType()) + "\033[0m" + "]";
	return str;
}

void Piece::SetPossibleMoves(Board* board, int file, int rank)
{
	this->possibleMoves = vector<string>();
}

vector<string> Piece::GetPossibleMoves()
{
	return this->possibleMoves;
}

Piece* Piece::clone() const {
	return new Piece(*this);
}
