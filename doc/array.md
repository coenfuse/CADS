# cads : : array

A simple wrapper for a fixed sized array. Consists of simple methods enclosed in
a simple package that helps in reducing redundant code and improving code clarity.

## Features
- Minimum usage of C++ exceptions.
- Simple Implementation.
- Thoroughly tested and all test cases included.

## Member Types

- **[container](array/member_types.md)** : Actual templated data array
- **[CONST_REF](array/member_types.md)** : Alias for Constant Reference to templated data-type
- **[PTR](array/member_types.md)** : Alias for Pointer to templated data-type
- **[REF](array/member_types.md)** : Alias for Reference to templated data-type
- **[SIZE](array/member_types.md)** : Templated size-type
- **[TYPE](array/member_types.md)** : Templated data-type

## Member Functions

- **[operator [ size_t index ]](array/overloads/square_bracket_operator.md)** : Two-way data indexing operator.
---
- **[array( )](array/init/def_ctor.md)** : Default constructor
- **[array( array<TYPE,SIZE>& )](array/init/copy_ctor.md)** : Copy constructor
- **[~array( )](array/init/dtor.md)** : Default destructor
---
- **[back( )](array/meth/cads_array_back.md)** : Returns last element in the array
- **[clear( )](array/meth/cads_array_clear.md)** : Clears the array container
- **[data( )](array/meth/cads_array_data.md)** : Returns pointer to internal container
- **[fill( )](array/meth/cads_array_fill.md)** : Fills the container with specified value
- **[front( )](array/meth/cads_array_front.md)** : Returns first element in the array
- **[is_empty( )](array/meth/cads_array_is_empty.md)** : Checks the container if its empty
- **[size( )](array/meth/cads_array_is_size.md)** : Returns total size of container

## Usage
To use cads array in you code. First include the either of the following header file
**`
#include "CADS.h"` or `#include "cads/array.h"
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
- [x] Copy Constuctor
- [x] back( )
- [x] clear( )
- [x] data( )
- [ ] fill( )
- [ ] front( )
- [x] is_empty( )
- [x] operator[ ]
- [ ] size( )
- [ ] swap( )

#### **V2**
- [ ] Copy Constuctor (Convertible)
- [ ] operator=
- [ ] operator==
- [ ] operator!=
- [ ] Pre-Increment / Post-Increment
- [ ] Post-Increment / Post-Decrement
- [ ] Relational Operator Overloads
- [ ] at( )
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

## Contributions
Seeking.