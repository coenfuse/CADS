#pragma once

#include <chrono>
#include <thread>
#include <iostream>
#include <time.h>

class compound {

	// Custom data structure containing random variables of different types.
	// Just for testing purposes.

	bool m_boolean_var;
	float m_float_var;
	std::string m_str_var;
	int m_int_var;

public:

	compound() {

		srand((unsigned int)time_t(NULL) + rand());

		m_boolean_var = rand() % 2;
		m_float_var = (float)(rand() % 69);
		m_str_var = "XXX";
		m_int_var = rand() % 6969;

	}

	compound(int _init_data) {

		srand((unsigned int)time_t(NULL) + rand());

		m_boolean_var = rand() % 2;
		m_float_var = (float)(rand() % 69);
		m_str_var = "XXX";
		m_int_var = _init_data;

	}

	compound(float _init_float) {
		
		srand((unsigned int)time_t(NULL) + rand());

		m_boolean_var = rand() % 2;
		m_float_var = _init_float;
		m_str_var = "XXX";
		m_int_var = rand() % 6969;
	}

	compound(std::string& _init_str) {

		srand((unsigned int)time_t(NULL) + rand());

		m_boolean_var = rand() % 2;
		m_float_var = (float)(rand() % 69);
		m_str_var = _init_str;
		m_int_var = rand() % 6969;
	}

	~compound(){}

	bool operator == (compound& other) {
		
		// No particular reason why this is written this way.
		bool is_equal = false;

		if (this->m_boolean_var == other.m_boolean_var)
			if (this->m_float_var == other.m_float_var)
				if (this->m_int_var == other.m_int_var)
					if (this->m_str_var == other.m_str_var)
						is_equal = true;

		return is_equal;
	}

	bool operator != (compound& other) {
		return !(*this == other);			// Negating the previous overload
	}

	bool operator > (compound& other) {
		bool is_greater = false;
	
		// Keeping it simple
	
		if (this->m_int_var > other.m_int_var)
			is_greater = true;
	
		return is_greater;
	}

	bool operator < (compound& other) {
		return !(*this > other);			// Negating the previous overload
	}

	bool operator >= (compound& other) {
		bool is_greater = false;
	
		// Not comparing string and boolean members
	
		if (this->m_int_var >= other.m_int_var)
			is_greater = true;
	
		return is_greater;
	}

	bool operator <= (compound& other) {
		return !(*this >= other);			// Negating the previous overload.
	}

	void print() {
		if (this->m_boolean_var)
			std::cout << "Bool : True\n";
		else
			std::cout << "Bool : False\n";
		std::cout << "Float : " << this->m_float_var << "f\n";
		std::cout << "String : " << m_str_var << "\n";
		std::cout << "Int : " << this->m_int_var;
		std::cout << "\n\n";
	}
};

const static enum class test_type {
	learn_array,
	
	learn_single_linked_list,
	learn_double_linked_list,
	learn_sorted_linked_list,
};

const static enum class timer_type {
	nanoseconds,
	microseconds,
	milliseconds,
	seconds,
	minutes
};

class testing {

	static class Stopwatch {

		using time_type = std::chrono::time_point<std::chrono::steady_clock>;

		time_type m_start;
		time_type m_end;
		bool m_valid;

	public:

		Stopwatch() :
			m_start(std::chrono::high_resolution_clock::now()),
			m_end(std::chrono::high_resolution_clock::now()),
			m_valid(false)
		{}

		void start() {

			m_start = std::chrono::high_resolution_clock::now();
			m_valid = false;

		}

		void stop() {

			m_end = std::chrono::high_resolution_clock::now();
			m_valid = true;

		}

		unsigned int get_duration(timer_type type) {

			switch (type)
			{
			case timer_type::nanoseconds:
				return (unsigned int)(std::chrono::duration_cast<std::chrono::nanoseconds>(m_end - m_start).count());
				break;

			case timer_type::microseconds:
				return (unsigned int)(std::chrono::duration_cast<std::chrono::microseconds>(m_end - m_start).count());
				break;

			case timer_type::milliseconds:
				return (unsigned int)(std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start).count());
				break;

			case timer_type::seconds:
				return (unsigned int)(std::chrono::duration_cast<std::chrono::seconds>(m_end - m_start).count());
				break;

			case timer_type::minutes:
				return (unsigned int)(std::chrono::duration_cast<std::chrono::minutes>(m_end - m_start).count());
				break;
			}
		}

	};
	
	Stopwatch Timer;
	test_type type;

private:

	void test_learn_single_list();
	void test_learn_sorted_list();

	void test_cads_list();

public:

	testing(test_type _init_type) : type(_init_type) {}
	~testing(){}

	void run() {

		Timer.start();
		std::cout << "Test Running" << std::endl;
		Timer.stop();
		std::cout << Timer.get_duration(timer_type::microseconds) << std::endl;

	}

};


// Hot garbage. DONT READ

//srand((unsigned int)time(NULL));
	//learn::List<int> test;
	//for (size_t i = 0; i < 10; i++) {
	//	test.insert(rand() % 101);
	//}
	//test.display();
	//size_t var = 5;
	//
	//test.splice_to(3, 6);//.display();
	//test.display();
	//test.reverse();
	//test.display();

	// Snippet to test negative indexes
	/*
	srand((unsigned int)time(NULL));
	CADS::List<int> test;
	for (size_t i = 0; i < 5; i++) {
		test.push_back(rand() % 100);
	}

	test.display();
	for (short i = 0; i < test.size(); i++) {
		log(*test.at(i));
		log("\n");
	}

	log("\n\n");

	for (short i = -1; i >= (test.size() * -1); i--) {
		log(*test.at(i));
		log("\n");
	}

	log("\n");

	log("Using operator overloads");
	log("\n\n");

	for (short i = 0; i < test.size(); i++) {
		log(test[i]);
		log("\n");
	}

	log("\n\n");

	for (short i = -1; i >= (test.size() * -1); i--) {
		log(test[i]);
		log("\n");
	}
	// Testing out of bounds indexes
	//log(*test.at(-7));		// Returns list.end()
	//log(*test.at(100));		// Returns list.end()
	//log(test[-32]);			// Returns nullptr
	//log(test[76]);			// Returns nullptr
	*/


	// Snippet to compare sort()
	//std::cout << "Driver Code" << std::endl;
	////CADS::List<int> list = { 5,6,8 };
	//learn::List<int>sll;
	//std::list<int> std_list;
	//size_t counter = 0;
	//while (counter < 1000) {
	//	//list.push_back(rand());
	//	std_list.push_back(rand());
	//	counter++;
	//}
	//
	//auto sum = 0;
	//for (size_t i = 0; i < 100; i++) {
	//	auto beg = std::chrono::high_resolution_clock::now();
	//	//std_list.reverse();
	//	std_list.sort();
	//	auto fin = std::chrono::high_resolution_clock::now();
	//	auto std_dur = std::chrono::duration_cast<std::chrono::milliseconds>(fin - beg);
	//	sum += std_dur.count();
	//	std::system("cls");
	//	log("Sorting STL: ");
	//	log((int)i);
	//	log(" %");
	//}
	//log("\n\nSTL sort test complete now. Proceed to test sort of CADS?")
	//
	//std_list.clear();
	//
	//counter = 0;
	//while (counter < 1000) {
	//	//list.push_back(1000000 - counter);
	//	sll.insert(rand());
	//
	//	//std_list.push_back(rand());
	//	counter++;
	//}
	//std::cin.get();
	//
	//auto sums = 0;
	//for (size_t i = 0; i < 100; i++) {
	//	auto start = std::chrono::high_resolution_clock::now();
	//	//list.reverse();
	//	sll.sort();
	//	auto end = std::chrono::high_resolution_clock::now();
	//	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	//	sums += duration.count();
	//	std::system("cls");
	//	log("Sorting Learn: ");
	//	log((int)i);
	//	log(" %");
	//}
	//log("\n\nAverage time  by stl::list (in Microseconds) to sort a list of length 1 Million:");
	//log((float)sum / 100);
	//log("\nAverage time  by CADS::List (in Microseconds) to sort a list of length 1 Million:");
	//log((float)sums / 100);

// Pause current thread
// std::chrono::milliseconds dur(10);
// std::this_thread::sleep_for(dur);

// Test for execution time between list.add() and list.join()

/*
List <int> newList, secondList, thirdList, fourthList;
	for (int i = 0; i < 5; i++) {
		newList.insert(rand() % 100);
		secondList.insert(rand() & 100);
	}
	//std::cout << (newList.size() * 0.000001) << " Megabytes" << std::endl;
	auto start = std::chrono::high_resolution_clock::now();
	newList.add(secondList);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Addition of two lists took time of: "<<duration.count()<<" milliseconds"<<std::endl;
	newList.clear();
	secondList.clear();

	for (int i = 0; i < 1000000; i++) {
		thirdList.insert(rand() & 100);
		fourthList.insert(rand() & 100);
	}

	auto start2 = std::chrono::high_resolution_clock::now();
	thirdList.join(fourthList);
	auto end2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
	std::cout << "Joining of two lists took time of: " << duration2.count() << " milliseconds" << std::endl;

	std::cout << (thirdList.size() * 0.000001) << " Megabytes" << std::endl;
*/
