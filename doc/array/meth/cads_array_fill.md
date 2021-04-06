# cads : : array : : fill ( )

 - **return type** : void
 - **parameters** : [CONST_REF](../member_types.md) val_to_fill
 - **time complexity** : O(n)

Member function that fills the array container with the specified parameter.

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

	container.fill(69);

	std::cout << "\nFilled / Overwritten Array" << std::endl;

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

Filled / Overwritten Array
69,69,69,69,69,69,69,69,69,69,
```

Since this method alters the contents inside of the container. It doesn't work when the container is initialized as constant type.

## Removing fill( )