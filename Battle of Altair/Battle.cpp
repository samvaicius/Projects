//made by Sammie Vaicius
#include "Battle.h"
#include "Enemy.h"
#include "Player.h"
#include "Weapon.h"
#include "Fairy.h"
#include <stdlib.h>
#include <time.h>  
#include <stdio.h>
#include "Sword.h"
#include "Display.h"
#include "Skeleton.h"
#include "BearLady.h"
#include "Gryphon.h"
#include "DragonWarrior.h"

//creates the battle scene as well as the attack and defends for player and enemy
bool Battle::enemyBattle(int x, Player player)
{
	
		
	int enemyDefend = 0;
	int playerDefend = 0;
	int turn = 0;
	int playerDamage;
	int enemyDamage;
	Enemy enemy;
	Display d;
	Fairy fairy;
	Skeleton skeleton;
	BearLady bearLady;
	Gryphon gryphon;
	DragonWarrior dragonWarrior;
	if (x == 1)
		enemy = fairy;
	else if (x == 2)
		enemy = skeleton;
	else if (x == 3)
		enemy = bearLady;
	else if (x == 4)
		enemy = gryphon;
	else if (x == 5)
		enemy = dragonWarrior;
	Weapon playerWeapon;
	if (playerFirst())
	{
		turn = 1;
	}
	else
	{
		turn = 0;
	}

	while (turn != -1)
	{
		char move = 'x';
		displayStats(enemy, player);
		if (turn == 1)
		{
			while (move != 'a' && move != 'd')
			{
				cout << "Type a to attack or d to defend" << endl;
				cout << endl;
				cin >> move;
				cout << endl;
			}
				if (move == 'a')
				{
					if (enemyDefend == 1)
					{
						d.displayDefend();
						cout << "ENEMY DEFENDED" << endl;
						enemyDefend = 0;
					}
					else
					{
						d.displayPlayerAttack();
						playerWeapon = player.getWeapon();
						playerDamage = playerWeapon.getDamage();

						enemy.loseHealth(playerDamage);
					}
					
				}
				else if (move == 'd')
				{
					playerDefend = 1;
				}
				turn = 0;
		}
		else
		{
			cout << "enemy's turn" << endl;
			if (enemy.defend())
			{
				enemyDefend = 1;
				cout << "Enemy chose to defend" << endl;
			}
			else
			{
				cout << "ENEMY chose to attack" << endl;
				if (playerDefend == 1)
				{
					cout << "PLAYER DEFENDED" << endl;
					d.displayDefend();
					playerDefend = 0;
				}
				else
				{
					d.displayEnemyAttack();
					player.setHealth(enemy.getAttack());
				}
			}
			turn = 1;
		}

		if (enemy.getHealth() <= 0)
		{
			turn = -1;
			cout << "WIN" << endl;
			d.displayBattleWin();
			return true;
		}
		if (player.getHealth() <= 0)
		{
			turn = -1;
			cout << "LOSE" << endl;
			return false;
		}
		
	}
	
}

//determines whether or not the player or enemy is first
bool Battle::playerFirst()
{
	srand(time(0));
	int random = rand() % 2;
	if (random == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//displays the stats of both the enemy and player
void Battle::displayStats(Enemy enemy, Player player)
{
	cout << enemy.getEnemyName() <<  "'s health is " << enemy.getHealth() << endl;
	cout << endl;
	cout << player.getName() << "'s health is " << player.getHealth() << endl;
	cout << endl;
}