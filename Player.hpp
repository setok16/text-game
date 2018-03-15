/****************************************************************************
 * Author: Kotaro Seto
 * Date: March 16, 2017
 * Description: This is the class header file for the Player class.
 ***************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Space.hpp"
#include "Backpack.hpp"
#include <string>

class Space;//needed for circular dependencies

class Player
{
	private:
		int health;
		Space* current;
		Backpack backpack;
		bool readyToEscape;
	public:
		Player();
		~Player();

		//Set methods
		void setCurrent(Space*);
		void addItem(Item*);
		void recover();
		void escapeReady();

		//Get methods
		Space* getCurrent();
		std::vector<Item*> getItems();
		int getHealth();
		bool isEscapeReady();

		void decrementHealth();
		bool isDead();
		
};

#endif
