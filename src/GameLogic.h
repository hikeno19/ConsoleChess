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
		void PromptMove();
		bool CheckValidEntry(string entry);
		vector<string> CheckValidStartEntry( string start);
		bool CheckValidEndEntry(vector<string> moves, string coord);
		int LetterToInteger(char ch);
		string CoordinateIntegerToString(int file, int rank);
		string GetCurrentPlayer();
		string GetOppositePlayer();

		// Board instance 
		Board* board;
		Board* testBoard;
	private:

		//variables
		bool GameIsOn;
		bool currentSide;
		string position;
		int moveCount;
};

