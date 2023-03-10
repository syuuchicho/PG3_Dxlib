#include "Enemy.h"
Enemy::Enemy()
{
	Initialize();

}

void Enemy::Initialize()
{
	phase_ = 0;//接近フェーズ
	posX = 40;
	posY = 30;
	pRadius = 20;
	speed = 2;
	//道のり
	way = 50;
}

void (Enemy::* Enemy::phase[])() =
{
	&Enemy::Approach,	//要素番号0
	&Enemy::Shoot,		//要素番号1
	&Enemy::Leave		//要素番号2
};

void Enemy::Update()
{
	(this->*phase[phase_])();
	bulletY += bSpeed;
}

void Enemy::Approach()
{
	posY += speed;
	way -= speed;
	if (way <= 0&&shootFlag==false)
	{
		//シュート
		phase_ = 1;
		//(this->*phase[1])();
		shootFlag = true;
	}
}

void Enemy::Shoot()
{
	bulletX = posX;
	bulletY = posY;
	bRadius = 10;
	bSpeed = 5;
	
	//離脱
	//(this->*phase[2])();
	phase_ = 2;
}

void Enemy::Leave()
{
	posY -= speed;
}

void Enemy::Draw()
{
	//敵
	DrawBox(posX, posY, posX + pRadius, posY + pRadius, GetColor(255, 0, 0), true);
	//弾
	DrawBox(bulletX, bulletY, bulletX + bRadius, bulletY + bRadius, GetColor(255, 0, 0), false);

}

