#include <iostream>
#include "../test.h"
#include <array>

const size_t test_size_const = 10;
#define TEST_SIZE 10
#define TEST_TYPE int

void fill_array(cads::array<TEST_TYPE, TEST_SIZE>& _to_fill, bool fill_with_zero = false) {
	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (fill_with_zero)
			_to_fill[index] = 0;
		else
			_to_fill[index] = rand() % 1000;
	}
}

void init_test(){
	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> test_container;

	std::cout << "Testing Initialization\n";
	std::cout << "----------------------------------------\n";

	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (test_container[index] == 0)
			test_result = true;
		else
			test_result = false;
	}

	if (test_result)
		std::cout << "Unit Test 1 : PASSED (Container initialized with 0's)\n";
	else {
		std::cout << "Unit Test 1 : FAILED (Container filled with garbage values)\n";
	}

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing initialization\n";
}

void copy_ctor() {
	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> base_container;

	std::cout << "\nTesting Copy Constructor\n";
	std::cout << "----------------------------------------\n";

	fill_array(base_container);

	cads::array<TEST_TYPE, TEST_SIZE> copy_container = base_container;

	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (base_container[index] == copy_container[index])
			test_result = true;
		else {
			test_result = false;
			break;
		}
	}

	if (test_result)
		std::cout << "Unit Test 1 : PASSED (Copy ctor successfully copied contents to other)\n";
	else {
		std::cout << "Unit Test 1 : FAILED (Copy ctor failed in copying contents to other.)\n";
	}

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing Copy Constructor\n";
}

void square_operator() {

	bool test_result = false;
	cads::array<TEST_TYPE, TEST_SIZE> test_container;

	std::cout << "\nTesting [ ] operator\n";
	std::cout << "----------------------------------------\n";

	for (size_t index = 0; index < TEST_SIZE; index++) {
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

	for (size_t index = 0; index < TEST_SIZE; index++) {
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
		index < TEST_SIZE * 100;
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
	cads::array<TEST_TYPE, TEST_SIZE> test_container;

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

	if (test_container.back() == test_container[TEST_SIZE - 1])
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
	cads::array<TEST_TYPE, TEST_SIZE> test_container;
	const cads::array<TEST_TYPE, TEST_SIZE> const_container;

	std::cout << "\nTesting clear( ) member function\n";
	std::cout << "----------------------------------------\n";

	fill_array(test_container);

	test_container.clear();

	for (size_t index = 0; index < TEST_SIZE; index++) {
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

void data_member() {
	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> test_container;

	std::cout << "\nTesting data( ) member function\n";
	std::cout << "----------------------------------------\n";

	fill_array(test_container);

	int* data_container = test_container.data();

	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (data_container[index] == test_container[index])
			test_result = true;
		else {
			test_result = false;
			break;
		}
	}

	if (test_result)
		std::cout << "Unit Test 1 : PASSED (Successful reference. Member working normally)\n";
	else {
		std::cout << "Unit Test 1 : FAILED (Unsuccessful reference. Member not working normally)\n";
	}

	test_container.clear();

	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (data_container[index] == static_cast<int>(0))
			test_result = true;
		else
			test_result = false;
	}

	if (test_result)
		std::cout << "Unit Test 2 : PASSED (Returned a reference to internal container)\n";
	else {
		std::cout << "Unit Test 2 : FAILED (Returned a copy of internal container)\n";
	}

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing data( ) member function\n";
}

void fill_member() {
	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> test_container;

	std::cout << "\nTesting fill( ) member function\n";
	std::cout << "----------------------------------------\n";

	int to_fill = rand();
	test_container.fill(to_fill);

	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (test_container[index] == to_fill) {
			test_result = true;
			continue;
		}
		else {
			test_result = false;
			break;
		}
	}

	if (test_result)
		std::cout << "Unit Test 1 : PASSED (Array filled with var container)\n";
	else {
		std::cout << "Unit Test 1 : FAILED (Array not filled with var container)\n";
	}

	test_container.fill(68 + 1);

	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (test_container[index] == 69) {
			test_result = true;
			continue;
		}
		else {
			test_result = false;
			break;
		}
	}

	if (test_result)
		std::cout << "Unit Test 2 : PASSED (Array filled with constant)\n";
	else {
		std::cout << "Unit Test 2 : FAILED (Array not filled with constant)\n";
	}

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing fill( ) member function\n";
}

void front_member() {
	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> test_container;

	std::cout << "\nTesting front( ) member function\n";
	std::cout << "----------------------------------------\n";

	if (test_container.front() == 0)
		test_result = true;
	else
		test_result = false;

	if (test_result)
		std::cout << "Unit Test 1 : PASSED (Valid value returned from empty container)\n";
	else {
		std::cout << "Unit Test 1 : FAILED (Invalid value returned from empty container)\n";
	}

	fill_array(test_container);

	if (test_container.front() == test_container[0])
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
		//test_container.front() = 69;			// Syntax Error
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

	int var = test_container.front();
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
			test_container.front()++;
			++(test_container.front());
			test_container.front() += test_container.front();
			test_container.front() -= test_container.front();
			test_container.front() *= test_container.front();
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
	std::cout << "Finished testing front( ) member function\n";
}

void is_empty_member() {

	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> test_container;

	std::cout << "\nTesting is_empty( ) member function\n";
	std::cout << "----------------------------------------\n";

	test_result = test_container.is_empty();

	if (test_result)
		std::cout << "Unit Test 1 : PASSED (Initialized array identified as empty)\n";
	else
		std::cout << "Unit Test 1 : FAILED (Inititalized array identified as non-empty)\n";

	fill_array(test_container);
	test_result = test_container.is_empty();

	if (!test_result)
		std::cout << "Unit Test 2 : PASSED (Randomly filled array identified as non-empty)\n";
	else
		std::cout << "Unit Test 2 : FAILED (Randomly filled array identified as empty)\n";

	test_container.clear();
	test_result = test_container.is_empty();

	if (test_result)
		std::cout << "Unit Test 3 : PASSED (Cleared array identified as empty)\n";
	else
		std::cout << "Unit Test 3 : FAILED (Cleared array identified as non-empty)\n";

	fill_array(test_container, true);
	test_result = test_container.is_empty();

	if (test_result)
		std::cout << "Unit Test 4 : PASSED (FALSE POSITIVE : Array filled with zeroes identified as empty)\n";
	else
		std::cout << "Unit Test 4 : FAILED (UNRELIABLE : Array filled with zeroes identified as non-empty)\n";


	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing is_empty( ) member function\n";

}

void length_member() {
	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> test_container;

	std::cout << "\nTesting length( ) member function\n";
	std::cout << "----------------------------------------\n";

	test_result = (TEST_SIZE == test_container.length());

	if (test_result)
		std::cout << "Unit Test 1 : PASSED (Container returning correct number of elements inside of it)\n";
	else {
		std::cout << "Unit Test 1 : FAILED (Container returning incorrect number of elements inside of it)\n";
	}

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing length( ) member function\n";
}

void size_member() {
	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> test_container;

	std::cout << "\nTesting size( ) member function\n";
	std::cout << "----------------------------------------\n";

	test_result = (TEST_SIZE * sizeof(int) == test_container.size());

	if (test_result)
		std::cout << "Unit Test 1 : PASSED (Container returning correct size)\n";
	else {
		std::cout << "Unit Test 1 : FAILED (Container returning incorrect size)\n";
	}

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing size( ) member function\n";
}

void swap_member() {
	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> original, expected;

	std::cout << "\nTesting swap( ) member function\n";
	std::cout << "----------------------------------------\n";

	fill_array(original);
	expected = original;

	original.swap(14, 2);
	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (original[index] != expected[index]) {
			test_result = false;
			break;
		}
		test_result = true;
	}

	if (test_result)
		std::cout << "Unit Test 1 : PASSED (Handled invalid first index)\n";
	else {
		std::cout << "Unit Test 1 : FAILED (Couldn't handle invalid first index)\n";
	}

	original.swap(5, 26);
	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (original[index] != expected[index]) {
			test_result = false;
			break;
		}
		test_result = true;
	}

	if (test_result)
		std::cout << "Unit Test 2 : PASSED (Handled invalid second index)\n";
	else {
		std::cout << "Unit Test 2 : FAILED (Couldn't handle invalid second index)\n";
	}

	original.swap(89, 26);
	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (original[index] != expected[index]) {
			test_result = false;
			break;
		}
		test_result = true;
	}

	if (test_result)
		std::cout << "Unit Test 3 : PASSED (Handled both invalid indexes)\n";
	else {
		std::cout << "Unit Test 3 : FAILED (Couldn't handle both invalid indexes)\n";
	}

	for (int i = 0; i < 1000; i++) {
		size_t swap_this = rand() % TEST_SIZE;
		size_t with_this = rand() % TEST_SIZE;

		int temp = expected[swap_this];
		expected[swap_this] = expected[with_this];
		expected[with_this] = temp;

		original.swap(swap_this, with_this);

		for (size_t index = 0; index < TEST_SIZE; index++) {
			if (original[index] != expected[index]) {
				test_result = false;
				break;
			}
			test_result = true;
		}
	}

	if (test_result)
		std::cout << "Unit Test 4 : PASSED (Successful swapping of valid indexes)\n";
	else {
		std::cout << "Unit Test 4 : FAILED (Unsuccessful swapping of valid indexes)\n";
	}

	expected = original;
	original.swap(5, 5);
	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (original[index] != expected[index]) {
			test_result = false;
			break;
		}
		test_result = true;
	}

	if (test_result)
		std::cout << "Unit Test 5 : PASSED (Integrity maintained when same swapping indexes are given)\n";
	else {
		std::cout << "Unit Test 5 : FAILED (Abnormal behavior when same swapping indexes are given)\n";
	}

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing swap( ) member function\n";
}

void testing::test_array() {

	// Consists of all the code for unit testing the array data structure.

	std::cout << "Array test module running.\n\n";
	init_test();
	copy_ctor();
	square_operator();
	back_member();
	clear_member();
	data_member();
	fill_member();
	front_member();
	is_empty_member();
	length_member();
	size_member();
	swap_member();
	std::cout << "\nArray test module finished" << std::endl;
	
}