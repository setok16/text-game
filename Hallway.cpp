/************************************************************************
 * Author: Kotaro Seto
 * Date: March 17, 2017
 * Description: This is the class implementation file for Hallway.
 ***********************************************************************/
#include "Hallway.hpp"

Hallway::Hallway(std::string n, bool l) : Space(n, l)
{
}

bool Hallway::unlock(Player* pPtr)
{
	locked = false;
	return true;
}

/************************************************************************
 * If the object name is "hallway 1", this will add an airtank to the
 * player's backpack inventory. If the object name is "hallway 2", it will
 * do nothing.
 ************************************************************************/
bool Hallway::checkDebris(Player* pPtr)
{
	if (this->name == "hallway 1") {
		std::vector<Item*> items = pPtr->getItems();
		for (unsigned int i = 0; i < items.size(); i++) {
			if (items[i]->getName() == "air tank") {
				std::cout << "Nothing here..." << std::endl;
				return false;
			}
		}
		Item* iPtr = new Item("air tank", "Barely any air left");
		pPtr->addItem(iPtr);
		std::cout << "An air tank. The gauge indicates that the tank is\n"
		<< "very low on air. If I plan on using this to escape, I'll \n"
		<< "need to swim very quickly. Unfortunately, I'm not a fast\n"
		<< "swimmer."
		<< std::endl;
		return true;
	} else if (this->name == "hallway 2") {
		std::vector<Item*> items = pPtr->getItems();
		for (unsigned int i = 0; i < items.size(); i++) {
			if (items[i]->getName() == "janitor key") {
				std::cout << "Nothing here..." << std::endl;
				return false;
			}
		}
		Item* iPtr = new Item("janitor key", "Can be used to open the janitor storage");
		pPtr->addItem(iPtr);
		std::cout << "Found a janitor key. I did see a janitor storage room..."
		<< std::endl;
		return true;
	}
	return false;
}

