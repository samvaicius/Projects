//made by Sammie Vaicius
#include "Player.h"
#include "Weapon.h"
#include "Axe.h"
#include "Sword.h"
#include "Wand.h"

Weapon weapon;
Sword sword;
Axe axe;
Wand wand;
int playerHealth;
string playerName;
int money = 0;
int maxHealth;

//returns player weapon
Weapon Player::getWeapon()
{
	return weapon;
}

//returns an integer of player's health
int Player::getHealth()
{
	return playerHealth;
}


//sets health by subtracting damage from health then returns an integer of updated health
int Player::setHealth(int damage)
{
	playerHealth -= damage;
	return playerHealth;
}

//sets the weapon for player
void Player::setWeapon(int x)
{
	if (x == 1)
	{
		weapon = sword;
	}
	else if (x == 2)
	{
		weapon = axe;
	}
	else
	{
		weapon = wand;
	}
}

//sets the name for player
void Player::setName(string n)
{
	playerName = n;
}

//returns the name of player as string
string Player::getName()
{
	return playerName;
}

//adds int to player's money
void Player::addMoney(int x)
{
	money += x;
}

//returns money
int Player::getMoney()
{
	return money;
}

//calls upon the weapon upgrade
void Player::upgradeWeapon()
{
	weapon.upgradeWeapon();
}

//upgrades the player's health
void Player::upgradeHealth()
{
	//cout << "Previous health was: " << maxHealth << endl;
	maxHealth += 30;
	//cout << "New health is: " << maxHealth << endl;
}

//displays the player's stats
void Player::showStats()
{
	cout << " Name: " << playerName << "  Health: " << playerHealth << " Weapon Name:" << weapon.getName() << "  Weapon Damage: " << weapon.getDamage() << endl;
}

//set's player's max health to int
void Player::setMaxHealth(int x)
{
	maxHealth = x;
}

//sets playerhealth to maxhealth
void Player::heal()
{
	playerHealth = maxHealth;
}