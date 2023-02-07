//made by Sammie Vaicius
#pragma once
#ifndef SKELETON_H
#define SKELETON_H
#include <iostream>
#include "Enemy.h"
using namespace std;

class Skeleton :public Enemy
{
private:
public:
	Skeleton()
	{
		health = 100;
		attack = 20;
		enemyName = "Skeleton";
	}

};


#endif // !SKELETON_H
