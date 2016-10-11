#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy (int hps) : hit_points (hps), score (new int (0)) {
}

Enemy::~Enemy () {
	delete score;
}

int Enemy::get_hit_points () const {
	return hit_points;
}

int Enemy::get_score () const {
	return *score;
}

void Enemy::set_hit_points (int new_hit_points) {
	hit_points = new_hit_points;
}

void Enemy::set_score (int new_score) {
	*score = new_score;
}