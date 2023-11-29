#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include <string>
#include <vector>


using namespace std;

class Bishop : public Piece
{
	public:
		//Constructors
		Bishop();
		Bishop(bool color);
		//Destructor
		~Bishop();
		vector<string> GetPossibleMoves(Board* board, int file, int rank) override;
	private:
};

#endif