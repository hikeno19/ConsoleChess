#ifndef KING_H
#define KING_H
#include "Piece.h"
#include <string>
#include <vector>

using namespace std;

class King : public Piece
{
public:
	//Default Constructor
	King();
	//Constructor
	King(bool color);
	//Destructor
	~King();
	vector<string> GetPossibleMoves(Board* board, int file, int rank) override;
private:
};
#endif