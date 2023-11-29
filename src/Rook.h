#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
#include <string>
#include <vector>

using namespace std;

class Rook : public Piece
{
public:
	//Constructors
	Rook();
	Rook(bool color);
	//Destructor
	~Rook();
	vector<string> GetPossibleMoves(Board* board, int file, int rank) override;
private:
};
#endif
