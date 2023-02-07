//made by Sammie Vaicius
#include "Store.h"
#include "Display.h"
#include "Player.h"
#include "Weapon.h"

int upgradeHealth = 0;
int upgradeDamage = 0;
int moneySpent = 0;


//activates the store scene as well as allows the player to upgrade weapon and health
Weapon Store::store(Player player,Weapon weapon)
{
	moneySpent = 0;
	Display d;
	int x = -1;

	

	cout << player.getName() << " calls in Drattix to update them after the battle" << endl;
	d.displayStore();

	cout << "Drattix congratulates " << player.getName() << " for their capture and offers to upgrade their weapon" << endl;
	cout << "for 10 Zoola or upgrade health for 10 Zoola" << endl;
	cout << "" << endl;
	cout << "" << endl;

	cout << player.getName() << " has " << player.getMoney() << " Zoola" << endl;

	while (x != 0)
	{
		while (x!= 0 && x != 1 && x != 2)
		{
			cout << endl;
			cout << "Press 1 to upgrade weapon, 2 to upgrade health, or 0 to exit" << endl;
			cin >> x;
		}
		if (x == 1)
		{
			if (player.getMoney() >= 10)
			{
				player.addMoney(-10);
				moneySpent += 10;
				weapon.upgradeWeapon();
				upgradeDamage++;
				cout << "Weapon Upgraded" << endl;
				cout << player.getName() << " now has " << player.getMoney() << " Zoola " << endl;
				x = -1;
			}
			else
			{
				cout << "NOT ENOUGH FUNDS" << endl;
				x = -1;
			}
		}
		else if (x == 2)
		{
			if (player.getMoney() >= 10)
			{
				player.addMoney(-10);
				moneySpent += 10;
				player.upgradeHealth();
				upgradeHealth++;
				cout << "Health Upgraded" << endl;
				cout << player.getName() << " now has " << player.getMoney() << " Zoola " << endl;
				x = -1;
			}
			else
			{
				cout << "NOT ENOUGH FUNDS" << endl;
				x = -1;
			}
		}
		else
		{

		}
	}

	cout << endl;
	cout << player.getName() << " decides that it is time to go back to capture more creatures" << endl;
	cout << endl;
	d.displayStore();
	cout << "Drattix heals " << player.getName() << endl;
	cout << "Drattix wishes " << player.getName() << " luck on their next capture and zooms away" << endl;

	return weapon;
}


//returns the integer for how many times health was upgraded
//was used for troubleshooting issues with data mismatch
int Store::getUpgradeHealth()
{
	return upgradeHealth;
}


//returns the integer for how many times weapon damage was upgraded
//was used for troubleshooting issues with data mismatch
int Store::getUpgradeDamage()
{
	return upgradeDamage;
}


//returns an integer of the money spent
int Store::getMoneySpent()
{
	return moneySpent;
}