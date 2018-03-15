/*************************************************************************
 * Author: Kotaro Seto
 * Description: This is the utility function source code.
 ************************************************************************/
#include "utility.hpp"

void cinCleanUp()
{
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	std::cout << "Please enter a valid input." << std::endl;
}
