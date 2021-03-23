#include <iostream>
#include "../test.h"

const size_t test_size_const = 10;

void square_operator() {
	
	bool test_result = false;
	cads::array<int, test_size_const> test_container;

	std::cout << "Testing square brackets operator\n";

	for (size_t index = 0; index < test_size_const; index++) {
		try {
			test_container[index] = index * index;
		}
		catch (...) {
			test_result = false;
			break;
		}
		test_result = true;
	}

	if (test_result) std::cout << "Unit Test 1 : PASSED (Assign using square operator)\n";
	else {
		std::cout << "Unit Test 1 : FAILED (Assign using square operator)\n";
	}

	for (size_t index = 0; index < test_size_const; index++) {
		switch (test_container[index])
		{
		case 0:
		case 1:
		case 4:
		case 9:
		case 16:
		case 25:
		case 36:
		case 49:
		case 64:
		case 81: test_result = true;
			break;
		default: {
			test_result = false;
			break; 
		}
			break;
		}
	}

	if (test_result) std::cout << "Unit Test 2 : PASSED (Access using sqaure operator)\n";
	else {
		std::cout << "Unit Test 2 : FAILED (Access using sqaure operator)\n";
	}

	for (size_t index = test_size_const + 1;			// Initializing with out-of bounds index
		index < test_size_const * test_size_const;		// Some random loop limit
		index++) {
		
		try {
			test_container[index];
		}
		catch (std::out_of_range) {
			test_result = true;		// Program did throw exception.
			continue;				// Continue subsequent iterations.
		}
		
		test_result = false;		// Index out of bounds, didn't throw exception.
		break;						// Test failed. Stop subsequent iterations.
	}

	if (test_result) std::cout << "Unit Test 3 : PASSED (Index out of bounds check)\n";
	else {
		std::cout << "Unit Test 3 : FAILED (Index out of bounds check)\n";
	}

	std::cout << "Finished testing sqaure brackets operator\n";

}

void at_member() {

	std::cout << "\nTesting at( ) member function\n";

	//	Unit testing code goes here...

	std::cout << "Finished testing at( ) member function\n";

}

void testing::test_array() {

	// Consists of all the code for unit testing the array data structure.

	std::cout << "Array test module running.\n\n";
	square_operator();
	at_member();
	std::cout << "\nArray test module finished" << std::endl;
	
}