# cads : : array : : clear ( )

 - **return type** : void
 - **time complexity** : O(n)

Member function that clears the array container by filling it with zeroes.
The zeroes used to overwrite the whole array are static_cast to initializtion type as : **`static_cast<TYPE>(0);`**

**Example usage :**
```sh
#include <iostream>
#include "cads/array.h"
int main(){
	cads::array<int, 10> container;
	
	for(size_t i = 0; i < 10; i++){
		array_container[index] = (int)(index * index);		// Assigning value to container.
	}
	
	std::cout << "Filled Array" << std::endl;

	for(size_t i = 0; i < 10; i++){
		std::cout << array_container[index] << ",";
	}

	container.clear();

	std::cout << "\nCleared Array" << std::endl;

	for(size_t i = 0; i < 10; i++){
		std::cout << array_container[index] << ",";
	}
	return 0;
}
```
**Output :**
```sh
Filled Array
0,1,4,9,16,25,36,49,64,81,

Cleared Array
0,0,0,0,0,0,0,0,0,0,
```

Since this method alters the contents inside of the container. It doesn't work when the container is initialized as constant type.