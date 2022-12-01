#pragma once
#include "treasure.h"



const int arraySize = 5;



template <class T>
class TreasureChest
{
	Treasure<T>* treasureArray[arraySize];
	string description;
	int itemCounter;
public:
	TreasureChest(string description)
		: itemCounter(0), description(description) {}
	void encounterTreasure(Treasure<T>* treasurePtr);
	void removeTreasure(int index);
	void removeTreasure(string name);
	void showTreasures();
	void replaceTreasure(Treasure<T>* newTreasurePtr);
	bool hasItem(Treasure<T>* treasurePtr);

private:
	int existingTreasureChoice(string& existingTreasureName);
	void replaceTreasure(int existingTreasureIndex, Treasure<T>* newTreasurePtr);
	int hasItem(string treasureName);
	void addTreasure(Treasure<T>* treasurePtr);
	bool verifyAnswer();
};




template <class T>
bool TreasureChest<T>::hasItem(Treasure<T>* treasurePtr)
{
	for (int i = 0; i < itemCounter; i++)
	{
		if ((*treasureArray[i]).getName().compare(treasurePtr->getName()) == 0)     //  if inspected Treasure name equals the compared Treasure name
			return true;
	}

	return false;
}

template <class T>
int TreasureChest<T>::hasItem(string treasureName)
{
	for (int i = 0; i < itemCounter; i++)
	{
		if ((*treasureArray[i]).getName().compare(treasureName) == 0)
		{
			return i;       // position in array at which the found treasure was found
		}
	}

	return arraySize + 1;    // some constant number from outside of available array range
}


template <class T>
bool TreasureChest<T>::verifyAnswer()
{
	char answer;
	cin >> answer;

	if (answer == 'y' || answer == 'Y')
	{
		return true;
	}
	else if (answer == 'n' || answer == 'N')
	{
		return false;
	}
	else
	{
		cout << "\nWrong letter of choice" << endl;
		return false;
	}
}

template <class T>
void TreasureChest<T>::encounterTreasure(Treasure<T>* treasurePtr)
{
	cout << "\n\nYou just encountered: " << *treasurePtr;

	if (hasItem(treasurePtr))
	{
		cout << " But you have already got that in your accessory so you won't pick that again.";
		return;
	}
	
	cout << "Do you want to pick it up? y/n : ";

	if (!verifyAnswer())
	{
		cout << "\nThis item will now be left alone\n";
		return;
	}

	
	if (itemCounter >= arraySize)
	{
		cout << "The chest is already full. This is what we have now:\n\n";
		this->showTreasures();
		cout << "Do you want any of already posessed items to be replaced or would you rather like to leave this new item alone? y/n : ";
		
		if (!verifyAnswer())
		{
			cout << "\nThis item will now be left alone\n";
			return;
		}

		replaceTreasure(treasurePtr);

		return;
	}


	addTreasure(treasurePtr);
	showTreasures();
	

}

template <class T>
int TreasureChest<T>::existingTreasureChoice(string& existingTreasureName)
{
	cout << "\nChoose existing treasure (enter its name here): ";
	cin >> existingTreasureName;
	return hasItem(existingTreasureName);
}


template <class T>
void TreasureChest<T>::replaceTreasure(int existingTreasureIndex, Treasure<T>* newTreasurePtr)
{
	treasureArray[existingTreasureIndex] = newTreasurePtr;
}


template <class T>
void TreasureChest<T>::replaceTreasure(Treasure<T>* newTreasurePtr)
{
	cout << "You currently have the following treasures in your chest:\n";
	showTreasures();
	cout << "\nWhich one of already posessed treasures would you like to replace with the encountered one? ";
	string nameChoice;

	int foundPosition = existingTreasureChoice(nameChoice);

	if (foundPosition > itemCounter)
	{
		cout << nameChoice << " treasure not found in your current treasure chest. No changes made to the existing treasure chest then..." << endl;
	}
	else
	{
		replaceTreasure(foundPosition, newTreasurePtr);
		cout << nameChoice << " successfully replaced with " << (*newTreasurePtr).getName() << endl;
		showTreasures();
	}
}



template <class T>
void TreasureChest<T>::showTreasures()
{
	cout << "\n\nThis is a Treasure chest called \"" << description << "\":\n\n";

	for (int i = 0; i < itemCounter; i++)
	{
		cout << "\tTreasure #" << i + 1 << ": " << *treasureArray[i] << endl;
	}

	cout << "\n\n";
}



template <class T>
void TreasureChest<T>::addTreasure(Treasure<T>* newTreasurePtr)
{
	treasureArray[itemCounter] = newTreasurePtr;
	itemCounter++;
	cout << newTreasurePtr->getName() << " added successfully" << endl;
}


template <class T>
void TreasureChest<T>::removeTreasure(int index)
{
	if (index < 0 || index >= itemCounter)
	{
		cout << "Non existent index provided..." << endl;
		return;
	}

	string removedTreasureName = (*treasureArray[index]).getName();

	for (int i = index; i < itemCounter - 1; i++)
	{
		treasureArray[i] = treasureArray[i + 1];
	}

	treasureArray[itemCounter - 1] = nullptr;
	itemCounter--;

	cout << "After removal of " << removedTreasureName << ":";
	showTreasures();
}


template <class T>
void TreasureChest<T>::removeTreasure(string name)
{
	int foundPosition = hasItem(name);

	if (foundPosition == arraySize + 1)
	{
		cout << "\"" << name << "\" not found in the chest, hence no removal performed" << endl;
	}

	removeTreasure(foundPosition);
}

