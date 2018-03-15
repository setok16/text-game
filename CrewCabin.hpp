/**************************************************************************
 * Author: Kotaro Seto
 * Date: March 18, 2017
 * Description: This is the class header file for the CrewCabin class. It
 * inherits the Space class.
 *************************************************************************/
#ifndef CREWCABIN_HPP
#define CREWCABIN_HPP

#include "Space.hpp"

class CrewCabin : public Space
{
	private:
	public:
		CrewCabin(std::string, bool);
		bool unlock(Player*);
		bool checkBed(Player*);
		bool readWhiteboard(Player*);
};

#endif
