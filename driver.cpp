#include <iostream>
#include <string>
#include "learn\learn.h"
#include"include/ds.h"
#include <chrono>
#include <list>
#define log(x) std::cout<<x<< std::endl;

int main() {
	std::cout << "Driver Code" << std::endl;
	srand((unsigned int)time(NULL));
	learn::List<int> test_list;
	std::list<int> std_list;
	for (int i = 1; i < 100000; i++) {
		test_list.insert(rand() % 9000);
		std_list.push_back(rand() % 9000);
	}
	
	auto start = std::chrono::high_resolution_clock::now();
	test_list.sort(0);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	log(duration.count());

	auto stdstart = std::chrono::high_resolution_clock::now();
	std_list.sort();
	auto stdend = std::chrono::high_resolution_clock::now();
	auto stdduration = std::chrono::duration_cast<std::chrono::microseconds>(stdend - stdstart);
	log(stdduration.count());
}

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