/************************************************************************
 * Author: Kotaro Seto
 * Date: March 16, 2017
 * Description: This is the class header for GuestCabin, which is a derived
 * class of Space.
 ***********************************************************************/
#ifndef GUESTCABIN_HPP
#define GUESTCABIN_HPP

#include "Space.hpp"

class GuestCabin : public Space
{
	private:
		bool doorLodged;
	public:
		GuestCabin(std::string, bool);
		bool unlock(Player*);
		bool checkDesk(Player*);
		bool takeDeskApart(Player*);
		bool checkBed(Player*);
		bool dislodgeDoor(Player*); 
		bool goThroughSouthDoor(Player*);
		bool rest(Player*);
};

#endif
