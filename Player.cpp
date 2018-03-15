/************************************************************************
 * Author: Kotaro Seto
 * Date: March 16, 2017
 * Description: This is the class implementation file for the Player class.
 ************************************************************************/
#include "Player.hpp"

Player::Player()
{
	health = 20;
	current = nullptr;
	readyToEscape = false;
}

Player::~Player()
{
}

void Player::setCurrent(Space* room)
{
	current = room;
}

/************************************************************************
 * This function will add an Item object to the player's backpack.
 ************************************************************************/
void Player::addItem(Item* item)
{
	backpack.pushItem(item);
}

Space* Player::getCurrent()
{
	return current;
}

int Player::getHealth()
{
	return health;
}

/************************************************************************
 * This method will return the Item object that matches the parameter name
 ************************************************************************/
std::vector<Item*> Player::getItems()
{
	return backpack.getItems();
}

void Player::recover()
{
	health = 20;
}

void Player::escapeReady()
{
	readyToEscape = true;
}

bool Player::isEscapeReady()
{
	return readyToEscape;
}

void Player::decrementHealth()
{
	if (health != 0) {
		health--;
	}
}

/**************************************************************************
 * Returns true if the player health is 0
 *************************************************************************/
bool Player::isDead()
{
	if (health == 0) {
		return true;
	} else {
		return false;
	}
}
