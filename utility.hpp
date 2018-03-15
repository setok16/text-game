/************************************************************************
 * Author: Kotaro Seto
 * Description: This is the header file for the utility function library.
 ***********************************************************************/

#ifndef UTILITY_HPP
#define UTILUTY_HPP
#include <iostream>

template <typename T>
bool outOfRange(T min, T max, T input)
{
	bool inRange = false;
	if (input >= min && input <= max)
	{
		inRange = true;
	}
	return inRange;
}

void cinCleanUp();

/***************************************************************************
 * This utility function will take as parameters the minimum value, maximum 
 * value, and the input variable and checks to see if the input is valid.
 * This is a template function, so it should work with most data types.
 **************************************************************************/
template <typename T>
void cinValidation(T min, T max, T &input)
{
	while (!(std::cin >> input) || !outOfRange(min, max, input)) {
		cinCleanUp();
	}
}

#endif
