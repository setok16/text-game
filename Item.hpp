/**************************************************************************
 * Author: Kotaro Seto
 * Date: March 11, 2017
 * Description: This is the Item class header file. 
 *************************************************************************/
 #ifndef ITEM_HPP
 #define ITEM_HPP
 #include <vector>
 #include <string>

 class Item
 {
	private:
		std::string name;
		std::string description;
	public:
		Item(std::string, std::string);
		~Item();
		std::string getName();
		std::string getDescription();
 };

 #endif

