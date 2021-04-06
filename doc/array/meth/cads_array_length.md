# cads : : array : : length ( )

 - **return type** : size_t
 - **time complexity** : constant

Member function that returns a total number elements the container can hold.

**Example usage :**
```sh
#include <iostream>
#include "cads/array.h"
int main(){
	cads::array<int, 10> container;
	std::cout <<"container can store : " << container.length() << " elements";
	return 0;
}
```
**Output :**
```sh
10 elements
```

## Removing length( )