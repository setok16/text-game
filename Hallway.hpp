/************************************************************************
 * Author: Kotaro Seto
 * Date: March 17, 2017
 * Description: This is the class header for Hallway, which is a derived
 * class of Space.
 ***********************************************************************/
#ifndef HALLWAY_HPP
#define HALLWAY_HPP

#include "Space.hpp"

class Hallway : public Space
{
	private:
	public:
		Hallway(std::string, bool);
		bool unlock(Player*);
		bool checkDebris(Player*);
};

#endif
