#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include <string>
#include <vector>

using namespace std;

class Queen : public Piece
{
public:
	//Constructors
	Queen();
	Queen(bool color);
	//Destructor
	~Queen();
	void SetPossibleMoves(Board* board, int file, int rank) override;
private:
};

#endif