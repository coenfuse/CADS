
# cads : : array


A simple wrapper for a fixed sized array. Consists of simple methods enclosed in
a simple package that helps in reducing redundant code and improving code clarity.

## Features
- Exception Safe.
- Simple Implementation.
- Thoroughly tested and all test cases included.

## Member Types
- **[container](#container)** : Actual templated data array
- **[CONST_REF](#const_ref)** : Alias for Constant Reference to templated data-type
- **[PTR](#ptr)** : Alias for Pointer to templated data-type
- **[REF](#ref)** : Alias for Reference to templated data-type
- **[SIZE](#size)** : Templated size-type
- **[TYPE](#type)** : Templated data-type

## Member Functions
- **meth_1()** : Brief description
- **meth_2()** : Brief description
- **meth_3()** : Brief description

## Members (Private)
- **crystal( )** : Brief description
- **crystal( )** : Brief description
- **crystal()** : Brief description

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
- [ ] operator[ ]
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
#### 1. container
The actual array container inside this wrapper class. It is a regular array whose templated TYPE and SIZE that are determined on compile time.
Container is not an array itself, it is a pointer that'll contain a reference to a newly allocated array. The allocation is done at the time of initialization by wrapper's constructor.
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


## Contributions
Seeking.