/*****************************************************************************
 * Author: Kotaro Seto
 * Date: March 16, 2017
 * Description: This is the class implementation file for CabinCrew.
 ****************************************************************************/
#include "GuestCabin.hpp"

GuestCabin::GuestCabin(std::string n, bool l) : Space(n, l)
{
	doorLodged = true;
}

/****************************************************************************
 * Unlocks door if player has the master key and returns a bool.
 ****************************************************************************/
bool GuestCabin::unlock(Player* pPtr)
{
	std::vector<Item*> items = pPtr->getItems();
	for (unsigned int i = 0; i < items.size(); i++) {
		if (items[i]->getName() == "master key" && locked) {
			locked = false;
			std::cout << "I've unlocked the door." << std::endl;
			return true;
		}
	}
	return false;
}

/****************************************************************************
 * Checks desk for items. If player does not have a flashlight, it will be
 * added to his inventory. Returns a bool for success.
 ***************************************************************************/
bool GuestCabin::checkDesk(Player* pPtr)
{
	std::vector<Item*> items = pPtr->getItems();
	if (this->name == "player cabin") {
		for (unsigned int i = 0; i < items.size(); i++) {
			if (items[i]->getName() == "flashlight") {
				std::cout << "There seems to be nothing else here." << std::endl;
				return false;
			}
		}
		Item* iPtr = new Item("flashlight", "A regular flashlight");
		pPtr->addItem(iPtr);
		std::cout << "A flashlight. I might need this later." << std::endl;
		return true;
	} else { //if this is the guest cabin object
		for (unsigned int i = 0; i < items.size(); i++) {
			if (items[i]->getName() == "crew key") {
				std::cout << "There seems to be nothing else here." << std::endl;
				return false;
			}
		}
		Item* iPtr = new Item("crew key", "This can open the crew cabins");
		std::cout << "I've found a crew key. Now, I can open the crew cabins."
		<< std::endl;
		pPtr->addItem(iPtr);
		return true;
	}
}

/****************************************************************************
 * This will break the desk so that the player can acquire the deskleg.
 ***************************************************************************/
bool GuestCabin::takeDeskApart(Player* pPtr)
{
	bool hasScrewdriver = false;
	std::vector<Item*> items = pPtr->getItems();
	Item* iPtr = new Item("desk leg", "A desk leg you too off");
	for (unsigned int i = 0; i < items.size(); i++) {
		if (items[i]->getName() == "screwdriver") {
			hasScrewdriver = true;
		}
	}

	if (hasScrewdriver){
		for (unsigned int i = 0; i < items.size(); i++) {
			if (items[i]->getName() == "desk leg") {
				std::cout << "I already have a desk leg." << std::endl;
				return false;
			}
		}
		std::cout << "I've managed to take off a desk leg." << std::endl;
		pPtr->addItem(iPtr);
		return true;
	}
	std::cout << "It looks like I will need a tool to take this desk apart."
	<< std::endl;
	return false;
}

/****************************************************************************
 * This will check the bed for items. Same deal as before, but the player
 * will get a screwdriver.
 ***************************************************************************/
bool GuestCabin::checkBed(Player* pPtr)
{
	std::vector<Item*> items = pPtr->getItems();
	for (unsigned int i = 0; i < items.size(); i++) {
		if (items[i]->getName() == "screwdriver") {
			std::cout << "Nothing here..." << std::endl;
			return false;
		}
	}
	Item* iPtr = new Item("screwdriver", "Could be used to take things apart");
	pPtr->addItem(iPtr);
	std::cout << "A screwdriver. Perhaps I can use this to take something apart."
	<< std::endl;
	return false;
}

/****************************************************************************
 * Changes the bool doorLodged to false so that player can go through the
 * south door which is lodged. Player needs the desk leg to do this.
 ***************************************************************************/
 bool GuestCabin::dislodgeDoor(Player* pPtr)
 {
	std::vector<Item*> items = pPtr->getItems();
	bool hasDeskLeg = false;
	for (unsigned int i = 0; i < items.size(); i++) {
		if (items[i]->getName() == "desk leg") {
			hasDeskLeg = true;
		}
	}

	if (hasDeskLeg) {
		doorLodged = false;
		std::cout << "The door has been dislodged." << std::endl;
		return true;
	}
	std::cout << "I'll need something to dislodge the door with. "
	<< "Perhaps something with leverage." << std::endl;
	return false;
 }

/*****************************************************************************
 * This will change the player's current location pointer to s3. The door
 * must have been dislodged prior to call this otherwise it will fail.
 * Also, the player needs to have a flashlight to go through the south
 * door.
 ****************************************************************************/
 bool GuestCabin::goThroughSouthDoor(Player* pPtr)
 {
	if (this->name == "player cabin") {
		std::vector<Item*> items = pPtr->getItems();
		if (!doorLodged) {
			for (unsigned int i = 0; i < items.size(); i++) {
				if (items[i]->getName() == "flashlight") {
				pPtr->setCurrent(s3);
				std::cout << "Entering hallway 1." << std::endl;
				return true;
				}
			}
			std::cout << "It is way too dark outside the cabin.\n"
			<< "I better find something to light my way." << std::endl;
			return false;
		}

		std::cout << "The door seems to be lodged. I'll need to change that\n"
		<< "if I ever plan on going through this door." << std::endl;
		return false;
	} else { //guest cabin case
		std::cout << "Entering " << s3->getName() << " ." << std::endl;
		pPtr->setCurrent(s3);
		return true;
	}
 }

/************************************************************************
 * This method will recover the player's health.
 ***********************************************************************/
bool GuestCabin::rest(Player* pPtr)
{
	pPtr->recover();
	std::cout << "I now have 20 health." << std::endl;
	return true;
}
