#include <iostream>
#include "TicTacToe.h"

using namespace std;

void TicTacToe::OnBoard()
{
	player = 2;
	
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			Board[i][j] = 0;
		}
	}
	GetInput();
}

void TicTacToe::GetInput()
{
	if (RepeatFlag == false)
		player = turn(player);
	else
		RepeatFlag = false;
		
	
	cout << "Row :";
	cin >> row;
	row--;
	cout << "Column :";
	cin >> column;
	column--;
	
	if (Board[row][column] == NULL) {
			count++;
			if (player == 1)
				Board[row][column] = 'x';
			else if (player == 2)
				Board[row][column] = 'o';
	}
	else {
			cout << "Input is overwritten or invalid, not allowed !!" << endl << "Please input your choice again:" ;
			RepeatFlag = true;
			GetInput();
	}
	BoardPrint(Board);
	
	
}


int TicTacToe::turn(int player)
{
	switch (player)
	{
	case 1: player = 2;
	{
				cout << "\nPlayer 2 turn.\n\n";
				break;
	}
	case 2: player = 1;
	{
				cout << "\nPlayer 1 turn.\n\n";
				break;
	}
	}
	return player;
}

void TicTacToe::BoardPrint(char x[3][3])
{
	cout << "      |     |     \n";
	cout << "   " << x[0][0] << "  |  " << x[0][1] << "  |  " << x[0][2] << "  \n";
	cout << " _____|_____|_____\n";
	cout << "      |     |     \n";
	cout << "   " << x[1][0] << "  |  " << x[1][1] << "  |  " << x[1][2] << "  \n";
	cout << " _____|_____|_____\n";
	cout << "      |     |     \n";
	cout << "   " << x[2][0] << "  |  " << x[2][1] << "  | " << x[2][2] << "  \n";
	cout << "      |     |     \n";
	Winner();
		     
	
}

int TicTacToe::Winner()
{
	char ans = NULL;
	
	if (Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2])
		ans = Board[0][0];
	else if (Board[2][0] == Board[1][1] && Board[2][0] == Board[0][2])
		ans = Board[2][0];
	else if (Board[0][0] == Board[0][1] && Board[0][0] == Board[0][2])
		ans = Board[0][0];
	else if (Board[1][0] == Board[1][1] && Board[1][0] == Board[1][2])
		ans = Board[1][0];
	else if (Board[2][0] == Board[2][1] && Board[2][0] == Board[2][2])
		ans = Board[2][0];
	else if (Board[0][0] == Board[1][0] && Board[0][0] == Board[2][0])
		ans = Board[0][0];
	else if (Board[0][1] == Board[1][1] && Board[0][1] == Board[2][1])
		ans = Board[0][1];
	else if (Board[0][2] == Board[1][2] && Board[0][2] == Board[2][2])
		ans = Board[0][2];

	if (ans == 'x')
	{
		return WinPlayer1;
	}
	else if(ans == 'o')
	{
		return WinPlayer2;
	}
	else if (count >= 9)
	{
		return Draw;
	}
	GetInput();
}