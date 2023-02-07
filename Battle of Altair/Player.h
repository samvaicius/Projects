//made by Sammie Vaicius
#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Weapon.h"
using namespace std;

class Player
{
private:
	Weapon weapon;
	//Game game;
	int money;
	string playerName;
	int playerHealth;
	int maxHealth;
public:
	Player()
	{
		playerHealth = 50;
		maxHealth = 50;
		money = 0;
	}
	Player(string inputName, int weaponNum, int inputMoney, int inputHealth)
	{

		setName(inputName);
		setWeapon(weaponNum);
		money = inputMoney;
		playerHealth = inputHealth;
	}
	Weapon getWeapon();
	void setWeapon(int x);
	int getHealth();
	int setHealth(int damage);
	void setName(string n);
	string getName();
	void addMoney(int x);
	int getMoney();
	void upgradeWeapon();
	void upgradeHealth();
	void showStats();
	void heal();
	void setMaxHealth(int x);

};



#endif // !PLAYER_H
