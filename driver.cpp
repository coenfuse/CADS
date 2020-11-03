#include <iostream>
#include <string>
#include "learn\learn.h"

int main() {
	std::cout << "Driver Code" << std::endl;

	List<int> newList(34);
	newList.insert(674);
	newList.insert_beg(6855);
	newList.insert_at(42, 0);
	newList.insert_at(87, (unsigned int)newList.length());
	newList.insert_at(534, 8);
	newList.insert(156);
	newList.insert(88);
	newList.insert(156);
	newList.insert(654);
	newList.insert(156);
	newList.insert(892);
	newList.insert(156);
	newList.insert(267);
	newList.insert(489);
	newList.display();
	newList.shuffle();
	newList.display();
	newList.split(5).first.display();
	newList.split(5).second.display();
	return 0;
}