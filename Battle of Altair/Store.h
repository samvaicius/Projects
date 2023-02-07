//made by Sammie Vaicius
#pragma once
#ifndef STORE_H
#define STORE_H
#include <iostream>
#include "Player.h"

using namespace std;

class Store
{
private:

public:
	Weapon store(Player player, Weapon weapon);
	int getUpgradeHealth();
	int getUpgradeDamage();
	int getMoneySpent();
};



#endif // !STORE_H
