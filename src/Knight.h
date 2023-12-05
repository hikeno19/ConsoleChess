#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include <string>
#include <vector>


using namespace std;

class Board;

class Knight : public Piece
{
	public:
		//Constructors
		Knight();
		Knight(bool color);
		//Destructor
		~Knight();
		void SetPossibleMoves(Board* board, int file, int rank);
		Knight* clone() const override;

	private:
		vector<pair<int, int>> moves; 
};

#endif