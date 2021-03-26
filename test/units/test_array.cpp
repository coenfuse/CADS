#include <iostream>
#include "../test.h"
#include <array>

const size_t test_size_const = 10;
void fill_array(cads::array<int, test_size_const>& _to_fill, bool fill_with_zero = false) {
	for (size_t index = 0; index < test_size_const; index++) {
		if (fill_with_zero)
			_to_fill[index] = 0;
		else
			_to_fill[index] = rand() % 1000;
	}
}

void init_test(){
	bool test_result = true;
	cads::array<int, test_size_const> test_container;

	std::cout << "Testing Initialization\n";
	std::cout << "----------------------------------------\n";

	for (size_t index = 0; index < test_size_const; index++) {
		if (test_container[index] == 0)
			test_result = true;
		else
			test_result = false;
	}

	if (test_result)
		std::cout << "Unit Test 1 : PASSED (Container initialized with 0)\n";
	else {
		std::cout << "Unit Test 1 : FAILED (Container filled with garbage values)\n";
	}

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing initialization\n";
}

void square_operator() {
	
	bool test_result = false;
	cads::array<int, test_size_const> test_container;

	std::cout << "\nTesting square brackets operator\n";
	std::cout << "----------------------------------------\n";

	for (size_t index = 0; index < test_size_const; index++) {
		try {
			test_container[index] = (int)(index * index);
		}
		catch (...) {
			test_result = false;
			break;
		}
		test_result = true;
	}

	if (test_result) std::cout << "Unit Test 1 : PASSED (Could assign using square operator)\n";
	else {
		std::cout << "Unit Test 1 : FAILED (Couldn't assign using square operator)\n";
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

	if (test_result) std::cout << "Unit Test 2 : PASSED (Could access using sqaure operator)\n";
	else {
		std::cout << "Unit Test 2 : FAILED (Couldn't access using sqaure operator)\n";
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

	if (test_result) std::cout << "Unit Test 3 : PASSED (Thrown exception for invalid index)\n";
	else {
		std::cout << "Unit Test 3 : FAILED (Didn't throw exception for invalid index)\n";
	}

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing sqaure brackets operator\n";

}

void testing::test_array() {

	// Consists of all the code for unit testing the array data structure.

	std::cout << "Array test module running.\n\n";
	init_test();
	square_operator();
	std::cout << "\nArray test module finished" << std::endl;
	
}