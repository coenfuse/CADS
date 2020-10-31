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

	List<int> secondList(45);
	secondList.insert(454);
	secondList.insert(78);
	secondList.insert(204);
	secondList.insert(984);
	secondList.insert(114);
	std::cout <<"Length of list before join "<< newList.length() << std::endl;
	std::cout << "Size of the list before join is: " << newList.size() << " bytes" << std::endl;
	secondList.display();
	newList.join(secondList);
	newList.display();

	std::cout << "Length of list after join " << newList.length() << std::endl;
	std::cout << "Size of the list before join is: " << newList.size() << " bytes" << std::endl;
	return 0;
}