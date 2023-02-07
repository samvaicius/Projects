//made by Sammie Vaicius
#pragma once
#ifndef AXE_H
#define AXE_H
#include <iostream>
#include "Weapon.h"
using namespace std;

class Axe :public Weapon
{
private:
public:
	Axe()
	{
		damage = 30;
		name = "axe";
	}
	int getDamage();
	string getName();

};


#endif // !AXE_H
