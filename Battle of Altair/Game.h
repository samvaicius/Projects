//made by Sammie Vaicius
#pragma once
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include <fstream>
#include <iostream>
using namespace std;

class Game
{
private:
public: 
	
	void play(string name, int inputHealth, int level, string weaponName, int weaponDamage, int money);
	void play();
	void savePlayer(Player* player, int level, string weaponName, int weaponDamage);
	void testing();
	Player* loadPlayer();
};

#endif // !GAME_H


