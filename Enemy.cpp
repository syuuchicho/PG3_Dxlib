#include "Enemy.h"
Enemy::Enemy()
{
	Initialize();

}

void Enemy::Initialize()
{
	phase_ = 0;//�ڋ߃t�F�[�Y
	posX = 40;
	posY = 30;
	pRadius = 20;
	speed = 2;
	//���̂�
	way = 50;
}

void (Enemy::* Enemy::phase[])() =
{
	&Enemy::Approach,	//�v�f�ԍ�0
	&Enemy::Shoot,		//�v�f�ԍ�1
	&Enemy::Leave		//�v�f�ԍ�2
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
		//�V���[�g
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
	
	//���E
	//(this->*phase[2])();
	phase_ = 2;
}

void Enemy::Leave()
{
	posY -= speed;
}

void Enemy::Draw()
{
	//�G
	DrawBox(posX, posY, posX + pRadius, posY + pRadius, GetColor(255, 0, 0), true);
	//�e
	DrawBox(bulletX, bulletY, bulletX + bRadius, bulletY + bRadius, GetColor(255, 0, 0), false);

}

