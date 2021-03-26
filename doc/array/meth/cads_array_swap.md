# cads : : array : : swap ( )

 - **return type** : void
 - **parameters** : size_t _index_A, size_t _index_B
 - **time complexity** : constant

Member function that swaps two elements residing at particular indexes inside the container.

**Example usage :**
```sh
#include <iostream>
#include "cads/array.h"
int main(){
	cads::array<int, 10> container;
	
	for(size_t i = 0; i < 10; i++){
		array_container[index] = (int)(index * index);		// Assigning value to container.
	}
	
	std::cout << "Unswapped Array" << std::endl;

	for(size_t i = 0; i < 10; i++){
		std::cout << array_container[index] << ",";
	}

	container.swap(3,8);

	std::cout << "\nAltered Array" << std::endl;

	for(size_t i = 0; i < 10; i++){
		std::cout << array_container[index] << ",";
	}
	return 0;
}
```
**Output :**
```sh
Unswapped Array
0,1,4,9,16,25,36,49,64,81,

Altered Array
0,1,4,64,16,25,36,49,9,81,
```

Since this method alters the contents inside of the container. It doesn't work when the container is initialized as constant type.