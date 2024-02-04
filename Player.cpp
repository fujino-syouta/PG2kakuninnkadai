#include "Player.h"
#include"Novice.h"
void Player::Initialize()
{
	x_ = 600;
	y_ = 600;
	r_ = 10;
	speed_ = 5;
	isAlive_ = true;
	Balletx_ = 0;
	Ballety_ = 0;
	Balletr_ = 5;
}

void Player::Update(char* keys, char* preKeys)
{
	Ballety_-=speed_;
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		Balletx_ = x_;
		Ballety_ = y_;
	}
	if (keys[DIK_W]) {
		y_ -= 20;
	}
	if (keys[DIK_S]) {
		y_ += 20;
	}
	if (keys[DIK_D]) {
		x_ += 20;
	}
	if (keys[DIK_A]) {
		x_ -= 20;
	}



}

void Player::Draw()
{
	Novice::DrawEllipse(x_, y_, r_, r_, 0.0f, RED, kFillModeSolid);
	Novice::DrawEllipse(Balletx_, Ballety_, Balletr_, Balletr_, 0.0f, BLACK, kFillModeSolid);

}