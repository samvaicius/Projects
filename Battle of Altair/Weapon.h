//made by Sammie Vaicius
#pragma once
#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>

using namespace std;

class Weapon
{
private:
public:
	Weapon() {};

	
	int damage;
	string name;
	int getDamage();
	string getName();
	void upgradeWeapon();
	void setDamage(int x);

	

};


#endif // !WEAPON_H
