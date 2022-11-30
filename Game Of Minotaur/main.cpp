#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
using namespace std;

const int limit = 5;


template <class T>
class treasure
{
	T value;
	char name[20];
public:
	treasure(const char* n, T v) : value(v) { strcpy_s(name, n); }

	friend ostream& operator<<(ostream& input, const treasure t)
	{
		cout << t.name << " of value " << t.value << " coins." << endl;
		return input;
	}
};


template <class T>
class treasure_chest
{
	treasure<T>* treasure_tab[limit];
	char description[20];
	int item_counter;
public:
	treasure_chest(const char* desc);
	void pick_or_not(treasure<T>* treasure_ptr);
	void add_treasure(treasure<T>* t);
	void remove_treasure(int which_one);
	void show_treasures();
	bool got_item_or_not(treasure<T>* treasure_ptr);
};



template <class T>
bool treasure_chest<T>::got_item_or_not(treasure<T>* treasure_ptr)
{
	for (int i = 0; i < item_counter; i++)
	{
		if (treasure_tab[i] == treasure_ptr)
			return true;
	}

	return false;
}



template <class T>
void treasure_chest<T>::show_treasures()
{
	cout << "\n\nThis is a treasure chest called \"" << description << "\":\n\n";

	for (int i = 0; i < item_counter; i++)
	{
		cout << i << ". " << *treasure_tab[i] << endl;
	}

	cout << "\n\n";
}


template <class T>
void treasure_chest<T>::pick_or_not(treasure<T>* treasure_ptr)
{
	cout << "You just encountered " << *treasure_ptr << endl
		<< "Do you want to pick it up? y/n : ";
	char c;
	cin >> c;

	if (c == 'y')
	{
		if (item_counter >= limit)
		{
			cout << "There is too many items in the chest. This is what we have now:\n\n";
			this->show_treasures();
			cout << "Which one do you want to replace: ";
			int choice;
			cin >> choice;

			remove_treasure(choice);

			cout << "\nAfter removal we have:" << endl;
			show_treasures();

		}


		add_treasure(treasure_ptr);

		cout << "\n\nNow we have:" << endl;
		show_treasures();
	}

}


template <class T>
treasure_chest<T>::treasure_chest(const char* desc)
	: item_counter(0)
{
	strcpy_s(description, desc);

	for (int i = 0; i < limit; i++) { treasure_tab[i] = NULL; }
}



template <class T>
void treasure_chest<T>::add_treasure(treasure<T>* t)
{
	treasure_tab[item_counter] = t;
	item_counter++;
}


template <class T>
void treasure_chest<T>::remove_treasure(int which_one)
{
	for (int i = which_one; i < limit - 1; i++)
	{
		treasure_tab[i] = treasure_tab[i + 1];
	}

	treasure_tab[limit - 1] = NULL;

	item_counter--;
}




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






	//cout  << "Nacisnij dowolny klawisz, aby zakonczyc dzialanie programu..." << endl;
	//_getch();
}