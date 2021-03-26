# cads : : array : : data ( )

 - **return type** : [PTR](../member_types.md)
- **time complexity** : constant

Member function that returns a pointer to the internal container of the array.
It basically sends the address of the first element inside of the internal container. Furthermore, it sends a pointer to internal container and not a copy of the container itself.
Any alteration to the container after returning its pointer to some pointer variable will be reflected on whenver an access to the container is made using the pointer.

**Example usage :**
```sh
#include <iostream>
#include "cads/array.h"
int main(){
	cads::array<int, 10> container;
	
	// Filling the container
	for(size_t index = 0; index < 10; index++){
		container[index] = (int)(index * 10);
	}

	int* ptr_container = container.data();

	// The following code will print contents inside of the container
	for(size_t index = 0; index < 10; index++){
		std::cout << ptr_container[index] << ",";
	}

	// Altering the original container
	container.clear();
	std::cout <<"\n";

	// Now the following loop will print zeroes even though we didn't touch the ptr_container
	for(size_t index = 0; index < 10; index++){
		std::cout << ptr_container[index] << ",";
	}
	
	return 0;
}
```
**Output :**
```sh
0,10,20,30,40,50,60,70,80,90,
0,0,0,0,0,0,0,0,0,0,
```