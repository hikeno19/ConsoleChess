#include "Board.h"
#include <string>
#include <vector>

using namespace std;

class GameLogic
{
	public:
		GameLogic();
		~GameLogic();

		void Initiate();
		vector<int> PromptMove();
		bool CheckValidEntry(string entry);
		bool CheckValidStartEntry( string start);
		bool CheckValidEndEntry(Board* boardState, int file, int rank, string end);
		int LetterToInteger(char ch);
		string CoordinateIntegerToString(int file, int rank);
		void PrintBoard();
		string GetCurrentPlayer();
		string GetOppositePlayer();


	private:
		// Board instance 
		Board* board;
		Board* testBoard;

		//variables
		bool GameIsOn;
		bool currentSide;
		string position;
		int moveCount;
};

