#pragma once
class TicTacToe
{
public:
	void OnBoard(); // make 3*3 board & put 0 as default
	int count = 0;
	int Winner(); // 8 possible winning conditions & draw condition
	
private:
	
	enum WinOut { WinPlayer1 = 1, WinPlayer2, Draw }; // 1= Player1 won; 2= Player2 won; 3= game draws
	int player;
	char Board[3][3];
	int row, column;
	bool RepeatFlag = false;

	void GetInput(); // Get input from player1 ('x') & player2('o')
	int turn(int); // Change players' turn. 
	void BoardPrint(char x[3][3]); // Print Board each time after getting input from player
};

