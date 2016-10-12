// Exercise8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BattleShip.h"

void copy_name ()
{
	char first[7];
	char last[10];

	strcpy_s (first, "Yuchen");	// we need at least 7 space in arr first
	strcpy_s (last, "Mei");

	std::cout << first << " " << last << std::endl;
}

void print_fullname ()
{
	char fullname[] = "Yuchen Mei";
	for (char& c : fullname)
	{
		std::cout << c;
	}
	std::cout << std::endl;
}

void battleship ()
{
	const int ROW = 5;
	const int COL = 5;
	bool arr[ROW][COL];

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = false;
		}
	}

	int ranRow, ranCol;
	int guessRow, guessCol;

	srand ((unsigned int)time (nullptr));
	ranRow = rand () % ROW;
	ranCol = rand () % COL;

	while (1)
	{
		std::cout << "Input a row number and a col number: " << std::endl;
		std::cin >> guessRow >> guessCol;

		if (guessCol == ranCol && guessRow == ranRow)
		{
			std::cout << "Guess successfully!" << std::endl;
			break;
		}
		else if (guessCol == ranCol && guessRow != ranRow)
		{
			std::cout << "Right col and Wrong row, try again." << std::endl;
		}
		else if (guessRow == ranRow && guessCol != ranCol)
		{
			std::cout << "Right row and Wrong col, try again." << std::endl;
		}
		else
		{
			std::cout << "Wrong row and wrong col." << std::endl;
		}
	}

	std::cout << "The answer is: row " << ranRow << " col " << ranCol << std::endl;
}

int main()
{
	int arr[2][2];
	arr[0][0] = 7;
	arr[0][1] = 8;
	arr[1][0] = 9;
	arr[1][1] = 11;

	int* pa = &arr[0][0];

	std::cout << *(pa + 3) << std::endl;

	system ("pause");
    return 0;
}