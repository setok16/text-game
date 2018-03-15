/*****************************************************************************
 * Author: Kotaro Seto
 * Date: March 18, 2017
 * Description: This is the class implementation for the CrewCabin class.
 *****************************************************************************/
#include "CrewCabin.hpp"

CrewCabin::CrewCabin(std::string n, bool l) : Space(n, l)
{}

bool CrewCabin::unlock(Player* pPtr)
{
	std::vector<Item*> items = pPtr->getItems();
	for (unsigned int i = 0; i < items.size(); i++) {
		if (items[i]->getName() == "crew key" && locked) {
			locked = false;
			std::cout << "I've unlocked the door." << std::endl;
			return true;
		}
	}
	return false;
}

/******************************************************************************
 * If the player doesn't have flippers, it will be added to his inventory.
 *****************************************************************************/
bool CrewCabin::checkBed(Player* pPtr)
{
	std::vector<Item*> items = pPtr->getItems();
	for (unsigned int i = 0; i < items.size(); i++) {
		if (items[i]->getName() == "flippers") {
			std::cout << "Nothing here..." << std::endl;
			return false;
		}
	}
	Item* iPtr = new Item("flippers", "Can be used to swim faster");
	pPtr->addItem(iPtr);
	std::cout << "I found a pair of flippers." << std::endl;
	return true;
}

/******************************************************************************
 * Displays the code needed to access the tech bay.
 *****************************************************************************/
bool CrewCabin::readWhiteboard(Player* pPtr)
{
	std::cout << "The whiteboard reads 3355.\n" 
	<< "It looks like an access code for some area." << std::endl;
	return true;
}
