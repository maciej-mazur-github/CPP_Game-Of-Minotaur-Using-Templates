#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include "treasure_chest.h"
using namespace std;



int main()
{

	Treasure<double> dagger("Dagger", 5.5), knife("Knife", 10.1), shield("Shield", 15.15), spear("Spear", 15.0), helmet("Helmet", 20.0), boots("Boots", 12.4), sword("Sword", 28.9);

	TreasureChest<double> chest1("Box");

	chest1.encounterTreasure(&dagger);
	chest1.encounterTreasure(&knife);
	chest1.encounterTreasure(&dagger);
	chest1.encounterTreasure(&knife);
	chest1.encounterTreasure(&dagger);
	chest1.encounterTreasure(&shield);
	chest1.encounterTreasure(&spear);
	chest1.encounterTreasure(&helmet);
	chest1.encounterTreasure(&boots);
	chest1.encounterTreasure(&sword);


	cout << "\nYou have stepped on the Minotaur. You need a shield." << endl;

	if (chest1.hasItem(&shield))
	{
		cout << "\n\nYou have got the shield, you won." << endl;
	}

	else
	{
		cout << "\n\nYou do not have a shield, Minotaur just ate you." << endl;
	}

	chest1.removeTreasure("Dagger");
	//chest1.showTreasures();

}