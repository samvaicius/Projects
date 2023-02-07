//made by Sammie Vaicius
#pragma once
#ifndef BEARLADY_H
#define BEARLADY_H
#include <iostream>
#include "Enemy.h"
using namespace std;

class BearLady :public Enemy
{
private:
public:
	BearLady()
	{
		health = 250;
		attack = 50;
		enemyName = "Bear Lady";
	}

};


#endif // !BEARLADY_H
