# cads : : array : : array ( array<TYPE,SIZE>& )

- **time complexity** : O(n)

Default copy constructor for **`cads::array`** container. It initializes the newly created container with all the values of container that is being copied.
Initialization takes linear time. Since arrays have fixed size, both the arrays should have same type and size. No conversion exists as of now.

```sh
#include <iostream>
#include "cads/array.h"

int main(){
	cads::array<int, 5> array_container;

	for(size_t i = 0; i < 5; i++){
		array_container[index] = (int)(index * index);		// Assigning value to container.
	}

	cads::array<int, 5> copy_container = array_container;

	for(size_t i = 0; i < 5; i++){
		std::cout << copy_container[index] << ", ";
	}

	return 0;
}
```

**Output :**
```sh
0, 1, 4, 9, 16,
```