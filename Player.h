#pragma once
class Player {
private:
	int x_;
	int y_;
	int speed_;
	int r_;
	bool isAlive_;
	int Balletx_;
	int Ballety_;
	int Balletr_;
public:
	void Initialize();
	void Update(char* keys, char* preKeys);
	void Draw();
	int GetPosX() { return x_; }
	int GetPosY() { return y_; }
	int GetR() { return r_; }
	int GetPosX2() { return Balletx_; }
	int GetPosY2() { return Ballety_; }
	int GetR2() { return Balletr_; }

};
