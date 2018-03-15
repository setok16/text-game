/************************************************************************
 * Author: Kotaro Seto
 * Date: March 11, 2017
 * Description: This is the Item class implementation file.
 ***********************************************************************/
#include "Item.hpp"

// Constructor
Item::Item(std::string n, std::string d)
{
	name = n;
	description = d;
}

// Deconstructor
Item::~Item(){}

/***********************************************************************
 *	Get Methods
 **********************************************************************/
 std::string Item::getName()
 {
	return name;
 }
 std::string Item::getDescription()
 {
	return description;
 }
