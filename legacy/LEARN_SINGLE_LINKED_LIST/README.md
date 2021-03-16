# CADS

CADS is an attempt to create a better STL for C++ developers and learners.
Implemented in simple readable syntax, CDS tries to overcome the few drawbacks in STL (one being highly unreadable).
This project is in its very early stage of development and currently consists of only a few data structures.
While the current priority is to write simple code, performance upgrades will be implemented in parallel as the development progresses.

## How is this project structured?
This project is divided into two namespaces:
- **Learn :** All the code coming under this category is aimed towards learning purposes only and not meant to be incorporated in serious projects.
Thouroughly commented to explain the logic with complete documentation at the end of each file.
*Note: Some of the code is really stupid here, Users are recommended to learn from it and improve it as a practice howsover they like.*

- **CADS :** Improving from the **Learn**, all the code residing in this category is geared towards performance. Since high degree of readability is
still being maintained in this section a user is recommeded to tailor the code as required. Although there has been an attempt to made this code as generic
as possible while trying not to overstuff trivial features.

## Development
Currently the author is having a good time messing up with iterators and sorting algorithms.
Since this is a very early version of the project, this documentation is subject to frequent changes.
I am trying to keep the development process as architecturally logical as possible. The development is running in parallel on two branches named [LEARN]() and [CADS]().
Both of these branches contain a sub-branch for each type of data structure or algorithm or whatever that is written in them. It is planned to merge both the branches of CADS and LEARN
along with their sub-branches into main seamlessly. I'm also curious about how this goes.

### Learn
- [ ] - Array
- [ ] - Vector
- [x] - [Singly Linked List](learn/LINKED_LIST/list.h)
- [ ] - Bi-Directional Linked List
- [ ] - Ring
- [ ] - Stack
- [ ] - Q
- [ ] - Circular Q
- [ ] - DQ
- [ ] - Priority Q
- [ ] - Multi Q
- [ ] - Set
- [ ] - Map
- [ ] - Matrix
- [ ] - Plane
- *more later on.*

### CADS
- [ ] - Array
- [ ] - Vector
- [x] - [Bi-Directional Linked List](CADS/LINKED_LIST/list.h)
- [ ] - Ring
- [ ] - Stack
- [ ] - Q
- [ ] - Circular Q
- [ ] - DQ
- [ ] - Priority Q
- [ ] - Set
- [ ] - Map
- [ ] - Matrix
- [ ] - Plane
- *more later on.*

## Testing CADS
A proprietary testing wrapper has been defined in the CADS project that handles everything related to testing.
Kindly read the [testing](src/testing/testing.md) documention for more information.


## Usage
This project is uploaded as a MSVC project (project file included).
All the code related to start unit testing of any data type resides in the [main](src/main.cpp) file.
For direct usage of in your projects, just clone the [CADS](CADS) folder present inside the repository.