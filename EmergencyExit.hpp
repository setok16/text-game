/**********************************************************************
 * Author: Kotaro Seto
 * Date: March 19, 2017
 * Description: This is the class header for the EmergencyExit class, which
 * inherits from Space. Once the player manages to reach this room, the
 * game is finished.
 *********************************************************************/
#ifndef EMERGENCY_EXIT
#define EMERGENCY_EXIT
#include "Space.hpp"

class EmergencyExit : public Space
{
	public:
		EmergencyExit(std::string, bool);
		bool unlock(Player*);
};

#endif

