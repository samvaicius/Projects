//made by Sammie Vaicius
#pragma once
#ifndef DRAGONWARRIOR_H
#define DRAGONWARRIOR_H
#include <iostream>
#include "Enemy.h"
using namespace std;

class DragonWarrior :public Enemy
{
private:
public:
	DragonWarrior()
	{
		health = 1000;
		attack = 150;
		enemyName = "Dragon Warrior";
	}

};


#endif // !SKELETON_H
