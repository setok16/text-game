/*********************************************************************
 * Author: Kotaro Seto
 * Date: March 19, 2017
 * Description: This is the class implementation for the Game class.
 ********************************************************************/
#include "Game.hpp"

/*********************************************************************
 * The constructor assigns all the rooms to their proper locations.
 ********************************************************************/
Game::Game()
{
	finished = false;
	playerCabin->setDoors(nullptr, nullptr, hallway1, nullptr);
	guestCabin->setDoors(nullptr, hallway1, nullptr, nullptr);
	hallway1->setDoors(playerCabin, hallway2, janitorStorage, guestCabin);
	hallway2->setDoors(techBay, crewCabin, nullptr, hallway1);
	janitorStorage->setDoors(hallway1, nullptr, nullptr, nullptr);
	crewCabin->setDoors(nullptr, nullptr, nullptr, hallway2);
	techBay->setDoors(emergencyExit, nullptr, hallway2, nullptr);
	emergencyExit->setDoors(nullptr, nullptr, techBay, nullptr);
	player->setCurrent(playerCabin);
}

/********************************************************************
 * The destructor is responsible for freeing all of the memories for
 * its member variables.
 *******************************************************************/

Game::~Game()
{
	delete player;
	delete playerCabin;
	delete guestCabin;
	delete hallway1;
	delete hallway2;
	delete janitorStorage;
	delete crewCabin;
	delete techBay;
	delete emergencyExit;

	player = nullptr;
	playerCabin = nullptr;
	guestCabin = nullptr;
	hallway1 = nullptr;
	hallway2 = nullptr;
	janitorStorage = nullptr;
	crewCabin = nullptr;
	techBay = nullptr;
	emergencyExit = nullptr;
}

/********************************************************************
 * This function will let the user choose an item from his inventory
 * and read its descriptions.
 *******************************************************************/
void Game::checkInventory()
{
	int choice;
	int i;
	std::vector<Item*> items = player->getItems();
	for (i = 0; i < items.size(); i++) {
		std::cout << i+1 << ". " << items[i]->getName() << std::endl;
	}
	std::cout << i+1 << ". exit" << std::endl;
	std::cout << "\nSelect an item you'd like to inspect: ";
	cinValidation(1, i+1, choice);
	std::cout << std::endl;
	if (choice < i) {
		std::cout
		<< "Name: \t\t"<< items[choice-1]->getName() << std::endl
		<< "Description: \t" << items[choice-1]->getDescription() 
		<< std::endl;
	} 
}


/*********************************************************************
* Displays the current player location and health points.
*********************************************************************/
void Game::displayCurrentStatus()
{
	std::cout << "Your current location: " 
	<< (player->getCurrent())->getName() << std::endl
	<< "Your current health: " << player->getHealth() << std::endl;
}


/*********************************************************************
 * Returns true if the player has made it to the emergency exit.
 ********************************************************************/
bool Game::isFinished()
{
	return finished;
}

/*********************************************************************
 * Returns true if player is dead
 ********************************************************************/
bool Game::isDead()
{
	if (player->isDead()) {
		return true;
	} else {
		return false;
	}
}

/*********************************************************************
 * This function will be responsible for displaying all the methods
 * available in the player's locataion. The user can then choose an action
 * to take. This will be looped in main()
 *********************************************************************/
void Game::action()
{	
	int choice;
	Space* sPtr = player->getCurrent();
	// if the player is in player cabin
	if (sPtr->getName() == "player cabin") {
		GuestCabin* gPtr = static_cast<GuestCabin*>(sPtr);
		std::cout << "Please select an action.\n"
		<< "*******************************\n"
		<< "1. Check inventory.\n"
		<< "2. Check current status.\n"
		<< "3. Take a rest.\n"
		<< "4. Inspect the desk.\n"
		<< "5. Take the desk apart.\n"
		<< "6. Inspect the bed.\n"
		<< "7. Dislodge the door.\n" 
		<< "8. Exit room.\n"
		<< "*******************************\n" << std::endl;
		cinValidation(1, 8, choice);

		switch (choice){
			case 1:
				checkInventory();
				std::cout << std::endl;
				break;
			case 2:
				displayCurrentStatus();
				std::cout << std::endl;
				break;
			case 3:
				gPtr->rest(player);
				std::cout << std::endl;
				break;
			case 4:
				gPtr->checkDesk(player);
				std::cout << std::endl;
				break;
			case 5:
				gPtr->takeDeskApart(player);
				std::cout << std::endl;
				break;
			case 6:
				gPtr->checkBed(player);
				std::cout << std::endl;
				break;
			case 7:
				gPtr->dislodgeDoor(player);
				std::cout << std::endl;
				break;
			case 8:
				gPtr->goThroughSouthDoor(player);
				std::cout << std::endl;
				break;
		}
	} else if (sPtr->getName() == "hallway 1"){
		Hallway* hPtr = static_cast<Hallway*>(sPtr);
		std::cout << "Please select an action.\n"
		<< "********************************\n"
		<< "1. Check inventory.\n"
		<< "2. Check current status.\n"
		<< "3. Inspect debris.\n"
		<< "4. Go through door to player cabin.\n"
		<< "5. Go through door to hallway 2.\n"
		<< "6. Go through door to janitor storage.\n"
		<< "7. Go through door to guest cabin.\n"
		<< "********************************\n" << std::endl;
		cinValidation(1, 7, choice);

		switch (choice){
			case 1:
				checkInventory();
				std::cout << std::endl;
				break;
			case 2:
				displayCurrentStatus();
				std::cout << std::endl;
				break;
			case 3:
				hPtr->checkDebris(player);
				std::cout << std::endl;
				break;
			case 4:
				hPtr->goThroughNorthDoor(player);
				std::cout << std::endl;
				break;
			case 5:
				hPtr->goThroughEastDoor(player);
				std::cout << std::endl;
				break;
			case 6:
				hPtr->goThroughSouthDoor(player);
				std::cout << std::endl;
				break;
			case 7:
				hPtr->goThroughWestDoor(player);
				std::cout << std::endl;
				break;
		}
	} else if (sPtr->getName() == "hallway 2"){
		Hallway* hPtr = static_cast<Hallway*>(sPtr);
		std::cout << "Please select an action.\n"
		<< "********************************\n"
		<< "1. Check inventory.\n"
		<< "2. Check current status.\n"
		<< "3. Inspect debris.\n"
		<< "4. Go through door to tech bay.\n"
		<< "5. Go through door to crew cabin.\n"
		<< "6. Go through door to hallway 1.\n"
		<< "********************************\n" << std::endl;
		cinValidation(1, 6, choice);

		switch (choice){
			case 1:
				checkInventory();
				std::cout << std::endl;
				break;
			case 2:
				displayCurrentStatus();
				std::cout << std::endl;
				break;
			case 3:
				hPtr->checkDebris(player);
				std::cout << std::endl;
				break;
			case 4:
				hPtr->goThroughNorthDoor(player);
				std::cout << std::endl;
				break;
			case 5:
				hPtr->goThroughEastDoor(player);
				std::cout << std::endl;
				break;
			case 6:
				hPtr->goThroughWestDoor(player);
				std::cout << std::endl;
				break;
		}
	} else if (sPtr->getName() == "janitor storage") {
		JanitorStorage* jPtr = static_cast<JanitorStorage*>(sPtr);
		std::cout << "Please select an action.\n"
		<< "********************************\n"
		<< "1. Check inventory.\n"
		<< "2. Check current status.\n"
		<< "3. Inspect the storage rack.\n"
		<< "4. Inspect the tool box.\n"
		<< "5. Exit room.\n"
		<< "********************************\n" << std::endl;
		cinValidation(1, 5, choice);

		switch (choice){
			case 1:
				checkInventory();
				std::cout << std::endl;
				break;
			case 2:
				displayCurrentStatus();
				std::cout << std::endl;
				break;
			case 3: 
				jPtr->checkRack(player);
				std::cout << std::endl;
				break;
			case 4:
				jPtr->checkToolBox(player);
				std::cout << std::endl;
				break;
			case 5:
				jPtr->goThroughNorthDoor(player);
				std::cout << std::endl;
				break;
		}
	} else if (sPtr->getName() == "crew cabin") {
		CrewCabin* cPtr = static_cast<CrewCabin*>(sPtr);
		std::cout << "Please select an action.\n"
		<< "********************************\n"
		<< "1. Check inventory.\n"
		<< "2. Check current status.\n"
		<< "3. Inspect the bed.\n"
		<< "4. Inspect the whiteboard.\n"
		<< "5. Exit room.\n"
		<< "********************************\n" << std::endl;
		cinValidation(1, 5, choice);

		switch (choice){
			case 1:
				checkInventory();
				std::cout << std::endl;
				break;
			case 2:
				displayCurrentStatus();
				std::cout << std::endl;
				break;
			case 3: 
				cPtr->checkBed(player);
				std::cout << std::endl;
				break;
			case 4:
				cPtr->readWhiteboard(player);
				std::cout << std::endl;
				break;
			case 5:
				cPtr->goThroughWestDoor(player);
				std::cout << std::endl;
				break;
		}
	} else if (sPtr->getName() == "guest cabin") {
		GuestCabin* gPtr = static_cast<GuestCabin*>(sPtr);
		std::cout << "Please select an action.\n"
		<< "********************************\n"
		<< "1. Check inventory.\n"
		<< "2. Check current status.\n"
		<< "3. Take a rest.\n"
		<< "4. Inspect the desk.\n"
		<< "5. Inspect the bed.\n"
		<< "6. Exit room.\n"
		<< "********************************\n" << std::endl;
		cinValidation(1, 6, choice);

		switch (choice){
			case 1:
				checkInventory();
				std::cout << std::endl;
				break;
			case 2:
				displayCurrentStatus();
				std::cout << std::endl;
				break;
			case 3:
				gPtr->rest(player);
				std::cout << std::endl;
				break;
			case 4:
				gPtr->checkDesk(player);
				std::cout << std::endl;
				break;
			case 5:
				gPtr->checkBed(player);
				std::cout << std::endl;
				break;
			case 6:
				gPtr->goThroughEastDoor(player);
				std::cout << std::endl;
				break;
		}
	} else if (sPtr->getName() == "tech bay") {
		TechBay* tPtr = static_cast<TechBay*>(sPtr);
		std::cout << "Please select an action.\n"
		<< "********************************\n"
		<< "1. Check inventory.\n"
		<< "2. Check current status.\n"
		<< "3. Turn the drainage valve.\n"
		<< "4. Activate the generator.\n"
		<< "5. Go through emergency hatch.\n"
		<< "6. Exit room.\n" 
		<< "********************************\n" << std::endl;
		cinValidation(1, 6, choice);

		switch (choice){
			case 1:
				checkInventory();
				std::cout << std::endl;
				break;
			case 2:
				displayCurrentStatus();
				std::cout << std::endl;
				break;
			case 3:
				tPtr->turnDrainageValve(player);
				std::cout << std::endl;
				break;
			case 4:
				tPtr->activateGenerator(player);
				std::cout << std::endl;
				break;
			case 5:
				tPtr->goThroughNorthDoor(player);
				std::cout << std::endl;
				break;
			case 6:
				tPtr->goThroughSouthDoor(player);
				std::cout << std::endl;
				break;
		} 
	} else {
		std::cout 
		<< "Congratulations. You've exited the ship safely with an air\n"
		<< "tank and flippers. As you quickly ascend to the surface,\n"
		<< "you feel a wild annoyance in your joints.\n"
		<< "You have the BENDS. There is a burning sensation throughout\n"
		<< "your body. As you realize there are no rescue teams in the\n"
		<< "area, you die in agonizing pain.\n" 
		<< std::endl << "THE END" << std::endl;
		finished = true;
	}
	player->decrementHealth();
}
