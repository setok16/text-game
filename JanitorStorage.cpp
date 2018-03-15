/*************************************************************************
 * Author: Kotaro Seto
 * Date: March 18, 2017
 * Description: This is the class implementation for the JanitorStorage
 * class.
 ************************************************************************/
#include "JanitorStorage.hpp"

JanitorStorage::JanitorStorage(std::string n, bool l) : Space(n, l)
{}

bool JanitorStorage::unlock(Player* pPtr)
{
	std::vector<Item*> items = pPtr->getItems();
	for (unsigned int i = 0; i < items.size(); i++) {
		if (items[i]->getName() == "janitor key" && locked) {
			locked = false;
			std::cout << "I've unlocked the door." << std::endl;
			return true;
		}
	}
	return false;
}

bool JanitorStorage::checkRack(Player* pPtr)
{
	std::vector<Item*> items = pPtr->getItems();
	for (unsigned int i = 0; i < items.size(); i++) {
		if (items[i]->getName() == "crow bar") {
			std::cout << "Nothing here..." << std::endl;
			return false;
		}
	}
	Item* iPtr = new Item("crow bar", "Can open the rustiest of valves");
	pPtr->addItem(iPtr);
	std::cout << "I've found a crow bar. Lets hold onto this just incase..."  
	<< std::endl;
	return true;
}

bool JanitorStorage::checkToolBox(Player* pPtr)
{
	std::vector<Item*> items = pPtr->getItems();
	for (unsigned int i = 0; i < items.size(); i++) {
		if (items[i]->getName() == "master key") {
			std::cout << "Nothing here..." << std::endl;
			return false;
		}
	}
	Item* iPtr = new Item("master key", "Can be used to open the guest cabins");
	pPtr->addItem(iPtr);
	std::cout << "There was a master key. This can open the guest cabin.\n"  
	<< "The janitor probably left it here." << std::endl;
	return true;
}
