/*************************************************************************
 * Author: Kotaro Seto
 * Date: March 11, 2017
 * Description: This is the Backpack class header file. It includes the
 * item class and stores it in a vector as a member variable.
 ************************************************************************/
#ifndef BACKPACK_HPP
#define BACKPACK_HPP
#include "Item.hpp"
#include <vector>
#include <string>
#include <memory> // shared_ptr
#include <iostream>

class Backpack
{
	private:
		std::vector<Item*> inventory;
	public:
		Backpack();
		~Backpack();
		int findItemIndex(std::string);
		void pushItem(Item*);
		std::vector<Item*> getItems();
};

#endif
