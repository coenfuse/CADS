#include <iostream>
#include "include/ds.h"

int main() {
	std::cout << "Driver Code" << std::endl;

	List<int> newList(5);
	newList.insert(4);
	newList.display();
	newList.insert(8);
	newList.display();
	newList.insert(9);
	newList.display();
	newList.insert(10);
	newList.display();
	newList.insert(15);
	newList.display();

	return 0;
}