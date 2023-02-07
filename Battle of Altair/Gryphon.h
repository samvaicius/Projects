//made by Sammie Vaicius
#pragma once
#ifndef GRYPHON_H
#define GRYPHON_H
#include <iostream>
#include "Enemy.h"
using namespace std;

class Gryphon :public Enemy
{
private:
public:
	Gryphon()
	{
		health = 500;
		attack = 70;
		enemyName = "Gryphon";
	}

};


#endif // !SKELETON_H
