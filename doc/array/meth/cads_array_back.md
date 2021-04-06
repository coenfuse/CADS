# cads : : array : : back ( )

 - **return type** : [CONST_REF](../member_types.md)
 - **time complexity** : constant

Member function that returns a constant reference to element stored at the last index of the container.

**Example usage :**
```sh
#include <iostream>
#include "cads/array.h"
int main(){
	cads::array<int, 10> container;
	for(size_t i = 0; i < 10; i++){
		array_container[index] = (int)(index * index);		// Assigning value to container.
	}

	std::cout << container.back();
	return 0;
}
```
**Output :**
```sh
81
```

**`back()`** returns a constant reference to the element to prevent assingment operations using the returned reference.

## Removing back( )