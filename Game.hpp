/********************************************************************
 * Author: Kotaro Seto
 * Date: March 19, 2017
 * Description: This is the class header for the Game class. 
 *******************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"
#include "Space.hpp"
#include "CrewCabin.hpp"
#include "EmergencyExit.hpp"
#include "GuestCabin.hpp"
#include "Hallway.hpp"
#include "JanitorStorage.hpp"
#include "TechBay.hpp"
#include "utility.hpp"

class Game
{
	private:
		Player* player = new Player;
		bool finished;
		GuestCabin* playerCabin = new GuestCabin("player cabin", false);
		GuestCabin* guestCabin = new GuestCabin("guest cabin", true);
		Hallway* hallway1 = new Hallway("hallway 1", false);
		Hallway* hallway2 = new Hallway("hallway 2", false);
		JanitorStorage* janitorStorage = 
		new JanitorStorage("janitor storage", true);
		CrewCabin* crewCabin = new CrewCabin("crew cabin", true);
		TechBay* techBay = new TechBay("tech bay", true);
		EmergencyExit* emergencyExit = 
		new EmergencyExit("emergency exit", true);
	public:
		Game();
		~Game();

		void checkInventory();
		void displayCurrentStatus();
		bool isFinished();
		bool isDead();
		void action();
};

#endif
