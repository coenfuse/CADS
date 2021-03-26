# cads : : array : : is_empty ( )

 - **return type** : bool
 - **time complexity** : O(n)

Member function that returns a bool value depicting whether the container is empty or not.
In terms of cads::array, empty means having all the elements inside the container as 0.
'is_empty()' iterates over the whole container and checks whether all the indexes contain value 0 in them.
Return true if they do or false if they don't.

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

	for(size_t index = 0; index < 10; index++){
		std::cout << container[index] << ",";
	}

	if(container.is_empty())
		std::cout << "\nContainer is empty" << std::endl;
	else
		std::cout << "\nContainer is not empty" << std::endl;

	// Altering the container
	container.clear();

	if(container.is_empty())
		std::cout << "Container is empty" << std::endl;
	else
		std::cout << "Container is not empty" << std::endl;
	
	for(size_t index = 0; index < 10; index++){
		std::cout << container[index] << ",";
	}
	
	return 0;
}
```
**Output :**
```sh
0,10,20,30,40,50,60,70,80,90,
Container is not empty
Container is empty
0,0,0,0,0,0,0,0,0,0,
```

**This member function is marked as experimental because it counts 0 as an empty value. So, it gives a false positive if the array is actually filled with 0's only.** _I'm in a search of better alternative than checking for zeros, the container will be updated in future for the same._