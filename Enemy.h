#pragma once
#include<DxLib.h>
class Enemy
{
protected:
public:
	static bool isAllAlive;
	
	Enemy();
	~Enemy();

	bool IsAlive();
	void SetDeath();
	void Update();
	void Draw(int x,int y,int enemyCount);

private:
	bool isAlive = false;

};

