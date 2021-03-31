
## CADS (v 0.1.1.13.5)
CADS is a simple, learner friendly and fully customizable, Data Structure and Algorithm library for C++ developers. A lightweight C++ library using simplest of the coding practices to maintain highest levels of readability. It is :

- **Modular :** Remove the stuff you don't need.
- **Simple :** Easier to understand and modify
- **Tested :** Run existing tests or make your own.

## Why?
I like clean code and STL is far from it. It surely performs exceptionally well everywhere but it is little tricky to understand at the first glance. Personally, I like understanding every bit of code that goes into my projects and since STL played a fundamental role in all of my projects. Not understanding it fully enough bugged me.

## Features

- Heavily documented, Explaining the smallest of its features and nuances in great detail.
- Using common English words and method names to improve read-ability.
- Healthy balance of inheritance and code duplication to provide most optimum performance.
- Bundled with a complete testing system so user can test the performance of library and fidelity of its claims.
- No performance drop as compared to the STL.
- Appropriate for both novices and seasoned developers of any programming language.

## Containers
- [**Array**](src/cads/array.h) : Read documentation [here](doc/array.md)

## Usage
It is as easy as it gets. The following is an example of using two containers `array` and `list` provided in the library.
```sh
#include <iostream>
#include "cads.h"

int main(){
	cads::array<char, 20> array_exp;
	cads::list<int> list_exp;

	array_exp[3] = 'b';
	list_exp.push_back(3);

	//...
	
	return 0;
}
```
## Installation

**Need some help here.**
CADS is in its early state of development and I do not know any deployment methods for it. As of now, one can just clone the repository into their system and copy the `/src` folder from the repo and add into their project's dependency folder.

## Development Roadmap

This project is in its very early stage of development and currently consists of only a few data structures. The development is prioritized to create a strong structure consisting of very simple functionalities. Other performance upgrades and new features are slated for future releases.
The following is a brief road-map on how this project will be growing, but for more detailed insight into development. Refer to [**_this_**](doc/dev_roadmap.md)

- **v1.0 : Major containers with basic functionalities**
	- [x] **0.0 : Setting up testing framework**
	- [ ] **0.1 :** Static Containers
	- [ ] **0.2 :** Dynamic Containers
	- [ ] **0.3 :** Basic Abstract Data Types Containers
	- [ ] **0.4 :** Tree Containers
	- [ ] **0.5 :** Hashed Containers
	- [ ] **0.6 :** Multi-Dimension Containers
	- [ ] **0.7 :** Graph Containers
	- [ ] **0.8 :** Testing 1
	- [ ] **0.9 :** Testing 2
	- [ ] **1.0 :** Release Notes and Documentation
- **v2.0 : Introduce Overloads and Iterators**
	- [ ] **1.1 :** Overloads
	- [ ] **1.2 :** Iterators
	- [ ] **1.3 :** Overload Testing 1
	- [ ] **1.4 :** Overload Testing 2
	- [ ] **1.5 :** Iterator Testing 1
	- [ ] **1.6 :** Iterator Testing 2
	- [ ] **1.7 :** Iterator Testing 3
	- [ ] **1.8 :** Global Testing and Code Reviews
	- [ ] **1.9 :** Speed Testing and Code Reviews
	- [ ] **2.0 :** Release Notes and Documentation
- **v3.0 : Introduce Initializers**
- **v4.0 : Remove Dependencies**
- **v5.0 : Algorithms**


## Testing
A proprietary testing wrapper has been defined in the CADS project that handles everything related to testing.
Kindly read the [testing](...) documentation **( _incomplete_ )** for more information.

## Dependencies

CADS currently uses a few core C++ functions. As of v4.0 it is expected to be completely free from any dependency. Making it a completely independent library working out of the box. See the [development roadmap](doc/dev_roadmap.md) for more details.
- **[stdexcept](https://en.cppreference.com/w/cpp/header/stdexcept)**

<!--## Contribution

A pull-request standard is currently being theorized to improve bug-reporting and community assist on this project. Updates in this regard will be announced shortly.

## License
## Credits
-->