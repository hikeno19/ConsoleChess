#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <string>
#include <vector>
#include <memory>
#include <stack>

using namespace std;

class Board
{
	public:
		// constructor
		Board();
		// virtual destructor
		virtual ~Board();

		void NewBoard();
		vector<vector<Piece*>> GetBoard() const;
		Board* GetPreviousBoard();
		void SetBoard(vector<vector<Piece*>> board);
		void SetBoard(Board* b);
		void SetPreviousBoard(Board* b);
		void SetKingPositions(string whiteKing, string blackKing);
		string GetKingPosition(bool color) const;
		vector<string> GetKingPossibleMoves(bool color);
		bool CheckCheckmate( Board* boardState, bool currentSide);
		bool CheckCheck( Board* boardState, bool currentSide);
		bool MakeMove(vector<int> move);
		vector<string> GetEnemyPossibleMoves(Board* b, bool currentSide);

		Piece* GetPieceAt(int file, int rank);

		bool isOccupied(int file, int rank);

		bool GetColorOfPosition(int file, int rank);

		bool inRange(int n);

		bool inRangeCoordinates(int x, int y);

		void SetPossibleMovesAllPieces(Board* boardState);

		bool TestMove( Board* boardState, int sfile, int srank, int efile, int erank, bool currentSide);

		vector<string> GetPossibleMovesAt( int file, int rank);

		void undoMove();

		void PrintBoard();

		void HighlightPrintBoard(int file, int rank);

		Board* clone() const;

		vector<vector<Piece*>> board;

		Board* previousBoard;

	private:
		vector<string> enemyPossibleMoves;
		string blackKingPosition;
		string whiteKingPosition;

		struct Move {
			int fromX, fromY, toX, toY;
		};

};

#endif