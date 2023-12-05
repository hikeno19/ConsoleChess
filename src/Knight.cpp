#include "Knight.h"
#include "Board.h"

#include <vector>
#include <utility>
#include <string>


//Default Constructor
Knight::Knight() {
	this->SetColor(true);
	this->SetValue(3);
	this->SetType(PieceType::N);
	this->SetMoveIncrements({
	{ -2, -1 }, { -2, 1 },
	{ -1, -2 }, { -1, 2 },
	{ 1, -2 }, { 1, 2 },
	{ 2, -1 }, { 2, 1 }
		});
}
Knight::Knight(bool color) {
	this->SetColor(color);
	this->SetValue(3);
	this->SetType(PieceType::N);
	this->SetMoveIncrements({
		{ -2, -1 }, { -2, 1 },
		{ -1, -2 }, { -1, 2 },
		{ 1, -2 }, { 1, 2 },
		{ 2, -1 }, { 2, 1 }
	});
}
//Destructor
Knight::~Knight() {

}

void Knight::SetPossibleMoves(Board* board, int file, int rank)
{
	this->possibleMoves.clear();

	this->AddPossibleMove(board, file, rank);
	this->PrintPossibleMoves(file, rank);
}

Knight* Knight::clone() const
{
	return new Knight(*this);
}
