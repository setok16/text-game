/*************************************************************************
 * Author: Kotaro Seto
 * Date: March 19, 2017
 * Description: This is the class header for TechBay. This class is
 * inherited from the Space class.
 ************************************************************************/
#ifndef TECHBAY_HPP
#define TECHBAY_HPP
#include "Space.hpp"

class TechBay : public Space
{
	private:
		bool drainageValve;
		bool generator;
	public:
		TechBay(std::string, bool);
		bool unlock(Player*);
		bool turnDrainageValve(Player*);
		bool activateGenerator(Player*);
};

#endif
