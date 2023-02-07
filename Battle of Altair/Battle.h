//made by Sammie Vaicius
#ifndef BATTLE_H
#define BATTLE_H
#include <iostream>
#include "Player.h"
#include "Enemy.h"
using namespace std;


class Battle
{
private:
public:
	bool enemyBattle(int x, Player p);
	bool playerFirst();
	void displayStats(Enemy enemy, Player player);

};


#endif // !BATTLE_H
