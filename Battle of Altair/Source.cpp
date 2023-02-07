//Made by Sammie Vaicius
#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Weapon.h"

using namespace std;

int main()
{
	char c;
	Game g;

	cout << " WELCOME TO ATTACK OF ALTAIR " << endl;
	cout << "Press x to load a character or any other character to begin a new game" << endl;;
	cin >> c;

	if (c == 'x')
		g.loadPlayer();
	else
		g.play();
		
	//g.testing();
	
	
}