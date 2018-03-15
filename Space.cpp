/**************************************************************************
 * Author: Kotaro Seto
 * Date: March 16, 2017
 * Description: This is the class implementation file for the Space class.
 *************************************************************************/
#include "Space.hpp"

//Constructor
Space::Space(std::string n, bool l)
{
	name = n;
	locked = l;
	this->s1 = nullptr;
	this->s2 = nullptr;
	this->s3 = nullptr;
	this->s4 = nullptr;
}

//Destructor
Space::~Space()
{
}

//Sets the Space pointers for the object
void Space::setDoors(Space* s1, Space* s2, Space* s3, Space* s4)
{
	this->s1 = s1;
	this->s2 = s2;
	this->s3 = s3;
	this->s4 = s4;
}

//Returns locked member variable
bool Space::isLocked()
{
	return locked;
}

//Get method for the name private member variable
std::string Space::getName()
{
	return name;
}

//Navigation methods
bool Space::goThroughNorthDoor(Player* pPtr)
{
	s1->unlock(pPtr);
	if (!s1->isLocked()) {
		std::cout << "Entering " << s1->getName() << "." << std::endl;
		pPtr->setCurrent(s1);
		return true;
	} else {
		if (s1->getName() != "emergency exit") {
			std::cout << "The door to " << s1->getName() << " is locked."
			<< std::endl;
		}
		return false;
	}
}
bool Space::goThroughEastDoor(Player* pPtr)
{
	s2->unlock(pPtr);
	if (!s2->isLocked()) {
		std::cout << "Entering " << s2->getName() << "." << std::endl;
		pPtr->setCurrent(s2);
		return true;
	} else {
		std::cout << "The door to " << s2->getName() << " is locked." << std::endl;
		return false;
	}
}
bool Space::goThroughSouthDoor(Player* pPtr)
{
	s3->unlock(pPtr);
	if (!s3->isLocked()) {
		std::cout << "Entering " << s3->getName() << "." << std::endl;
		pPtr->setCurrent(s3);
		return true;
	} else {
		std::cout << "The door to " << s3->getName() << " is locked." << std::endl;
		return false;
	}
}
bool Space::goThroughWestDoor(Player* pPtr)
{
	s4->unlock(pPtr);
	if (!s4->isLocked()) {
		std::cout << "Entering " << s4->getName() << "." << std::endl;
		pPtr->setCurrent(s4);
		return true;
	} else {
		std::cout << "The door to " << s4->getName() << " is locked." << std::endl;
		return false;
	}
}
