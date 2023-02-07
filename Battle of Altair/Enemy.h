//made by Sammie Vaicius
#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>

using namespace std;

class Enemy
{
private:
	
public:
	string enemyName;
	int health;
	int attack;
	int getHealth();
	int loseHealth(int x);
	int getAttack();
	bool defend();
	string getEnemyName();
};



#endif // !ENEMY_H
