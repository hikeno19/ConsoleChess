#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Board;

enum PieceType {
	B = 'B',
	K = 'K',
	N = 'N',
	P = 'P',
	Q = 'Q',
	R = 'R',
	E = '#'
};

class Piece
{
	public:
		//Constructors
		Piece();
		Piece(bool color, int value);
		// Virtual Destructor for Polymorphism
		virtual ~Piece() = default;
		//Getters
		bool GetColor() const;
		int GetValue() const;
		PieceType GetType() const;
		string GetName() const;
		//Setters
		void SetColor(bool color);
		void SetValue(int value);
		void SetType(PieceType type);
		virtual string ToString();
		string HighlightToString();
		virtual void SetPossibleMoves(Board* board, int file, int rank);
		virtual vector<string> GetPossibleMoves();

		virtual Piece* clone() const;

		vector<string> possibleMoves;
	private:
		// variables 
		bool color;
		int value;
		PieceType type;
};

#endif