#pragma once
class Enemy {
private:
	int x_;
	int y_;
	int speed_;
	int r_;
	bool isAlive_;
	int life_;
	int respawnCount_;
public:
	void Initialize();
	void Update();
	void Draw();
	int GetPosX() { return x_; }
	int GetPosY() { return y_; }
	int GetR() { return r_; }
	int Getlife() { return life_; }
	void SetisAlive_(bool isAlive) { isAlive_ = isAlive; }
};
