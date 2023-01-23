#pragma once
#include "DxLib.h"
class Enemy
{


public:
	Enemy();
	~Enemy();

	void Initialize();
	void Update();

	void Approach();
	void Shoot();
	void Leave();

	void Draw();
private:
	static void (Enemy::* phase[])();
	//“G
	int posX = 0;
	int posY = 0;
	int pRadius = 0;
	int speed = 0;
	//’e
	int bulletX = 0;
	int bulletY = 0;
	int bRadius = 0;
	int bSpeed = 0;

	//“¹‚Ì‚è
	int way = 0;
	int phase_ = 0;

	bool shootFlag = false;
};

