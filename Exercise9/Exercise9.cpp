// Exercise9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Enemy.h"
#include "Player.h"

using namespace std;

int main()
{
	Player player (1);
	player.set_name ("Chen");

	cout << player.get_name () << endl;

	system ("pause");
    return 0;
}

