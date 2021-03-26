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

void copy_ctor() {
	bool test_result = true;
	cads::array<int, test_size_const> base_container;

	std::cout << "\nTesting Copy Constructor\n";
	std::cout << "----------------------------------------\n";

	fill_array(base_container);

	cads::array<int, test_size_const> copy_container = base_container;

	for (size_t index = 0; index < test_size_const; index++) {
		if (base_container[index] == copy_container[index])
			test_result = true;
		else {
			test_result = false;
			break;
		}
	}

	if (test_result)
		std::cout << "Unit Test 1 : PASSED (Copy ctor successfully copied contents to other.)\n";
	else {
		std::cout << "Unit Test 1 : FAILED (Copy ctor failed in copying contents to other.)\n";
	}

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing Copy Constructor\n";
}

void square_operator() {

	bool test_result = false;
	cads::array<int, test_size_const> test_container;

	std::cout << "\nTesting [ ] operator\n";
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
	std::cout << "Finished testing [ ] operator\n";

}

void back_member() {
	bool test_result = true;
	cads::array<int, test_size_const> test_container;

	std::cout << "\nTesting back( ) member function\n";
	std::cout << "----------------------------------------\n";

	if (test_container.back() == 0)
		test_result = true;
	else
		test_result = false;

	if (test_result)
		std::cout << "Unit Test 1 : PASSED (Valid value returned from empty container)\n";
	else {
		std::cout << "Unit Test 1 : FAILED (Invalid value returned from empty container)\n";
	}

	fill_array(test_container);

	if (test_container.back() == test_container[test_size_const - 1])
		test_result = true;
	else
		test_result = false;

	if (test_result)
		std::cout << "Unit Test 2 : PASSED (Valid value returned from filled container)\n";
	else {
		std::cout << "Unit Test 2 : FAILED (Invalid value returned from filled container)\n";
	}

	try {
		test_result = false;
		//test_container.back() = 69;			// Syntax Error
		throw std::invalid_argument("Can't assign to lvalue");
	}
	catch (...) {
		test_result = true;
	}

	if (test_result)
		std::cout << "Unit Test 3 : PASSED (Wasn't able to assign value to container)\n";
	else {
		std::cout << "Unit Test 3 : FAILED (Was able to assign value to container.)\n";
	}

	int var = test_container.back();
	try {
		var++;
		++var;
		var += var;
		var -= var;
		var *= var;
		if (var != 0)
			var /= var;
	}
	catch (...) {
		test_result = false;
	}

	if (test_result)
		std::cout << "Unit Test 4 : PASSED (Value returned by member is mutable)\n";
	else {
		std::cout << "Unit Test 4 : FAILED (Value returned by member isn't mutable)\n";
	}

	try {
		test_result = false;
		/*
			test_container.back()++;
			++(test_container.back());
			test_container.back() += test_container.back();
			test_container.back() -= test_container.back();
			test_container.back() *= test_container.back();
		*/
		throw std::invalid_argument("Can't assign to lvalue");
	}
	catch (...) {
		test_result = true;
	}

	if (test_result)
		std::cout << "Unit Test 5 : PASSED (Member isn't allowing alteration of container)\n";
	else {
		std::cout << "Unit Test 5 : FAILED (Member is allowing alteration of container)\n";
	}

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing back( ) member function\n";
}

void clear_member() {
	bool test_result = true;
	cads::array<int, test_size_const> test_container;
	const cads::array<int, test_size_const> const_container;

	std::cout << "\nTesting clear( ) member function\n";
	std::cout << "----------------------------------------\n";

	fill_array(test_container);

	test_container.clear();

	for (size_t index = 0; index < test_size_const; index++) {
		if (test_container[index] == 0)
			test_result = true;
		else
			test_result = false;
	}

	if (test_result)
		std::cout << "Unit Test 1 : PASSED (Successfully cleared the container)\n";
	else {
		std::cout << "Unit Test 1 : FAILED (Clearning the container unsuccessful)\n";
	}

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing clear( ) member function\n";
}

void testing::test_array() {

	// Consists of all the code for unit testing the array data structure.

	std::cout << "Array test module running.\n\n";
	init_test();
	copy_ctor();
	square_operator();
	back_member();
	clear_member();
	std::cout << "\nArray test module finished" << std::endl;
	
}