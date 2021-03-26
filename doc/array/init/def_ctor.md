# cads : : array : : array ( )

Default constructor for **`cads::array`** container. It initializes the whole container with value 0 upon invocation.
Initialization takes linear time and can be omitted by removing the loop from constructor's definition.

```sh
#include <iostream>
#include "cads/array.h"

int main(){
	cads::array<int, 5> array_container;
	
	for(size_t i = 0; i < 10; i++){
		std::cout << array_container[index] << ", ";
	}

	return 0;
}
```

**Output :**
```sh
0, 0, 0, 0, 0,
```

We need to use an initializer list like this:
`const cads::array<int,10> const_array = {1, 2, 3 ,4, 5}`
to initialize our container with the specified values.

_Functionality for automatic conversion of initializer list to array is scheduled for future updates._