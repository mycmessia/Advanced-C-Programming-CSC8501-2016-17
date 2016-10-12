#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "BattleShip.h"

using namespace std;

BattleShip::BattleShip (int hp) : HIT_POINTS (hp), score (0), try_time (0) {}
BattleShip::~BattleShip () {}

void BattleShip::cleanBoard () 
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = false;
		}
	}
}

void BattleShip::reset () {

	cleanBoard ();

	score = 0;

	cur_hp = HIT_POINTS;
}

void BattleShip::printBattleGround () 
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (!arr[i][j])
				cout << ".";
			else
				cout << "*";
		}
		cout << endl;
	}
}

void BattleShip::run ()
{
	reset ();

	srand ((unsigned int)time (nullptr));

	while (cur_hp)
	{
		cleanBoard ();

		try_time = 0;

		ranRow = rand () % ROW;
		ranCol = rand () % COL;

		while (1)
		{
			std::cout << "Input a row number and a col number: " << std::endl;
			std::cin >> guessRow >> guessCol;

			while ((guessRow >= ROW || guessRow < 0) || 
				   (guessCol >= COL || guessRow < 0) ||
					arr[guessRow][guessCol] == true)
			{
				std::cout << "Invalid input, try again!" << std::endl;
				std::cin >> guessRow >> guessCol;
			}

			if (guessCol == ranCol && guessRow == ranRow)
			{
				std::cout << "Nice shot. score increase, hit points decrease!" << std::endl;
				cur_hp--;
				score += (ROW * COL - try_time);
				break;
			}
			else 
			{
				arr[guessRow][guessCol] = true;
				std::cout << "Wrong answer try again." << std::endl;
			}

			printBattleGround ();

			try_time++;
		}

		std::cout << "Current hit points: " << cur_hp << std::endl;
	}

	std::cout << "Game over, your score is: " << score << std::endl;
}