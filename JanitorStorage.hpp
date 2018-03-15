/************************************************************************
 * Author: Kotaro Seto
 * Date: March 18, 2017
 * Description: This is the class header for the JanitorStorage class. It
 * is inherited from the Space class.
 ***********************************************************************/
#ifndef JANITOR_STORAGE
#define JANITOR_STORAGE
#include "Space.hpp"

class JanitorStorage : public Space
{
	public:
		JanitorStorage(std::string, bool);
		bool unlock(Player*);
		bool checkRack(Player*);
		bool checkToolBox(Player*);
};

#endif
