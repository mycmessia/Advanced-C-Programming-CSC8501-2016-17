#pragma once
#ifndef PLAYER
#define PLAYER

#include <string>

class Player {
public:
	Player (int hps);
	~Player ();

	int get_hit_points () const;
	int get_score () const;
	void set_hit_points (int new_hit_points);
	void set_score (int new_score);

	std::string get_name () const;
	void set_name (std::string player_name);

private:
	int hit_points;
	int* score;
	std::string name;
};

#endif