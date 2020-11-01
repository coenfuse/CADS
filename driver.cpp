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
	std::cout<<std::endl;
	std::cout << std::endl;
	newList.reverse();
	newList.display();
	//newList.insert(49);
	newList.insert_beg(94);
	std::cout << std::endl; 
	newList.display();
	//newList.peekFirst();
	return 0;
}