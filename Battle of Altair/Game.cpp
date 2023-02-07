//Made by Sammie Vaicius

#include "Game.h"
#include "Player.h"
#include "Weapon.h"
#include "Display.h"
#include "Sword.h"
#include "Axe.h"
#include "Wand.h"
#include "Battle.h"
#include "Store.h"


//allows the game to be played when a new character is created
void Game::play()
{
	Player player;
	
	Display d;
	Weapon weapon;
	string name;
	Sword sword;
	Battle battle;
	Axe axe;
	Wand wand;
	Store s;
	int weaponChoice;
	int enemyNumber = 0;
	char c;
	int level = 1;
	bool winBattle;
	int weaponUpgrade;
	int healthUpgrade;

	player.setMaxHealth(50);



	d.displayIntro();

	cout << endl;
	cout << "What is your name?" << endl;
	cout << "(enter in one word with no spaces)" << endl;
	cin >> name;
	player.setName(name);
	cout << endl;
	cout << endl;
	cout << name << " arrives at planet Altair and observes his weapons" << endl;
	cout << endl;
	d.displayWeapons();
	cout << endl;
	cout << endl;
	cout << "Type in the number 1 to choose the Sword, 2 to choose the axe, or" << endl;
	cout << "3 to choose the wand" << endl;
	cin >> weaponChoice;

	while (weaponChoice != 1 && weaponChoice != 2 && weaponChoice != 3)
	{
		cout << "Try Again" << endl;
		cout << "Type in the number 1 to choose the Sword, 2 to choose the axe, or" << endl;
		cout << "3 to choose the wand" << endl;
		cin >> weaponChoice;
		cout << endl;
	}

	if (weaponChoice == 1)
	{
		d.displaySword();
		weapon = sword;
		player.setWeapon(1);
		cout << endl;
		player.upgradeHealth();
		//cout << weapon.getDamage() << "  " << weapon.getDefense() << endl;
		//cout << name << " chooses the " << weapon.getName() << endl;

	}
	else if (weaponChoice == 2)
	{
		d.displayAxe();
		weapon = axe;
		player.setWeapon(2);
		cout << endl;
		//cout << weapon.getDamage() << "  " << weapon.getDefense() << endl;
		//cout << name << " chooses the " << weapon.getName() << endl;
	}
	else
	{
		d.displayWand();
		player.setWeapon(3);
		weapon = wand;
		player.upgradeHealth();
		player.upgradeHealth();
		cout << endl;

	}

	player.heal();

	cout << name << " picks up the " << weapon.getName() << " and heads off to find the first creature to capture" << endl;
	cout << endl;
	cout << "Press any key to continue" << endl;
	cout << "From here on out, anytime there is a press c to continue, you are able to" << endl;
	cout << "press s to save the game as well" << endl;
	cin >> c;
	if (c == 's')
	{
		Player* reference = &player;
		savePlayer(reference, level, weapon.getName(), weapon.getDamage());
		cout << endl;
		cout << endl;
		cout << "SAVE SUCCESS" << endl;
	}
	else if (c == 'p')
	{
		player.showStats();
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << name << " ventures off into the unknown and finds a fairy" << endl;
	d.displayFairy();
	cout << endl;
	cout << "The fairy warns " << name << " of the dangers on Altair but he chooses not to listen" << endl;
	cout << endl;
	cout << "He instead chooses to try to capture the fairy" << endl;
	cout << endl;
	cout << "Press any key to continue" << endl;
	cin >> c;
	if (c == 's')
	{
		Player* reference = &player;
		savePlayer(reference, level, weapon.getName(), weapon.getDamage());
		cout << endl;
		cout << endl;
		cout << "SAVE SUCCESS" << endl;
	}
	else if (c == 'p')
	{
		player.showStats();
	}
	cout << endl;
	cout << endl;
	d.displayBattleSwords();
	winBattle = battle.enemyBattle(level, player);
	if (winBattle)
	{
		level++;
		cout << name << " captured the fairy and recieved 30 Zoola " << endl;
		player.addMoney(30);
		cout << "Press any key to continue" << endl;
		cin >> c;
	}
	else
	{
		d.displayLoseGame();
		cout << name << " was defeated" << endl;
		cout << endl;
		cout << "The creatures on Altair are freed" << endl;
		cout << endl;
		cout << endl;
		cout << "GAME OVER" << endl;
		exit(0);
	} 
	
	weapon = s.store(player, weapon);
	weaponUpgrade = s.getUpgradeDamage();
	healthUpgrade = s.getUpgradeHealth();
	player.addMoney(-(s.getMoneySpent()));


	for (int i = 0; i < weaponUpgrade; i++)
	{
		player.upgradeWeapon();
	//	cout << "TEST" << weapon.getDamage() << endl;
	}
	for (int k = 0; k < healthUpgrade; k++)
	{
		player.upgradeHealth();
	}

	player.heal();

	//cout << player.getMaxHealth();
	//player.setHealth(player.getMaxHealth());
	cout << endl;
	//cout << weapon.getDamage() << endl;
	//cin >> c;


	cout << "Press any key to continue" << endl;
	cout << "Reminder that can press s to save game" << endl;
	cin >> c;
	if (c == 's')
	{
		Player* reference = &player;
		savePlayer(reference, level, weapon.getName(), weapon.getDamage());
		cout << endl;
		cout << endl;
		cout << "SAVE SUCCESS" << endl;
	}
	else if (c == 'p')
	{
		player.showStats();
	}


	cout << endl;
	cout << endl;
	cout << endl;

	cout << "As " << player.getName() << " continue through the land of Altair they begin to" << endl;
	cout << "hear some rattling coming from the bushes nearby" << endl;
	cout << "Press any key to continue" << endl;
	cin >> c;
	if (c == 's')
	{
		Player* reference = &player;
		savePlayer(reference, level, weapon.getName(), weapon.getDamage());
		cout << endl;
		cout << endl;
		cout << "SAVE SUCCESS" << endl;
	}
	else if (c == 'p')
	{
		player.showStats();
	}

	cout << endl;
	cout << endl;

	d.displaySkeleton();

	cout << endl;
	cout << endl;
	cout << " A skeleton appears seeking vengence for his friend" << endl;
	cout << " He demands sacrafice but " << player.getName() << " refuses" << endl;
	cout << endl;

	cout << "Press any key to continue" << endl;
	cin >> c;
	if (c == 's')
	{
		Player* reference = &player;
		savePlayer(reference, level, weapon.getName(), weapon.getDamage());
		cout << endl;
		cout << endl;
		cout << "SAVE SUCCESS" << endl;
	}

	d.displayBattleSwords();
	winBattle = battle.enemyBattle(level, player);
	if (winBattle)
	{
		level++;
		cout << name << " captured the Skeleton and recieved 30 Zoola " << endl;
		player.addMoney(30);
		cout << "Press any key to continue" << endl;
		cin >> c;
	}
	else
	{
		d.displayLoseGame();
		cout << name << " was defeated" << endl;
		cout << endl;
		cout << "The creatures on Altair are freed" << endl;
		cout << endl;
		cout << endl;
		cout << "GAME OVER" << endl;
		exit(0);
	}

	weapon = s.store(player, weapon);
	weaponUpgrade = s.getUpgradeDamage();
	healthUpgrade = s.getUpgradeHealth();
	player.addMoney(-(s.getMoneySpent()));

	for (int i = 0; i < weaponUpgrade; i++)
	{
		player.upgradeWeapon();
		//cout << "TEST" << weapon.getDamage() << endl;
	}
	for (int k = 0; k < healthUpgrade; k++)
	{
		player.upgradeHealth();
	}

	player.heal();

	cout << "Press any key to continue" << endl;
	cin >> c;
	if (c == 's')
	{
		Player* reference = &player;
		savePlayer(reference, level, weapon.getName(), weapon.getDamage());
		cout << endl;
		cout << endl;
		cout << "SAVE SUCCESS" << endl;
	}
	else if (c == 'p')
	{
		player.showStats();
	}

	cout << endl;
	cout << endl;
	
	cout << player.getName() << " hears screaming and growling getting closer and closer" << endl;

	cout << "Press any key to continue" << endl;
	cin >> c;
	if (c == 's')
	{
		Player* reference = &player;
		savePlayer(reference, level, weapon.getName(), weapon.getDamage());
		cout << endl;
		cout << endl;
		cout << "SAVE SUCCESS" << endl;
	}
	else if (c == 'p')
	{
		player.showStats();
	}


	d.displayBearLady();


	cout << endl;
	cout << "The Bear Lady speaks a forgein language but seems to be angry about something" << endl;
	cout << "The Bear Lady and " << player.getName() << " begin to battle" << endl;

	cout << "Press any key to continue" << endl;
	cin >> c;
	if (c == 's')
	{
		Player* reference = &player;
		savePlayer(reference, level, weapon.getName(), weapon.getDamage());
		cout << endl;
		cout << endl;
		cout << "SAVE SUCCESS" << endl;
	}
	else if (c == 'p')
	{
		player.showStats();
	}

	cout << endl;
	cout << endl;

	d.displayBattleSwords();
	winBattle = battle.enemyBattle(level, player);

	if (winBattle)
	{
		level++;
		cout << name << " captured the Bear Lady and recieved 30 Zoola " << endl;
		player.addMoney(30);
		cout << "Press any key to continue" << endl;
		cin >> c;
	}
	else
	{
		d.displayLoseGame();
		cout << name << " was defeated" << endl;
		cout << endl;
		cout << "The creatures on Altair are freed" << endl;
		cout << endl;
		cout << endl;
		cout << "GAME OVER" << endl;
		exit(0);
	}

	
	weapon = s.store(player, weapon);
	weaponUpgrade = s.getUpgradeDamage();
	healthUpgrade = s.getUpgradeHealth();
	player.addMoney(-(s.getMoneySpent()));

	for (int i = 0; i < weaponUpgrade; i++)
	{
		player.upgradeWeapon();
		//cout << "TEST" << weapon.getDamage() << endl;
	}
	for (int k = 0; k < healthUpgrade; k++)
	{
		player.upgradeHealth();
	}

	player.heal();

	cout << "Press any key to continue" << endl;
	cin >> c;
	if (c == 's')
	{
		Player* reference = &player;
		savePlayer(reference, level, weapon.getName(), weapon.getDamage());
		cout << endl;
		cout << endl;
		cout << "SAVE SUCCESS" << endl;
	}
	else if (c == 'p')
	{
		player.showStats();
	}

	cout << endl;
	cout << endl;
	cout << player.getName() << " sees an odd looking bird circling over them" << endl;
	cout << " it circles lower and lower until it lands in front of " << player.getName() << endl;
	cout << "Press any key to continue" << endl;
	cin >> c;
	if (c == 's')
	{
		Player* reference = &player;
		savePlayer(reference, level, weapon.getName(), weapon.getDamage());
		cout << endl;
		cout << endl;
		cout << "SAVE SUCCESS" << endl;
	}
	else if (c == 'p')
	{
		player.showStats();
	}


	d.displayGryphon();

	cout << " The Gryphon does not speak but looks into " << player.getName() << "'s soul" << endl;

	cout << "Press any key to continue" << endl;
	cin >> c;
	if (c == 's')
	{
		Player* reference = &player;
		savePlayer(reference, level, weapon.getName(), weapon.getDamage());
		cout << endl;
		cout << endl;
		cout << "SAVE SUCCESS" << endl;
	}
	else if (c == 'p')
	{
		player.showStats();
	}

	d.displayBattleSwords();
	winBattle = battle.enemyBattle(level, player);

	if (winBattle)
	{
		level++;
		cout << name << " captured the Gryphon and recieved 30 Zoola " << endl;
		player.addMoney(30);
		cout << "Press any key to continue" << endl;
		cin >> c;
	}
	else
	{
		d.displayLoseGame();
		cout << name << " was defeated" << endl;
		cout << endl;
		cout << "The creatures on Altair are freed" << endl;
		cout << endl;
		cout << endl;
		cout << "GAME OVER" << endl;
		exit(0);
	}


	weapon = s.store(player, weapon);
	weaponUpgrade = s.getUpgradeDamage();
	healthUpgrade = s.getUpgradeHealth();
	player.addMoney(-(s.getMoneySpent()));

	for (int i = 0; i < weaponUpgrade; i++)
	{
		player.upgradeWeapon();
		//cout << "TEST" << weapon.getDamage() << endl;
	}
	for (int k = 0; k < healthUpgrade; k++)
	{
		player.upgradeHealth();
	}

	player.heal();

	cout << "Press any key to continue" << endl;
	cin >> c;
	if (c == 's')
	{
		Player* reference = &player;
		savePlayer(reference, level, weapon.getName(), weapon.getDamage());
		cout << endl;
		cout << endl;
		cout << "SAVE SUCCESS" << endl;
	}
	else if (c == 'p')
	{
		player.showStats();
	}


	cout << endl;
	cout << endl;

	cout << player.getName() << " ventures off to find the last of the creatures to capture" << endl;
	cout << endl;

	cout << "Press any key to continue" << endl;
	cin >> c;
	if (c == 's')
	{
		Player* reference = &player;
		savePlayer(reference, level, weapon.getName(), weapon.getDamage());
		cout << endl;
		cout << endl;
		cout << "SAVE SUCCESS" << endl;
	}
	else if (c == 'p')
	{
		player.showStats();
	}

	d.displayDragonWarrior();

	cout << "The Dragon Warrior tells " << player.getName() << " that he will not stand for " << endl;
	cout << "the capturing of anymore creatures on Altair." << endl;
	cout << endl;
	cout << "He explains that he will protect those who cannot protect themselves" << endl;
	cout << endl;

	cout << "Press any key to continue" << endl;
	cin >> c;
	if (c == 's')
	{
		Player* reference = &player;
		savePlayer(reference, level, weapon.getName(), weapon.getDamage());
		cout << endl;
		cout << endl;
		cout << "SAVE SUCCESS" << endl;
	}
	else if (c == 'p')
	{
		player.showStats();
	}

	cout << endl;


	cout << player.getName() << " considers what he is saying and remembers the scared looks of the creatures " << endl;
	cout << "that were captured" << endl;

	cout << endl;
	cout << player.getName() << " tells the warrior that he is protecting the Alien people as well by" << endl;
	cout << "removing the chance of a threat" << endl;

	cout << endl;
	cout << "They begin to engage in battle" << endl;

	cout << endl;
	cout << "Press any key to continue" << endl;
	cin >> c;
	if (c == 's')
	{
		Player* reference = &player;
		savePlayer(reference, level, weapon.getName(), weapon.getDamage());
		cout << endl;
		cout << endl;
		cout << "SAVE SUCCESS" << endl;
	}
	else if (c == 'p')
	{
		player.showStats();
	}


	d.displayBattleSwords();
	winBattle = battle.enemyBattle(level, player);

	if (winBattle)
	{
		level++;
		cout << name << " captured the Dragon Warrior and recieved 30 Zoola " << endl;
		player.addMoney(30);
		cout << "Press any key to continue" << endl;
		cin >> c;
	}
	else
	{
		d.displayLoseGame();
		cout << name << " was defeated" << endl;
		cout << endl;
		cout << "The creatures on Altair are freed" << endl;
		cout << endl;
		cout << endl;
		cout << "GAME OVER" << endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "WIN GAME" << endl;





	//cout << "Test Lose" << endl;
	//d.displayLoseGame();
	//cout << name << " was defeated " << endl;
	//cout << "The creatures on Altair are freed" << endl;
	//cout << endl;
	//cout << "GAME OVER" << endl;
}

// allows the game to be played from the loaded data
void Game::play(string name, int inputHealth, int level, string weaponName, int weaponDamage, int inputMoney)
{	

	Store s;
	Battle battle;
	Display d;
	Weapon weapon;
	Axe axe;
	Sword sword;
	Wand wand;

	

	cout << endl;
	cout << endl;
	cout << "WElCOME BACK" << endl;
	cout << endl;
	cout << endl;

	char c;
	bool winBattle;
	int weaponUpgrade;
	int healthUpgrade;
	int weaponNum = 0;
	

	if (weaponName == "Sword")
	{
		weaponNum = 1;
		weapon = sword;

	}
	else if (weaponName == "axe")
	{
		weaponNum = 2;
		weapon = axe;
	}
	else if (weaponName == "Wand")
	{
		weaponNum = 3;
		weapon = wand;
	}
	cout << "WEAPON NUMBER" << endl;
	cout << weaponNum << endl;

	Player player(name, weaponNum, inputMoney, inputHealth);
	player.setMaxHealth(50);

	cout << endl;
	cout << endl;

	cout << player.getName() << " Decides to continue on their journey" << endl;
	
	cout << player.getName() << " is using the " << player.getWeapon().getName() << endl;

	cout << "Press any key to continue" << endl;
	cin >> c;

	if (level == 1)
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << name << " ventures off into the unknown and finds a fairy" << endl;
		d.displayFairy();
		cout << endl;
		cout << "The fairy warns " << name << " of the dangers on Altair but he chooses not to listen" << endl;
		cout << endl;
		cout << "He instead chooses to try to capture the fairy" << endl;
		cout << endl;
		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}
		cout << endl;
		cout << endl;
		d.displayBattleSwords();
		winBattle = battle.enemyBattle(level, player);
		if (winBattle)
		{
			level++;
			cout << name << " captured the fairy and recieved 30 Zoola " << endl;
			player.addMoney(30);
			cout << "Press any key to continue" << endl;
			cin >> c;
		}
		else
		{
			d.displayLoseGame();
			cout << name << " was defeated" << endl;
			cout << endl;
			cout << "The creatures on Altair are freed" << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER" << endl;
			exit(0);
		}

		weapon = s.store(player, weapon);
		weaponUpgrade = s.getUpgradeDamage();
		healthUpgrade = s.getUpgradeHealth();
		player.addMoney(-(s.getMoneySpent()));


		for (int i = 0; i < weaponUpgrade; i++)
		{
			player.upgradeWeapon();
			//	cout << "TEST" << weapon.getDamage() << endl;
		}
		for (int k = 0; k < healthUpgrade; k++)
		{
			player.upgradeHealth();
		}

		player.heal();

		//cout << player.getMaxHealth();
		//player.setHealth(player.getMaxHealth());
		cout << endl;
		//cout << weapon.getDamage() << endl;
		//cin >> c;


		cout << "Press any key to continue" << endl;
		cout << "Reminder that can press s to save game" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		cout << endl;
		cout << endl;
		cout << endl;

		cout << "As " << player.getName() << " continue through the land of Altair they begin to" << endl;
		cout << "hear some rattling coming from the bushes nearby" << endl;
		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		cout << endl;
		cout << endl;

		d.displaySkeleton();

		cout << endl;
		cout << endl;
		cout << " A skeleton appears seeking vengence for his friend" << endl;
		cout << " He demands sacrafice but " << player.getName() << " refuses" << endl;
		cout << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}

		d.displayBattleSwords();
		winBattle = battle.enemyBattle(level, player);
		if (winBattle)
		{
			level++;
			cout << name << " captured the Skeleton and recieved 30 Zoola " << endl;
			player.addMoney(30);
			cout << "Press any key to continue" << endl;
			cin >> c;
		}
		else
		{
			d.displayLoseGame();
			cout << name << " was defeated" << endl;
			cout << endl;
			cout << "The creatures on Altair are freed" << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER" << endl;
			exit(0);
		}

		weapon = s.store(player, weapon);
		weaponUpgrade = s.getUpgradeDamage();
		healthUpgrade = s.getUpgradeHealth();
		player.addMoney(-(s.getMoneySpent()));

		for (int i = 0; i < weaponUpgrade; i++)
		{
			player.upgradeWeapon();
			//cout << "TEST" << weapon.getDamage() << endl;
		}
		for (int k = 0; k < healthUpgrade; k++)
		{
			player.upgradeHealth();
		}

		player.heal();

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		cout << endl;
		cout << endl;

		cout << player.getName() << " hears screaming and growling getting closer and closer" << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		d.displayBearLady();


		cout << endl;
		cout << "The Bear Lady speaks a forgein language but seems to be angry about something" << endl;
		cout << "The Bear Lady and " << player.getName() << " begin to battle" << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		cout << endl;
		cout << endl;

		d.displayBattleSwords();
		winBattle = battle.enemyBattle(level, player);

		if (winBattle)
		{
			level++;
			cout << name << " captured the Bear Lady and recieved 30 Zoola " << endl;
			player.addMoney(30);
			cout << "Press any key to continue" << endl;
			cin >> c;
		}
		else
		{
			d.displayLoseGame();
			cout << name << " was defeated" << endl;
			cout << endl;
			cout << "The creatures on Altair are freed" << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER" << endl;
			exit(0);
		}


		weapon = s.store(player, weapon);
		weaponUpgrade = s.getUpgradeDamage();
		healthUpgrade = s.getUpgradeHealth();
		player.addMoney(-(s.getMoneySpent()));

		for (int i = 0; i < weaponUpgrade; i++)
		{
			player.upgradeWeapon();
			//cout << "TEST" << weapon.getDamage() << endl;
		}
		for (int k = 0; k < healthUpgrade; k++)
		{
			player.upgradeHealth();
		}

		player.heal();

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		cout << endl;
		cout << endl;
		cout << player.getName() << " sees an odd looking bird circling over them" << endl;
		cout << " it circles lower and lower until it lands in front of " << player.getName() << endl;
		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		d.displayGryphon();

		cout << " The Gryphon does not speak but looks into " << player.getName() << "'s soul" << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		d.displayBattleSwords();
		winBattle = battle.enemyBattle(level, player);

		if (winBattle)
		{
			level++;
			cout << name << " captured the Gryphon and recieved 30 Zoola " << endl;
			player.addMoney(30);
			cout << "Press any key to continue" << endl;
			cin >> c;
		}
		else
		{
			d.displayLoseGame();
			cout << name << " was defeated" << endl;
			cout << endl;
			cout << "The creatures on Altair are freed" << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER" << endl;
			exit(0);
		}


		weapon = s.store(player, weapon);
		weaponUpgrade = s.getUpgradeDamage();
		healthUpgrade = s.getUpgradeHealth();
		player.addMoney(-(s.getMoneySpent()));

		for (int i = 0; i < weaponUpgrade; i++)
		{
			player.upgradeWeapon();
			//cout << "TEST" << weapon.getDamage() << endl;
		}
		for (int k = 0; k < healthUpgrade; k++)
		{
			player.upgradeHealth();
		}

		player.heal();

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		cout << endl;
		cout << endl;

		cout << player.getName() << " ventures off to find the last of the creatures to capture" << endl;
		cout << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		d.displayDragonWarrior();

		cout << "The Dragon Warrior tells " << player.getName() << " that he will not stand for " << endl;
		cout << "the capturing of anymore creatures on Altair." << endl;
		cout << endl;
		cout << "He explains that he will protect those who cannot protect themselves" << endl;
		cout << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		cout << endl;


		cout << player.getName() << " considers what he is saying and remembers the scared looks of the creatures " << endl;
		cout << "that were captured" << endl;

		cout << endl;
		cout << player.getName() << " tells the warrior that he is protecting the Alien people as well by" << endl;
		cout << "removing the chance of a threat" << endl;

		cout << endl;
		cout << "They begin to engage in battle" << endl;

		cout << endl;
		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		d.displayBattleSwords();
		winBattle = battle.enemyBattle(level, player);

		if (winBattle)
		{
			level++;
			cout << name << " captured the Dragon Warrior and recieved 30 Zoola " << endl;
			player.addMoney(30);
			cout << "Press any key to continue" << endl;
			cin >> c;
		}
		else
		{
			d.displayLoseGame();
			cout << name << " was defeated" << endl;
			cout << endl;
			cout << "The creatures on Altair are freed" << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER" << endl;
		}

		cout << endl;
		cout << endl;
		cout << endl;
		cout << "WIN GAME" << endl;


	}
	else if (level == 2)
	{

		cout << endl;
		cout << endl;

		d.displaySkeleton();

		cout << endl;
		cout << endl;
		cout << " A skeleton appears seeking vengence for his friend" << endl;
		cout << " He demands sacrafice but " << player.getName() << " refuses" << endl;
		cout << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}

		d.displayBattleSwords();
		winBattle = battle.enemyBattle(level, player);
		if (winBattle)
		{
			level++;
			cout << name << " captured the Skeleton and recieved 30 Zoola " << endl;
			player.addMoney(30);
			cout << "Press any key to continue" << endl;
			cin >> c;
		}
		else
		{
			d.displayLoseGame();
			cout << name << " was defeated" << endl;
			cout << endl;
			cout << "The creatures on Altair are freed" << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER" << endl;
			exit(0);
		}

		weapon = s.store(player, weapon);
		weaponUpgrade = s.getUpgradeDamage();
		healthUpgrade = s.getUpgradeHealth();
		player.addMoney(-(s.getMoneySpent()));

		for (int i = 0; i < weaponUpgrade; i++)
		{
			player.upgradeWeapon();
			//cout << "TEST" << weapon.getDamage() << endl;
		}
		for (int k = 0; k < healthUpgrade; k++)
		{
			player.upgradeHealth();
		}

		player.heal();

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		cout << endl;
		cout << endl;

		cout << player.getName() << " hears screaming and growling getting closer and closer" << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		d.displayBearLady();


		cout << endl;
		cout << "The Bear Lady speaks a forgein language but seems to be angry about something" << endl;
		cout << "The Bear Lady and " << player.getName() << " begin to battle" << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		cout << endl;
		cout << endl;

		d.displayBattleSwords();
		winBattle = battle.enemyBattle(level, player);

		if (winBattle)
		{
			level++;
			cout << name << " captured the Bear Lady and recieved 30 Zoola " << endl;
			player.addMoney(30);
			cout << "Press any key to continue" << endl;
			cin >> c;
		}
		else
		{
			d.displayLoseGame();
			cout << name << " was defeated" << endl;
			cout << endl;
			cout << "The creatures on Altair are freed" << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER" << endl;
			exit(0);
		}


		weapon = s.store(player, weapon);
		weaponUpgrade = s.getUpgradeDamage();
		healthUpgrade = s.getUpgradeHealth();
		player.addMoney(-(s.getMoneySpent()));

		for (int i = 0; i < weaponUpgrade; i++)
		{
			player.upgradeWeapon();
			//cout << "TEST" << weapon.getDamage() << endl;
		}
		for (int k = 0; k < healthUpgrade; k++)
		{
			player.upgradeHealth();
		}

		player.heal();

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		cout << endl;
		cout << endl;
		cout << player.getName() << " sees an odd looking bird circling over them" << endl;
		cout << " it circles lower and lower until it lands in front of " << player.getName() << endl;
		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		d.displayGryphon();

		cout << " The Gryphon does not speak but looks into " << player.getName() << "'s soul" << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		d.displayBattleSwords();
		winBattle = battle.enemyBattle(level, player);

		if (winBattle)
		{
			level++;
			cout << name << " captured the Gryphon and recieved 30 Zoola " << endl;
			player.addMoney(30);
			cout << "Press any key to continue" << endl;
			cin >> c;
		}
		else
		{
			d.displayLoseGame();
			cout << name << " was defeated" << endl;
			cout << endl;
			cout << "The creatures on Altair are freed" << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER" << endl;
			exit(0);
		}


		weapon = s.store(player, weapon);
		weaponUpgrade = s.getUpgradeDamage();
		healthUpgrade = s.getUpgradeHealth();
		player.addMoney(-(s.getMoneySpent()));

		for (int i = 0; i < weaponUpgrade; i++)
		{
			player.upgradeWeapon();
			//cout << "TEST" << weapon.getDamage() << endl;
		}
		for (int k = 0; k < healthUpgrade; k++)
		{
			player.upgradeHealth();
		}

		player.heal();

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		cout << endl;
		cout << endl;

		cout << player.getName() << " ventures off to find the last of the creatures to capture" << endl;
		cout << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		d.displayDragonWarrior();

		cout << "The Dragon Warrior tells " << player.getName() << " that he will not stand for " << endl;
		cout << "the capturing of anymore creatures on Altair." << endl;
		cout << endl;
		cout << "He explains that he will protect those who cannot protect themselves" << endl;
		cout << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		cout << endl;


		cout << player.getName() << " considers what he is saying and remembers the scared looks of the creatures " << endl;
		cout << "that were captured" << endl;

		cout << endl;
		cout << player.getName() << " tells the warrior that he is protecting the Alien people as well by" << endl;
		cout << "removing the chance of a threat" << endl;

		cout << endl;
		cout << "They begin to engage in battle" << endl;

		cout << endl;
		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		d.displayBattleSwords();
		winBattle = battle.enemyBattle(level, player);

		if (winBattle)
		{
			level++;
			cout << name << " captured the Dragon Warrior and recieved 30 Zoola " << endl;
			player.addMoney(30);
			cout << "Press any key to continue" << endl;
			cin >> c;
		}
		else
		{
			d.displayLoseGame();
			cout << name << " was defeated" << endl;
			cout << endl;
			cout << "The creatures on Altair are freed" << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER" << endl;
		}

		cout << endl;
		cout << endl;
		cout << endl;
		cout << "WIN GAME" << endl;

	}
	else if (level == 3)
	{

		cout << endl;
		cout << endl;

		cout << player.getName() << " hears screaming and growling getting closer and closer" << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		d.displayBearLady();


		cout << endl;
		cout << "The Bear Lady speaks a forgein language but seems to be angry about something" << endl;
		cout << "The Bear Lady and " << player.getName() << " begin to battle" << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		cout << endl;
		cout << endl;

		d.displayBattleSwords();
		winBattle = battle.enemyBattle(level, player);

		if (winBattle)
		{
			level++;
			cout << name << " captured the Bear Lady and recieved 30 Zoola " << endl;
			player.addMoney(30);
			cout << "Press any key to continue" << endl;
			cin >> c;
		}
		else
		{
			d.displayLoseGame();
			cout << name << " was defeated" << endl;
			cout << endl;
			cout << "The creatures on Altair are freed" << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER" << endl;
			exit(0);
		}


		weapon = s.store(player, weapon);
		weaponUpgrade = s.getUpgradeDamage();
		healthUpgrade = s.getUpgradeHealth();
		player.addMoney(-(s.getMoneySpent()));

		for (int i = 0; i < weaponUpgrade; i++)
		{
			player.upgradeWeapon();
			//cout << "TEST" << weapon.getDamage() << endl;
		}
		for (int k = 0; k < healthUpgrade; k++)
		{
			player.upgradeHealth();
		}

		player.heal();

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		cout << endl;
		cout << endl;
		cout << player.getName() << " sees an odd looking bird circling over them" << endl;
		cout << " it circles lower and lower until it lands in front of " << player.getName() << endl;
		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		d.displayGryphon();

		cout << " The Gryphon does not speak but looks into " << player.getName() << "'s soul" << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		d.displayBattleSwords();
		winBattle = battle.enemyBattle(level, player);

		if (winBattle)
		{
			level++;
			cout << name << " captured the Gryphon and recieved 30 Zoola " << endl;
			player.addMoney(30);
			cout << "Press any key to continue" << endl;
			cin >> c;
		}
		else
		{
			d.displayLoseGame();
			cout << name << " was defeated" << endl;
			cout << endl;
			cout << "The creatures on Altair are freed" << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER" << endl;
			exit(0);
		}


		weapon = s.store(player, weapon);
		weaponUpgrade = s.getUpgradeDamage();
		healthUpgrade = s.getUpgradeHealth();
		player.addMoney(-(s.getMoneySpent()));

		for (int i = 0; i < weaponUpgrade; i++)
		{
			player.upgradeWeapon();
			//cout << "TEST" << weapon.getDamage() << endl;
		}
		for (int k = 0; k < healthUpgrade; k++)
		{
			player.upgradeHealth();
		}

		player.heal();

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		cout << endl;
		cout << endl;

		cout << player.getName() << " ventures off to find the last of the creatures to capture" << endl;
		cout << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		d.displayDragonWarrior();

		cout << "The Dragon Warrior tells " << player.getName() << " that he will not stand for " << endl;
		cout << "the capturing of anymore creatures on Altair." << endl;
		cout << endl;
		cout << "He explains that he will protect those who cannot protect themselves" << endl;
		cout << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		cout << endl;


		cout << player.getName() << " considers what he is saying and remembers the scared looks of the creatures " << endl;
		cout << "that were captured" << endl;

		cout << endl;
		cout << player.getName() << " tells the warrior that he is protecting the Alien people as well by" << endl;
		cout << "removing the chance of a threat" << endl;

		cout << endl;
		cout << "They begin to engage in battle" << endl;

		cout << endl;
		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		d.displayBattleSwords();
		winBattle = battle.enemyBattle(level, player);

		if (winBattle)
		{
			level++;
			cout << name << " captured the Dragon Warrior and recieved 30 Zoola " << endl;
			player.addMoney(30);
			cout << "Press any key to continue" << endl;
			cin >> c;
		}
		else
		{
			d.displayLoseGame();
			cout << name << " was defeated" << endl;
			cout << endl;
			cout << "The creatures on Altair are freed" << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER" << endl;
		}

		cout << endl;
		cout << endl;
		cout << endl;
		cout << "WIN GAME" << endl;

	}
	else if (level == 4)
	{
		cout << endl;
		cout << endl;
		cout << player.getName() << " sees an odd looking bird circling over them" << endl;
		cout << " it circles lower and lower until it lands in front of " << player.getName() << endl;
		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		d.displayGryphon();

		cout << " The Gryphon does not speak but looks into " << player.getName() << "'s soul" << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		d.displayBattleSwords();
		winBattle = battle.enemyBattle(level, player);

		if (winBattle)
		{
			level++;
			cout << name << " captured the Gryphon and recieved 30 Zoola " << endl;
			player.addMoney(30);
			cout << "Press any key to continue" << endl;
			cin >> c;
		}
		else
		{
			d.displayLoseGame();
			cout << name << " was defeated" << endl;
			cout << endl;
			cout << "The creatures on Altair are freed" << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER" << endl;
			exit(0);
		}


		weapon = s.store(player, weapon);
		weaponUpgrade = s.getUpgradeDamage();
		healthUpgrade = s.getUpgradeHealth();
		player.addMoney(-(s.getMoneySpent()));

		for (int i = 0; i < weaponUpgrade; i++)
		{
			player.upgradeWeapon();
			//cout << "TEST" << weapon.getDamage() << endl;
		}
		for (int k = 0; k < healthUpgrade; k++)
		{
			player.upgradeHealth();
		}

		player.heal();

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		cout << endl;
		cout << endl;

		cout << player.getName() << " ventures off to find the last of the creatures to capture" << endl;
		cout << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		d.displayDragonWarrior();

		cout << "The Dragon Warrior tells " << player.getName() << " that he will not stand for " << endl;
		cout << "the capturing of anymore creatures on Altair." << endl;
		cout << endl;
		cout << "He explains that he will protect those who cannot protect themselves" << endl;
		cout << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		cout << endl;


		cout << player.getName() << " considers what he is saying and remembers the scared looks of the creatures " << endl;
		cout << "that were captured" << endl;

		cout << endl;
		cout << player.getName() << " tells the warrior that he is protecting the Alien people as well by" << endl;
		cout << "removing the chance of a threat" << endl;

		cout << endl;
		cout << "They begin to engage in battle" << endl;

		cout << endl;
		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		d.displayBattleSwords();
		winBattle = battle.enemyBattle(level, player);

		if (winBattle)
		{
			level++;
			cout << name << " captured the Dragon Warrior and recieved 30 Zoola " << endl;
			player.addMoney(30);
			cout << "Press any key to continue" << endl;
			cin >> c;
		}
		else
		{
			d.displayLoseGame();
			cout << name << " was defeated" << endl;
			cout << endl;
			cout << "The creatures on Altair are freed" << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER" << endl;
		}

		cout << endl;
		cout << endl;
		cout << endl;
		cout << "WIN GAME" << endl;

	}
	else if (level == 5)
	{
		d.displayDragonWarrior();

		cout << "The Dragon Warrior tells " << player.getName() << " that he will not stand for " << endl;
		cout << "the capturing of anymore creatures on Altair." << endl;
		cout << endl;
		cout << "He explains that he will protect those who cannot protect themselves" << endl;
		cout << endl;

		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}

		cout << endl;


		cout << player.getName() << " considers what he is saying and remembers the scared looks of the creatures " << endl;
		cout << "that were captured" << endl;

		cout << endl;
		cout << player.getName() << " tells the warrior that he is protecting the Alien people as well by" << endl;
		cout << "removing the chance of a threat" << endl;

		cout << endl;
		cout << "They begin to engage in battle" << endl;

		cout << endl;
		cout << "Press any key to continue" << endl;
		cin >> c;
		if (c == 's')
		{
			Player* reference = &player;
			savePlayer(reference, level, weapon.getName(), weapon.getDamage());
			cout << endl;
			cout << endl;
			cout << "SAVE SUCCESS" << endl;
		}
		else if (c == 'p')
		{
			player.showStats();
		}


		d.displayBattleSwords();
		winBattle = battle.enemyBattle(level, player);

		if (winBattle)
		{
			level++;
			cout << name << " captured the Dragon Warrior and recieved 30 Zoola " << endl;
			player.addMoney(30);
			cout << "Press any key to continue" << endl;
			cin >> c;
		}
		else
		{
			d.displayLoseGame();
			cout << name << " was defeated" << endl;
			cout << endl;
			cout << "The creatures on Altair are freed" << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER" << endl;
		}

		cout << endl;
		cout << endl;
		cout << endl;
		cout << "WIN GAME" << endl;

	}



	
}

//loads the player data and calls upon the play function
Player* Game::loadPlayer()
{
	Player* player;
	int health;
	string name;
	int level;
	string weaponName;
	int weaponDamage;
	int money;
	ifstream fin("player.dat");
	if (!fin) {
		cout << "File error";
		exit(1);
		
	}
	fin >> name >> health >> level >> weaponName >> weaponDamage >> money;
	fin.close();
	cout << name << " " << health << " " << level << " " << weaponName << " " << weaponDamage << " " << money << endl;
	play(name,health, level, weaponName, weaponDamage, money);
}

//allows the character to be saved with important data
void Game::savePlayer(Player* player, int level,string weaponName, int weaponDamage)
{
	ofstream fout("player.dat");
	fout << player->getName() << " " << player->getHealth() << " " << level  << " " << weaponName << " " << weaponDamage << " " << player->getMoney() << endl;
	fout.close();
}
