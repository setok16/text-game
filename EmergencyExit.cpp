/*********************************************************************
 * Author: Kotaro Seto
 * Date: March 19, 2017
 * Description: This is the class implementation for EmergencyExit.
 ********************************************************************/
#include "EmergencyExit.hpp"

EmergencyExit::EmergencyExit(std::string n, bool l) : Space(n, l)
{}

bool EmergencyExit::unlock(Player* pPtr)
{
	bool hasFlippers = false;
	bool hasTank = false;
	if (pPtr->isEscapeReady()) {
	std::vector<Item*> items = pPtr->getItems();
		for (unsigned int i = 0; i < items.size(); i++) {
			if (items[i]->getName() == "flippers") {
				hasFlippers = true;
			}
			if (items[i]->getName() == "air tank") {
				hasTank = true;
			}
		}
		if (hasFlippers && hasTank) {
			locked = false;
			return true;
		} else {
			std::cout << "I'll need some gear if I ever plan on "
			<< "making it to \nthe surface alive." << std::endl;
			return false;
		}
	} else {
		std::cout << "The exit door cannot be opened. There seems "
		<< "to be water \nblocking the door. The pressure build up "
		<< "is too much. \nThe water needs to be drained and the "
		<< "generator needs \nto be activated to open this door."
		<< std::endl;
		return false;
	}
}
