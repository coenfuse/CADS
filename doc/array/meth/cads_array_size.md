# cads : : array : : size ( )

 - **return type** : size_t
 - **time complexity** : constant

Member function that returns a total size occupied by the container in memory.

**Example usage :**
```sh
#include <iostream>
#include "cads/array.h"
int main(){
	cads::array<int, 10> container;
	for(size_t i = 0; i < 10; i++){
		array_container[index] = (int)(index * index);		// Assigning value to container.
	}

	std::cout << container.size() << " bytes";				// Output might vary on systems with different architecture
	return 0;
}
```
**Output :**
```sh
40 bytes
```