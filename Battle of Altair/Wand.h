//made by Sammie Vaicius
#pragma once
#ifndef WAND_H
#define WAND_H
#include <iostream>
#include "Weapon.h"
using namespace std;


class Wand :public Weapon
{
private:
public:
	Wand()
	{
		damage = 10;
		name = "Wand";
	}
	int getDamage();
	string getName();


};


#endif // !WAND_H
