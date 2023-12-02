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
		void SetPossibleMoves(Board* board, int file, int rank) override;
		Bishop* clone() const override;
	private:
};

#endif