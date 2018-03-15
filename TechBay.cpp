/*********************************************************************
 * Author: Kotaro Seto
 * Date: March 19, 2017
 * Description: This is the class implementaion for TechBay. 
 *********************************************************************/
#include "TechBay.hpp"

//Constructor
TechBay::TechBay(std::string n, bool l) : Space(n, l)
{
	drainageValve = false;
	generator = false;
}

/**********************************************************************
 * To unlock this room, the player must input the key code obtained from
 * the crew cabin. The parameter isn't used, but it is kept this way to
 * keep the program's consistency.
 *********************************************************************/
bool TechBay::unlock(Player* pPtr)
{
	int code;
	std::cout << "Enter the 4 digit key code: ";
	std::cin >> code;
	std::cout << std::endl;
	if (code == 3355) {
		std::cout << "The door to the tech bay is unlocked." << std::endl;
		locked = false;
		return true;
	} else {
		std::cout << "Wrong key code." << std::endl;
		return false;
	}
}

/**********************************************************************
 * This will make the drainageValve = true; If generator == true, then the
 * method will unlock the emergency exit which will be s1.
 *********************************************************************/
bool TechBay::turnDrainageValve(Player* pPtr)
{
	std::vector<Item*> items = pPtr->getItems();
	for (unsigned int i = 0; i < items.size(); i++) {
		if (items[i]->getName() == "crow bar") {
			drainageValve = true;
			if (generator == true) {
				pPtr->escapeReady();
			}
			std::cout << "Using the crow bar, I was able to turn this "
			<< "rusty monstrosity \nof a drainage valve. The escape "
			<< "hatch should be \ndepressurized now." << std::endl;
			return true;
		}
	}
	std::cout 
	<< "The drainage valve is rusted shut. I'll need some good leverage\n"
	<< "if I want to turn this valve." << std::endl;
	return false;
}

/**********************************************************************
 * This will make the generator = true; If drainageValve == true, then the
 * method will unlock the emergency exit which will be s1.
 **********************************************************************/
bool TechBay::activateGenerator(Player* pPtr)
{
	generator = true;
	if (drainageValve == true) {
		pPtr->escapeReady();
	}
	std::cout << "The generator turned on with a reassuring vroom.\n"
	<< "Everything seems to be looking brighter." << std::endl;
	return true;
}
