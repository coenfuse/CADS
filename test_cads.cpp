#include "test/test.h"

int main(){
	// How to run these tests?
	// ---------------------------------------
	// Just change the initialization parameter of test object creation to your
	// liking from the provided enumerated types and hit run. That would be it.

	testing test(TYPE::array);
	test.run();
}