#include "Enemy.h"


//static ƒƒ“ƒo•Ï”‚ÍEnemy.cpp‚Å—pˆÓ‚·‚é
bool Enemy::isAllAlive = false;

Enemy::Enemy()
{
	
	isAlive = true;
	isAllAlive = true;
}

Enemy::~Enemy()
{

}

bool Enemy::IsAlive()
{
	return isAlive;
}

void Enemy::SetDeath()
{
	isAlive = false;
	isAllAlive = false;
}

void Enemy::Update()
{
	if (isAllAlive == false)
	{
		isAlive = false;
	}
}

void Enemy::Draw(int x, int y, int enemyCount)
{
	if (isAlive)
	{
		DrawBox(x * enemyCount, x* enemyCount, y*enemyCount, y* enemyCount, GetColor(255, 0, 0), true);
	}
}