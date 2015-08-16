#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main(){
	char PlayAgain = NULL;
	TicTacToe game;

	cout << "Welcome to the Tic-Tac-Toe Game" << endl;

	cout << "For Player1 = 'x' and Player2 = 'o' " << endl;

	cout << "Select Row from (1 or 2 or 3) and Column from (1 or 2 or 3) one by one " << endl;

REPEAT:
	game.count = 0;
	game.OnBoard();
	switch (game.Winner())
	{
	case 1:
		cout << "Player 1 Won . Congratulations !! ";
		break;
	case 2:
		cout << "Player 2 Won . Congratulations !! ";
		break;
	case 3:
		cout << "Game Draws";
		break;
	default:
		cout << "Failed";
		break;
	}

	PLAY:
	cout << "Do you want to play it again ? Y/N :";
	cin >> PlayAgain;
	
	if (PlayAgain == 'y' || PlayAgain == 'Y')
		goto REPEAT;
	else if (PlayAgain != 'y' && PlayAgain != 'n' && PlayAgain != 'Y' && PlayAgain != 'N'){
		cout << " invalid input!   Please select Y/N only. /n";
		goto PLAY;
	}
	else 
		return 0;


}
