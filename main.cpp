/**************************************************************************
 * Author: Kotaro Seto
 * Date: March 20, 2017
 * Description: This is the main.cpp that will play the ship game. It will
 * loop through the action() method of a Game object until the game is
 * finished. It will also contain introduction message for the player.
 **************************************************************************/
#include "Game.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::cout << "Welcome to the game.\n" << std::endl
	<< "I feel a slight dampness on my bed as you are suddenly awaken\n"
	<< "by an abrupt shake. It seems like the whole room was shaking.\n"
	<< "It is very dark and cold. The last thing I remember is sipping on\n"
	<< "whiskey while listening to smooth jazz at the cruize ship's jazz bar.\n"
	<< "What a pleasant memory. It feels so distant now although it was\n"
	<< "probably just a few hours ago. The flickering lights and the creaking \n"
	<< "walls create an ominous feeling in the room. Looking around the room, \n"
	<< "it seems to be partially flooded...\n"
	<< "What happened?.. \n"
	<< "Going for the budget option for this cruize didn't grant me a window,\n"
	<< "so there is no telling what's going on outside. The ship seems to be\n"
	<< "still now. It's uncomfortably still. Judging by the pain in my ears,\n"
	<< "the ship seems to have sunk and is now sitting at the bottom of the\n"
	<< "ocean. I need to escape.. I didn't pay for this.\n"
	<< std::endl
	<< "The extreme low temperature seems to be draining your health. Each action\n"
	<< "you take will hurt you due to the peircing frigidness of the envrionment.\n"
	<< "Your bed seems to be the only sanctuary for warmth where you can recover.\n"
	<< "It seems like your way out of the room first.\n" << std::endl;

	Game game;
	while (!game.isFinished()) {
		game.action();
		if (game.isDead()) {
			std::cout
			<< "It's too cold. I can't go on anymore. Maybe I'll just sleep here\n"
			<< "for a littlebit... \n" 
			<< "THE END\n" << std::endl;
			return 0;
		}
	}

	return 0;
}
