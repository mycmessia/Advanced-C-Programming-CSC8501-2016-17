#pragma once
#ifndef BATTLE_SHIP
#define BATTLE_SHIP

class BattleShip {
public:
	BattleShip (int hp);
	~BattleShip ();

	static const int ROW = 5;
	static const int COL = 5;
	bool arr[ROW][COL];

	void run ();
	void printBattleGround ();
	void cleanBoard ();
	void reset ();

private:
	const int HIT_POINTS;
	int score;
	int cur_hp;
	int try_time;
	int ranRow, ranCol;
	int guessRow, guessCol;
};

#endif