#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Board;

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
		string GetName() const;
		//Setters
		void SetColor(bool color);
		void SetValue(int value);
		void SetName(string name);
		virtual string ToString();
		string HighlightToString();
		virtual vector<string> GetPossibleMoves(Board* board, int file, int rank);
	private:
		// variables 
		bool color;
		int value;
		string name;
};

#endif