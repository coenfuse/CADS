#include "../test.h"
#include "../../src/array.h"
#include <array>
#include <iostream>

void testing::test_array() {

	// Consists of all the code for unit testing the array data structure.
	std::cout << "Array test module running." << std::endl;

	cads::array<int, 20> test;
	for (size_t index = 0; index < 10; index++) {
		
		//test.at(index) = 10;		// This shouldn't work
	}

	std::cout << test.size() << std::endl;
	std::cout << test.max_size() << std::endl;
	std::cout << test.vacant() << std::endl;
}