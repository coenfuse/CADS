# Member Types

## 1. container
The actual array container inside this wrapper class. It is a regular array whose templated TYPE and SIZE that are determined on compile time.
```sh
PTR container[SIZE];
```

## 2. CONST_REF
An alias for `const TYPE&` just for the sake of improving the readability of the code.
```sh
using CONST_REF = const TYPE&;
```

## 3. CONST_REF
An alias for `const TYPE*` just for the sake of improving the readability of the code.
```sh
using CONST_PTR = const TYPE*;
```

## 4. PTR
An alias for `TYPE*` just for the sake of improving the readability of the code.
```sh
using PTR = TYPE*;
```

## 5. REF
An alias for `TYPE&` just for the sake of improving the readability of the code.
```sh
using REF = TYPE&;
```

## 6. SIZE
Templated value of type `size_t` that is used every time a new array is initialized. It is also helpful in getting the size of the wrapper in constant time. The `size()` method returns the SIZE value without the need to iterate over whole container to know it's size. 

## 7. TYPE
Similar to `SIZE`, it is a templated type variable that is decided at compile time. For more info about templates, Read : [Templates and Template Classes in C++](https://www.cprogramming.com/tutorial/templates.html)

`template <typename TYPE, size_t SIZE>`