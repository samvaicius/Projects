//made by Sammie Vaicius
#pragma once
#ifndef FAIRY_H
#define FAIRY_H
#include <iostream>
#include "Enemy.h"
using namespace std;

class Fairy :public Enemy
{
private:
public:
	Fairy()
	{
		health = 40;
		attack = 20;
		enemyName = "Fairy";
	}

};


#endif // !FAIRY_H
