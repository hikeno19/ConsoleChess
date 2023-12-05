#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include <memory>
#include <utility>

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
		void SetPerpendicularMoves(Board* board, int file, int rank);
		void SetDiagonalMoves(Board* board, int file, int rank);

		void SetMoveIncrements(vector<pair<int, int>> increments);

		virtual vector<string> GetPossibleMoves();

		bool TestMove(Board* board, int file, int rank, int endFile, int endRank) const;

		void AddPossibleMove(Board* board, int file, int rank);

		void PrintPossibleMoves(int file, int rank);

		virtual Piece* clone() const;

		vector<string> possibleMoves;
	private:
		// variables 
		bool color;
		int value;
		PieceType type;
		vector<pair<int, int>> increments;
};

#endif