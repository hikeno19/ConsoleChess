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
		vector<string> CheckValidStartEntry( string start);
		bool CheckValidEndEntry(vector<string> moves, string coord);
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

