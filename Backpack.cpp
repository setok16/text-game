/************************************************************************
 * Author: Kotaro Seto
 * Date: March 11, 2017
 * Description: This is the Backpack class implementation file.
 ***********************************************************************/
#include "Backpack.hpp"

// Default Constructor
Backpack::Backpack()
{
	Item* iptr = new Item("room key", "My room key");
	inventory.push_back(iptr);
}	

// Destructor
Backpack::~Backpack()
{
	for (unsigned int i = 0; i < inventory.size(); i++) {
		delete inventory[i];
		inventory[i] = nullptr;
	}
}

/***********************************************************************
 * Takes as a parameter a name of an item and returns the index of the
 * inventory vector for that particular item.
 **********************************************************************/
int Backpack::findItemIndex(std::string n)
{
	int marker;
	for (unsigned int i = 0; i < inventory.size(); i++){
		if (inventory[i]->getName() == n) {
			marker = i;
		}
	}
	return marker;
}

/*************************************************************************
 * Push back an Item pointer to the inventory vector.
 ************************************************************************/
void Backpack::pushItem(Item* i)
{
	inventory.push_back(i);
}

/**************************************************************************
 * This method will take the item index as a parameter and returns the
 * Item*.
 *************************************************************************/
std::vector<Item*> Backpack::getItems()
{
	return inventory;
}

