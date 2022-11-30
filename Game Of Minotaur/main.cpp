#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
using namespace std;



int main()
{

	treasure<double> dagger("Dagger", 5.5), knife("Knife", 10.1), shield("Shield", 15.15);

	treasure_chest<double> chest1("Box");

	chest1.add_treasure(&dagger);
	chest1.add_treasure(&knife);
	chest1.add_treasure(&dagger);
	chest1.add_treasure(&knife);
	chest1.add_treasure(&dagger);

	chest1.pick_or_not(&shield);


	cout << "\nYou have stepped on the Minotaur. You need a shield." << endl;

	if (chest1.got_item_or_not(&shield))
		cout << "\n\nYou have got the shield, you won." << endl;

	else
		cout << "\n\nYou do not have a shield, Minotaur just ate you." << endl;

}