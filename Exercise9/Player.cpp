#include "stdafx.h"
#include "Player.h"

Player::Player (int hps) : hit_points (hps), score (new int (0)) {
}

Player::~Player () {
	delete score;
}

int Player::get_hit_points () const {
	return hit_points;
}

int Player::get_score () const {
	return *score;
}

void Player::set_hit_points (int new_hit_points) {
	hit_points = new_hit_points;
}

void Player::set_score (int new_score) {
	*score = new_score;
}

void Player::set_name (std::string player_name) {
	name = player_name;
}

std::string Player::get_name () const {
	return name;
}