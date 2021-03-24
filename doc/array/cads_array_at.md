# cads : : array : : at ( index )

 - **return type** : const type
 - **parameters** : size_t reference

Member function to access value stored at a specified index in the container.

**Example usage :**
```sh
#include <iostream>
#include "cads/array.h"
int main(){
	cads::array<int, 10> container;
	container[0] = 24;
	container[1] = 69;
	container[3] = 74;
	container[4] = 91;
	container[2] = 87;
	container[6] = 53;
	container[5] = 97;
	std::cout << container.at(1) << ",";
	std::cout << container.at(5) << ",";
	std::cout << container.at(3) ;
	return 0;
}
```
**Output :**
```sh
69,97,74
```
**at( )** returns a constant value specified at the index in the container. This is done to prevent assignment of value using this method. 
Also, this method returns the following whenever the index specified is out of bounds.
```sh
cads::array<type, size>::NPOS
```
NPOS is a placeholder value specifying invalid or empty in **cads : : array** container. It holds value of -1 that is statically casted with the type the container is templated with.
```sh
static constexp auto NPOS { static_cast<TYPE>(-1) };
```
It is a one-way data flow method unlike the [square operator](square_bracket_operator.md). With this we can only access data from the container, not assign to it.

```sh
#include <iostream>
#include "cads/array.h"
int main(){
	cads::array<int, 10> array_container;
	for(size_t i = 0; i < 10; i++){
		array_container.at(index) = (int)(index * index);		// Will throw Error C3892
	}
	return 0;
}
```
**Output :**
```sh
Error C3892	:'array_container': you cannot assign to a variable that is const.
```

_A constant variant of this operator is also available. It is automatically invoked when the container is initialized as a constant type._