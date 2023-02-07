//made by Sammie Vaicius
#include "Enemy.h"
#include <stdlib.h>
#include <time.h>  
#include <stdio.h>

int health = 0;
int attack = 0;
string enemyName = "";


//returns enemy health
int Enemy::getHealth()
{
	return health;
}


//returns enemy attack
int Enemy::getAttack()
{
	return attack;
}

//returns bool true if enemy defends false if they do not
bool Enemy::defend()
{
	srand(time(0));
	int random = rand() % 2;
	if (random == 0)
		return true;
	else
		return false;
}

//returns an int about how much health is lost
int Enemy::loseHealth(int x)
{
	health -= x;
	return health;
}

//returns a string with enemy name
string Enemy::getEnemyName()
{
	return enemyName;
}