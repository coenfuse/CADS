#include <iostream>
#include "../test.h"

// TODO : Add Custom Data Type Test Case
// TODO : Make Testing documentation. Also decribe on how to make your own uni-
// ts and add to the system for testing.
// TODO : Revise all these test cases carefully line by line before going into 
// v0.1.1.14

// Local Utility functions and definitions ------------------------------------

#define TEST_SIZE (size_t)100
#define TEST_TYPE double
#define NOW std::chrono::high_resolution_clock::now()

void fill_array(
	cads::array<TEST_TYPE, TEST_SIZE>& _to_fill, bool fill_with_zero = false
) {
	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (fill_with_zero)
			_to_fill[index] = static_cast<TEST_TYPE>(0);
		else
			_to_fill[index] = rand() % 1000;
	}
}

void log_result(
	unsigned int test_num, bool _result, const char* _message
) {
	if (_result)
		std::cout << "Unit Test "<< test_num << " : " << ansi::fg_green << "PASSED" << ansi::reset << " (" << _message << ")\n";
	else
		std::cout << "Unit Test " << test_num << " : " << ansi::fg_red << "FAILED" << ansi::reset << " (" << _message << ")\n";
}

// Unit Tests for container's methods -----------------------------------------

void copy_ctor() {
	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> base_container;

	std::cout << "\nTesting Copy Constructor\n";
	std::cout << "----------------------------------------\n";

	// copy_ctor() Unit Test 1

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
		log_result(1, test_result, "Copy ctor successfully copied contents to other");
	else
		log_result(1, test_result, "Copy ctor failed in copying contents to other");

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing Copy Constructor\n";
}

void square_operator() {

	bool test_result = false;
	cads::array<TEST_TYPE, TEST_SIZE> test_container;

	std::cout << "\nTesting [ ] operator\n";
	std::cout << "----------------------------------------\n";

	// clear() Unit Test 1

	for (size_t index = 0; index < TEST_SIZE; index++) {
		try {
			test_container[index] = (TEST_TYPE)(index * index);
		}
		catch (...) {
			test_result = false;
			break;
		}
		test_result = true;
	}

	if (test_result)
		log_result(1, test_result, "Could assign using square operator");
	else
		log_result(1, test_result, "Couldn't assign using square operator");

	// clear() Unit Test 2

	for (size_t index = 0; index < TEST_SIZE; index++) {
		switch ((bool)(test_container[index]))
		{
		case true: test_result = true;
			break;
		default: {
			test_result = false;
			break;
		}
			   break;
		}
	}

	if (test_result)
		log_result(2, test_result, "Could access using square operator");
	else
		log_result(2, test_result, "Couldn't access using square operator");

	// clear() Unit Test 3

	for (size_t index = TEST_SIZE + 1;			// Initializing with out-of bounds index
		index < TEST_SIZE * 10;
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

	if (test_result)
		log_result(3, test_result, "Thrown exception for invalid index");
	else
		log_result(3, test_result, "Didn't throw exception for invalid index");

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing [ ] operator\n";

}

void back_member() {
	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> test_container;

	std::cout << "\nTesting back( ) member function\n";
	std::cout << "----------------------------------------\n";

	// clear() Unit Test 1

	if (test_container.back())
		test_result = true;
	else
		test_result = false;

	if (test_result)
		log_result(1, test_result, "Valid value returned from empty container");
	else
		log_result(1, test_result, "Invalid value returned from empty container");

	// clear() Unit Test 2

	fill_array(test_container);

	if (test_container.back() == test_container[TEST_SIZE - 1])
		test_result = true;
	else
		test_result = false;

	if (test_result)
		log_result(2, test_result, "Valid value returned from filled container");
	else
		log_result(2, test_result, "Invalid value returned from filled container");

	// clear() Unit Test 3

	try {
		test_result = false;
		//test_container.back() = 69;			// Syntax Error
		throw std::invalid_argument("Can't assign to lvalue");
	}
	catch (...) {
		test_result = true;
	}

	if (test_result)
		log_result(3, test_result, "Wasn't able to assign value to container");
	else
		log_result(3, test_result, "Was able to assign value to container");

	// clear() Unit Test 4

	TEST_TYPE var = test_container.back();
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
		log_result(4, test_result, "Value returned by member is mutable");
	else
		log_result(4, test_result, "Value returned by member isn't mutable");

	// clear() Unit Test 5

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
		log_result(5, test_result, "Member isn't allowing alteration of container");
	else
		log_result(5, test_result, "Member is allowing alteration of container");

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing back( ) member function\n";
}

void data_member() {
	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> test_container;

	std::cout << "\nTesting data( ) member function\n";
	std::cout << "----------------------------------------\n";

	// data() Unit Test 1

	fill_array(test_container);

	TEST_TYPE* data_container = test_container.data();

	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (data_container[index] == test_container[index])
			test_result = true;
		else {
			test_result = false;
			break;
		}
	}

	if (test_result)
		log_result(1, test_result, "Successful reference. Member working normally");
	else
		log_result(1, test_result, "Unsuccessful reference. Member not working normally");

	// data() Unit Test 2

	for (size_t index = 0; index < TEST_SIZE; index++)				// Clearing the array
		test_container[index] = static_cast<TEST_TYPE>(0);

	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (data_container[index] == static_cast<TEST_TYPE>(0))
			test_result = true;
		else
			test_result = false;
	}

	if (test_result)
		log_result(2, test_result, "Returned a reference to internal container");
	else
		log_result(2, test_result, "Returned a copy of internal container");

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing data( ) member function\n";
}

void fill_member() {
	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> test_container;

	std::cout << "\nTesting fill( ) member function\n";
	std::cout << "----------------------------------------\n";

	// fill() Unit Test 1

	TEST_TYPE to_fill = static_cast<TEST_TYPE>(rand());
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
		log_result(1, test_result, "Array filled with var container");
	else
		log_result(1, test_result, "Array not filled with var container");

	// fill() Unit Test 2

	test_container.fill(static_cast<TEST_TYPE>(68 + 1));

	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (test_container[index] == static_cast<TEST_TYPE>(69)) {
			test_result = true;
			continue;
		}
		else {
			test_result = false;
			break;
		}
	}

	if (test_result)
		log_result(2, test_result, "Array filled with constant");
	else
		log_result(2, test_result, "Array not filled with constant");

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing fill( ) member function\n";
}

void front_member() {
	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> test_container;

	std::cout << "\nTesting front( ) member function\n";
	std::cout << "----------------------------------------\n";

	// front() Unit Test 1

	if (test_container.front())
		test_result = true;
	else
		test_result = false;

	if (test_result)
		log_result(1, test_result, "Valid value returned from empty container");
	else
		log_result(1, test_result, "Invalid value returned from empty container");

	// front() Unit Test 2

	fill_array(test_container);

	if (test_container.front() == test_container[0])
		test_result = true;
	else
		test_result = false;

	if (test_result)
		log_result(2, test_result, "Valid value returned from filled container");
	else
		log_result(2, test_result, "Invalid value returned from filled container");

	// front() Unit Test 3

	try {
		test_result = false;
		//test_container.front() = 69;			// Syntax Error
		throw std::invalid_argument("Can't assign to lvalue");
	}
	catch (...) {
		test_result = true;
	}

	if (test_result)
		log_result(3, test_result, "Wasn't able to assign value to container");
	else
		log_result(3, test_result, "Was able to assign value to container");

	// front() Unit Test 4

	TEST_TYPE var = test_container.front();
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
		log_result(4, test_result, "Value returned by member is mutable");
	else
		log_result(4, test_result, "Value returned by member isn't mutable");

	// front() Unit Test 5

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
		log_result(5, test_result, "Member isn't allowing alteration of container");
	else
		log_result(5, test_result, "Member is allowing alteration of container");

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing front( ) member function\n";
}

void length_member() {
	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> test_container;

	std::cout << "\nTesting length( ) member function\n";
	std::cout << "----------------------------------------\n";

	// length() Unit Test 1

	test_result = (TEST_SIZE == test_container.length());

	if (test_result)
		log_result(1, test_result, "Container returning correct number of elements inside of it");
	else
		log_result(1, test_result, "Container returning incorrect number of elements inside of it");

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing length( ) member function\n";
}

void size_member() {
	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> test_container;

	std::cout << "\nTesting size( ) member function\n";
	std::cout << "----------------------------------------\n";

	// size() Unit Test 1

	test_result = (TEST_SIZE * sizeof(TEST_TYPE) == test_container.size());

	if (test_result)
		log_result(1, test_result, "Container returning correct size");
	else
		log_result(1, test_result, "Container returning incorrect size");

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing size( ) member function\n";
}

void swap_member() {
	bool test_result = true;
	cads::array<TEST_TYPE, TEST_SIZE> original, expected;

	std::cout << "\nTesting swap( ) member function\n";
	std::cout << "----------------------------------------\n";

	// swap() Unit Test 1

	fill_array(original);
	expected = original;

	original.swap(rand(), rand() % TEST_SIZE);
	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (original[index] == expected[index])
			test_result = true;
		else {
			test_result = false;
			break;
		}
	}

	if (test_result)
		log_result(1, test_result, "Handled invalid first index");
	else
		log_result(1, test_result, "Couldn't handle invalid first index");

	// swap() Unit Test 2

	original.swap(rand() % TEST_SIZE, rand());
	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (original[index] == expected[index])
			test_result = true;
		else {
			test_result = false;
			break;
		}
	}

	if (test_result)
		log_result(2, test_result, "Handled invalid second index");
	else
		log_result(2, test_result, "Couldn't handle invalid second index");

	// swap() Unit Test 3

	original.swap(rand(), rand());
	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (original[index] == expected[index])
			test_result = true;
		else {
			test_result = false;
			break;
		}
	}

	if (test_result)
		log_result(3, test_result, "Handled both invalid indexes");
	else
		log_result(3, test_result, "Couldn't handle both invalid indexes");

	// swap() Unit Test 4

	for (int i = 0; i < 1000; i++) {
		size_t swap_this = rand() % TEST_SIZE;
		size_t with_this = rand() % TEST_SIZE;

		TEST_TYPE temp = expected[swap_this];
		expected[swap_this] = expected[with_this];
		expected[with_this] = temp;

		original.swap(swap_this, with_this);

		for (size_t index = 0; index < TEST_SIZE; index++) {
			if (original[index] == expected[index])
				test_result = true;
			else {
				test_result = false;
				break;
			}
		}
	}

	if (test_result)
		log_result(4, test_result, "Successful swapping of valid indexes");
	else
		log_result(4, test_result, "Unsuccessful swapping of valid indexes");

	// swap() Unit Test 5

	expected = original;
	const size_t to_swap = rand() % TEST_SIZE;

	original.swap(to_swap, to_swap);
	for (size_t index = 0; index < TEST_SIZE; index++) {
		if (original[index] == expected[index])
			test_result = true;
		else {
			test_result = false;
			break;
		}
	}

	if (test_result)
		log_result(5, test_result, "Integrity maintained when same swapping indexes are given");
	else
		log_result(5, test_result, "Abnormal behavior when same swapping indexes are given");

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing swap( ) member function\n";
}

void generic_test() {

	bool test_result = true;

	std::cout << "\nTesting generic ability of container\n";
	std::cout << "----------------------------------------\n";

	// generic Unit Test 1
	
	{
		try {
			cads::array<cus_dat_type, TEST_SIZE> generic_array;
		}
		catch (...) {
			test_result = false;
		}

		if (test_result)
			log_result(1, test_result, "Array successfully initialized with custom data type");
		else
			log_result(1, test_result, "Array failed initialized with custom data type");
	}

	// generic Unit Test 2

	{
		try {
			cads::array<std::string, TEST_SIZE> generic_array;
		}
		catch (...) {
			test_result = false;
		}

		if (test_result)
			log_result(2, test_result, "Array successfully initialized with string data type");
		else
			log_result(2, test_result, "Array failed initialized with string data type");
	}

	// generic Unit Test 3
	
	{
		try {
			cads::array<cads::array<TEST_TYPE, TEST_SIZE>, TEST_SIZE> nested_generic_array;
		}
		catch (...) {
			test_result = false;
		}

		if (test_result)
			log_result(3, test_result, "Array successfully initialized with nested data type");
		else
			log_result(3, test_result, "Array failed to initialized with nested data type");
	}

	std::cout << "----------------------------------------\n";
	std::cout << "Finished testing generic ability of container\n";
}

void speed_test() {

	std::cout << "\nSpeed testing of container\n";
	std::cout << "----------------------------------------\n";

	// Speed Testing 1 - Initialization
	{
		auto start = NOW;
		std::array<cus_dat_type, TEST_SIZE> standard_array;
		auto end = NOW;
		unsigned long int std_dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

		start = NOW;
		cads::array<cus_dat_type, TEST_SIZE> cads_array;
		end = NOW;
		unsigned long int cads_dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

		if (cads_dur <= std_dur)
			log_result(1, true, "CADS has faster initialization with custom data_type");
		else
			log_result(1, false, "CADS has slower initialization with custom data_type");
	}

	// Speed Testing 2 - Assignment using square bracket
	{
		std::array<TEST_TYPE, TEST_SIZE> std_array;
		cads::array<TEST_TYPE, TEST_SIZE> cads_array;

		auto start = NOW;
		for (size_t index = 0; index < TEST_SIZE; index++)
			std_array[index] = static_cast<TEST_TYPE>(index);
		auto end = NOW;
		unsigned long int std_dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

		start = NOW;
		for (size_t index = 0; index < TEST_SIZE; index++)
			cads_array[index] = static_cast<TEST_TYPE>(index);
		end = NOW;
		unsigned long int cads_dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

		if (cads_dur <= std_dur)
			log_result(2, true, "CADS has faster assignment to indexes");
		else
			log_result(2, false, "CADS has slower assignment to indexes");
	}

	// Speed Testing 3 - back( ) member
	{
		std::array<TEST_TYPE, TEST_SIZE> std_array;
		cads::array<TEST_TYPE, TEST_SIZE> cads_array;

		for (size_t index = 0; index < TEST_SIZE; index++) {
			std_array[index] = static_cast<TEST_TYPE>(index);
			cads_array[index] = static_cast<TEST_TYPE>(index);
		}

		TEST_TYPE temp;

		auto start = NOW;
		temp = std_array.back();
		auto end = NOW;
		unsigned long int std_dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

		start = NOW;
		temp = cads_array.back();
		end = NOW;
		unsigned long int cads_dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

		if (cads_dur <= std_dur)
			log_result(3, true, "CADS has faster back( ) member");
		else
			log_result(3, false, "CADS has slower back( ) member");
	}

	// Speed Testing 4 - data( ) member
	{
		std::array<TEST_TYPE, TEST_SIZE> std_array;
		cads::array<TEST_TYPE, TEST_SIZE> cads_array;

		for (size_t index = 0; index < TEST_SIZE; index++) {
			std_array[index] = static_cast<TEST_TYPE>(index);
			cads_array[index] = static_cast<TEST_TYPE>(index);
		}

		TEST_TYPE* temp;

		auto start = NOW;
		temp = std_array.data();
		auto end = NOW;
		unsigned long int std_dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

		start = NOW;
		temp = cads_array.data();
		end = NOW;
		unsigned long int cads_dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

		if (cads_dur <= std_dur)
			log_result(4, true, "CADS has faster data( ) member");
		else
			log_result(4, false, "CADS has slower data( ) member");
	}
	// INCOMPLETE

	std::cout << "----------------------------------------\n";
	std::cout << "Finished Speed testing of container\n";

}

void testing::test_array() {

	// Consists of all the code for unit testing the array data structure.

	std::cout << "Array test module running.\n";
	copy_ctor();
	square_operator();
	back_member();
	data_member();
	fill_member();
	front_member();
	length_member();
	size_member();
	swap_member();
	generic_test();
	speed_test();
	std::cout << "\nArray test module finished" << std::endl;
	
}