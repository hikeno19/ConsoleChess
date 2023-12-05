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
	vector<pair<int, int>> GetMoveIncrements();
	void SetPossibleMoves(Board* board, int file, int rank) override;
	King* clone() const override;
};
#endif
