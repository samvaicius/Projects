//made by Sammie Vaicius
#pragma once
#ifndef SWORD_H
#define SWORD_H
#include <iostream>
#include "Weapon.h"
using namespace std;

class Sword:public Weapon
{
private:
public:
	Sword()
	{
		damage = 20;
		name = "Sword";
	}
	int getDamage();
	string getName();


};


#endif // !SWORD_H
