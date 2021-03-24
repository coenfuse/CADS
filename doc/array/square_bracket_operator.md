# cads : : array : : operator [ index ]

Overloaded operator for index based addressing. This operator gives direct access to any of the data member present in the container at the specified index.
```sh
cads::array<type,size>array_container;
array_container[size_t index];
```

This operator doesn't incorporates bound checking and throws a **`std::out_of_range("Index out of valid range");`** exception whenever invalid index is given as input.

It is called two-way indexing operator (for the lack of better word) because with this we can access the data from the container as well as assign data to it.

```sh
#include <iostream>
#include "cads/array.h"
int main(){
	cads::array<int, 10> array_container;
	
	for(size_t i = 0; i < 10; i++){
		array_container[index] = (int)(index * index);		// Assigning value to container.
	}
	
	for(size_t i = 0; i < 10; i++){
		std::cout << array_container[index] << ",";	// Accessing value from container
	}
	
	return 0;
}
```
**Output :**
```sh
0,1,4,9,16,25,36,49,64,81
```

A constant variant of this operator is also available. It is automatically invoked when the container is initialized as a constant type.

**Example usage :**
```sh
#include <iostream>
#include "cads/array.h"
int main(){
    
    cads::array<int,10> var_array;              // Mutable Array
    const cads::array<int,10> const_array;      // Constant Array

    for(size_t index = 0; index < 10; index++){
        var_array[index] = index * index;           // This should work normally.
        const_array[index] = index * index;         // Compilation error. Must be modifiable lvalue.
    }

    for(size_t ele = 0; ele < 10; ele++){
        std::cout << var_array[index] << ", " << std::endl;
        std::cout << const_array[index] << ", " << std::endl;       // This should work normally.
    }

    return 0;
}
```
We need to use an initializer list like this:
`const cads::array<int,10> const_array = {1, 2, 3 ,4, 5}`
to initialize our container with the specified values.

_Functionality for automatic conversion of initializer list to array is scheduled for future updates._