/*************************************************************************
 * Author: Kotaro Seto
 * Date: Mar 16, 2017
 * Description: This is the header file for the Space base class.
 ************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Item.hpp"
#include "Player.hpp"

class Player;

class Space
{
	protected:
		std::string name;
		bool locked;
		Space* s1;
		Space* s2;
		Space* s3;
		Space* s4;
	public:
		Space(std::string, bool);
		virtual ~Space();
		void setDoors(Space*, Space*, Space*, Space*);
		virtual bool unlock(Player*) = 0;
		bool isLocked();
		std::string getName();
		virtual bool goThroughNorthDoor(Player*);
		virtual bool goThroughEastDoor(Player*);
		virtual bool goThroughSouthDoor(Player*);
		virtual bool goThroughWestDoor(Player*);
};

#endif
