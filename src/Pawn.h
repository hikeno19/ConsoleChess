#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include <string>
#include <vector>

using namespace std;

class Pawn : public Piece
{
	public:
		//Constructors
		Pawn();
		Pawn(bool color);
		//Destructor
		~Pawn();
		vector<string> GetPossibleMoves(Board* board, int file, int rank) override;
	private:
};

#endif