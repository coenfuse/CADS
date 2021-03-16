#include "testing.h"
#include "..\learn\learn.h"

int main() {

	// How to run this test?
	// ---------------------------------------
	// Just change the initialization parameter of test object creation to your
	// liking from the provided enumerated types and hit run. That would be it.

	learn::sorted_list<compound> compound_list;
	for (size_t i = 0; i < 20; i++) {
		compound_list.push(compound(rand() % 100));
	}
		
	for (size_t i = 0; i < 20; i++) {
		compound_list.at(i).print();
	}

	//testing test(test_type::learn_sorted_linked_list);
	//test.run();

}