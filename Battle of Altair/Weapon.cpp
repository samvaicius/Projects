//made by Sammie Vaicius
#include "Weapon.h"

int damage;
string name = "none";

//returns weapon's damage
int Weapon::getDamage()
{
	return damage;
}

//returns weapon's name
string Weapon::getName()
{
	return name;
}

//upgrades weapon
void Weapon::upgradeWeapon()
{
	//cout << "Previous damage was: " << getDamage() << endl;
	int newDamage = getDamage();
	newDamage += 20;
	setDamage(newDamage);
	//cout << "New damage is: " << getDamage() << endl;
}

//sets damage equal to int
void Weapon::setDamage(int x)
{
	damage = x;
}


