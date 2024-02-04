#include "Enemy.h"
#include"Player.h"
#include"Novice.h"
void Enemy::Initialize()
{
	x_ = 600;
	y_ = 200;
	r_ = 16;
	speed_ = 5;
	isAlive_ = true;
	life_ = 3;
	respawnCount_ = 120;
}

void Enemy::Update()
{
	if (isAlive_ == true)
	{
		x_ += speed_;
		if (x_ <= r_ || x_ >= 1280 + r_)
		{
			speed_ *= -1;
		}
	}
	if (isAlive_==false)
	{
		respawnCount_--;
	}
	if (respawnCount_==0)
	{
		life_ -= 1;
	}

	if (respawnCount_==0)
	{
		isAlive_ = true;
		respawnCount_ = 120;
	}
}

void Enemy::Draw()
{
	if (isAlive_ == true) {
		Novice::DrawEllipse(x_, y_, r_, r_, 0.0f, RED, kFillModeSolid);
	}
}