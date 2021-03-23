


# cads : : array


A simple wrapper for a fixed sized array. Consists of simple methods enclosed in
a simple package that helps in reducing redundant code and improving code clarity.

## Features
- Minimum usage of C++ exceptions.
- Simple Implementation.
- Thoroughly tested and all test cases included.

## Member Types

_Anchor tags for sub-headings aren't working. You'd have to manually scroll to bottom of this documentation for more details on the following members :(_
- **[container](#container)** : Actual templated data array
- **[CONST_REF](#const_ref)** : Alias for Constant Reference to templated data-type
- **[PTR](#ptr)** : Alias for Pointer to templated data-type
- **[REF](#ref)** : Alias for Reference to templated data-type
- **[SIZE](#size)** : Templated size-type
- **[TYPE](#type)** : Templated data-type

## Member Functions

- **[operator [ index ]](#operator-[])** : Two-way data indexing operator.

## Usage
To use cads array in you code. First include the either of the following header file
**`
#include "cads.h"` or `#include "cads/array.h"
`**
Then use the following syntax to initialize the array with type and size of your choice:
**`
cads::array<type,size> your_array;
`**

```sh
#include <iostream.h>
#include "CADS.h"           // or #include "cads/array.h"
int main(){
    
    // Initializing the array container
    cads::array<int, 10> my_array;
    
    // Filling the array
    for(size_t index = 0; index < 10; index++){
        my_array[index] = index * 2;
    }
    
    // Printing the array on console
    for(size_t index = 0; index < 10; index++){
        std::cout << my_array[index] << ", " << std::endl;
    }
    
    return 0;
}
```
**Output:**
```sh
0, 2, 4, 6, 8, 10, 12, 14, 16, 18
```

## Development Roadmap
#### **V1**
- [x] Default Constuctor
- [ ] at( )
- [ ] back( )
- [ ] clear( )
- [ ] data( )
- [ ] is_empty( )
- [ ] fill( )
- [ ] front( )
- [x] operator[ ]
- [ ] size( )
- [ ] swap( )

#### **V2**
- [ ] Copy Constuctor
- [ ] operator=
- [ ] operator==
- [ ] operator!=
- [ ] Pre-Increment / Post-Increment
- [ ] Post-Increment / Post-Decrement
- [ ] Relational Operator Overloads
- [ ] begin( )
- [ ] cbegin( )
- [ ] cend( )
- [ ] crbegin( )
- [ ] crend( )
- [ ] end( )
- [ ] rbegin( )
- [ ] rend( )

#### **V3**
- [ ] Aggregate Initialization Support
- [ ] erase( )
- [ ] find( )
- [ ] find_if( )
- [ ] reverse( )
- [ ] sort( )
- [ ] split( )
- [ ] swap( array )
- [ ] Negative Indexing
- [ ] subarr( )
- [ ] Sub-Array Extraction Support

## Documentation

### Member Types

#### 1. container
The actual array container inside this wrapper class. It is a regular array whose templated TYPE and SIZE that are determined on compile time.
```sh
PTR container[SIZE];
```

#### 2. CONST_REF
An alias for `const TYPE&` just for the sake of improving the readability of the code.
```sh
using CONST_REF = const TYPE&;
```

#### 3. CONST_REF
An alias for `const TYPE*` just for the sake of improving the readability of the code.
```sh
using CONST_PTR = const TYPE*;
```

#### 4. PTR
An alias for `TYPE*` just for the sake of improving the readability of the code.
```sh
using PTR = TYPE*;
```

#### 5. REF
An alias for `TYPE&` just for the sake of improving the readability of the code.
```sh
using REF = TYPE&;
```

#### 6. SIZE
Templated value of type `size_t` that is used everytime a new array is initialized. It is also helpful in getting the size of the wrapper in constant time. The `size()` method returns thie SIZE value without the need to iterate over whole container to know it's size. 

#### 7. TYPE
Similar to `SIZE`, it is a templated type variable that is decided at compile time. For more info about templates, Read : [Templates and Template Classes in C++](https://www.cprogramming.com/tutorial/templates.html)

`template <typename TYPE, size_t SIZE>`

### Member Functions

#### 1. operator [ index ]
Overloaded operator for index based addressing. This operator gives direct access to any of the data member present in the container at the specified index. This operator doesn't incorporates bound checking and throws an exception when it happens.
It is called two-way indexing operator (for the lack of better word) because the user can both access the data from and assign data to the container.
A constant variant of this operator is also available. It is used when the container is initialized as a constant type.
Example usage :
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
We need to use an intializer list like this:
**'const cads::array<int,10> const_array = {1, 2, 3 ,4, 5}'**
to initialize our container with the specified values.

_Functionality for automatic conversion of initializer list to array is scheduled for future updates._

## Contributions
Seeking.