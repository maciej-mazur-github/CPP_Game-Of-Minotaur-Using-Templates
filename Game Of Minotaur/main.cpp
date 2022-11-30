#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
using namespace std;



int main()
{

	Treasure<double> dagger("Dagger", 5.5), knife("Knife", 10.1), shield("Shield", 15.15);

	TreasureChest<double> chest1("Box");

	chest1.addTreasure(&dagger);
	chest1.addTreasure(&knife);
	chest1.addTreasure(&dagger);
	chest1.addTreasure(&knife);
	chest1.addTreasure(&dagger);

	chest1.encounter(&shield);


	cout << "\nYou have stepped on the Minotaur. You need a shield." << endl;

	if (chest1.hasItem(&shield))
		cout << "\n\nYou have got the shield, you won." << endl;

	else
		cout << "\n\nYou do not have a shield, Minotaur just ate you." << endl;

}