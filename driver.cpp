#include <iostream>
#include <string>
#include "learn\learn.h"
#include <chrono>

int main() {
	std::cout << "Driver Code" << std::endl;
	srand((unsigned int)time(nullptr));
	List<int>list,listr;
	for (int i = 0; i < 10; i++) {
		list.insert(rand()% 10000);
	}
	std::cout << (list.size() * 0.000001) << " Megabytes" << std::endl;
	list.display();
	list.trim_head(4);
	list.display();

	
	//if (list.palindrome()) {
		//std::cout << "It has a palindrome" << std::endl;
	//}
	//else
		//std::cout << "It doesn't have a palindrome" << std::endl;

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