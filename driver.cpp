#include <iostream>
#include <string>
#include "include/ds.h"

int main() {
	std::cout << "Driver Code" << std::endl;

	List<int> newList(34);
	newList.insert(674);
	newList.insert_beg(6855);
	newList.insert_at(42, 0);
	newList.insert_at(87, newList.length());
	newList.insert_at(534, 8);
	newList.display();
	List<int> secondList(34);
	secondList.insert(29);
	secondList.insert(56);
	secondList.insert(96);
	std::cout << secondList.peekMiddle() << std::endl;


	return 0;
}