#pragma once

#include<iostream>
#include<exception>
#include<time.h>
#include "..\UTIL.h"

/*
template <class Vector>
class List<Vector>::constIterator {

};

template <class Vector>
class List<Vector>::iterator {

};
*/

template <class T>
class List
{
public:

	// Constructors and Destructors
	List<T>() : m_length(0), m_start(nullptr), m_end(nullptr) {}
	List<T>(T input_data) {
		Node* newNode = new Node;
		newNode->node_data = input_data;
		newNode->next_node = nullptr;
		m_start = m_end = newNode;
		m_length = 1;
	}
	~List<T>() {};

	//class iterator;
	//class constIterator;

private:

	struct Node {
	public:
		T node_data;
		Node* next_node;
	public:
		// The following functions look trivial to me
		Node() : node_data(), next_node(nullptr) {}
		Node(T input_data, Node* new_next_node = nullptr) {
			node_data = input_data;
			next_node = new_next_node;
		}
		~Node() {}
	};

	unsigned int m_length;
	Node* m_start;
	Node* m_end;

	Node* get_node(unsigned int index) const {
		if (index < 0 || index > m_length) return nullptr;
		else {
			Node* m_traveler = m_start;
			unsigned int counter = 0;
			while (m_traveler != nullptr) {
				if (counter == index) break;
				m_traveler = m_traveler->next_node;
				counter++;
			}
			return m_traveler;
		}
	}
	Node* get_new_node(T input_data) {
		Node* newNode = new Node;
		newNode->node_data = input_data;
		newNode->next_node = nullptr;
		return newNode;
	}

	void remove_beg();
	void remove_end();
	void swap(unsigned int, unsigned int);

public:
	//iterator<List> begin();
	//iterator<List> end();
	// Adds two list and deletes the second list.
	void add(List<T>&);
	// Returns data stored in the list at a given index
	T at(const unsigned int index);

	// Deletes all the nodes in the list
	void clear();

	// Checks if the two list contain a same node
	bool common(List& second_list);

	// Removes duplicate nodes from the list.
	void dedup();
	void display();
	void display_from(unsigned int starting_index);
	void insert(T input_data);
	int find(T input_data);
	void insert_beg(T input_data);
	void insert_at(T input_data, unsigned int index);
	void intersect(List* second_list);
	int intersect_at(List* second_list);
	bool isEmpty();
	// Joins two lists while retaining the second list. 
	void join(List<T>&);
	size_t length() const;
	bool palindrome();

	// Returns the data contained in the first node of the list.
	T peekFirst() const;

	// Returns the data contained in the middle of the list if length % 2 == 1, else returns middle + 1
	T peekMiddle() const;

	// Returns the data contained in the last node of the list.
	T peekLast() const;

	// Returns a random value contained in the list.
	T random();

	// Removes the first node from the front containing the input data.
	void remove(T to_remove);

	// Removes all the occurencs of the data in the list.
	void remove_all(T to_remove);

	// Removes a specified node irrespective of data contained in it.
	void remove_at(unsigned int to_remove_index);

	// Reverses the list.
	void reverse();
	void shuffle();
	int size();
	void sort(bool ascending = true);

	// Returns a Pair that contains two halves of the list.
	Pair<List<T>> split(unsigned int split_from_index);
	void trim_tail(unsigned int trim_amount);
	void trim_head(unsigned int trim_amount);

	// Operator Overloads

	T& operator[](size_t index);
	T& operator[](size_t index) const;
};

// Implementations go below

/*
template <typename T>
iterator<List*> List<T>::begin() {
	return nullptr;
}

template <typename Vector, typename T>
iterator List<T>::end() {
	return nullptr;
}
*/

template <typename T>
T& List<T>::operator[](size_t index) {
	return noexcept(get_node((unsigned int)index)->node_data);
}

template <typename T>
T& List<T>::operator[](size_t index) const {
	return noexcept(get_node((unsigned int)index)->node_data);

	// If the list happens to be initialized as a const type then this operator
	// doesn't works for both reading and writing operation. Thus it is needed
	// to write a const overload for this operator.
}

template <typename T>
void List<T>::add(List<T>& second_list) {
	int length = second_list.length();
	int local_counter = 0;
	while (local_counter < length) {
		insert(second_list.at(local_counter));
		local_counter++;
	}
	second_list.clear();
}

template <typename T>
T List<T>::at(const unsigned int index) {
	// INCOMPLETE.
	// Need to specify a single operator like std::string::npos that
	// is returned whenever the given index is out of bounds.

	if (index < 0 || index > m_length)
		return NULL;
	else
		return get_node(index)->node_data;
}

template <typename T>
void List<T>::clear() {
	Node* node = m_start;
	Node* temporary = node;
	while (temporary != nullptr) {
		temporary = node->next_node;
		delete node;
		node = temporary;
		m_length--;
	}
	m_start = m_end = nullptr;
}

template <typename T>
bool List<T>::common(List& second_list) {
	// O(n^m). Extremely inefficient.

	if (m_length > 0 && second_list->m_length > 0) {

		Node* first_traveler = this->m_start;
		Node* second_traveler = second_list->m_start;

		while (first_traveler != nullptr) {
			while (second_traveler != nullptr) {
				if (first_traveler->node_data == second_traveler->node_data)
					return true;
				second_traveler = second_traveler->next_node;
			}
			first_traveler = first_traveler->next_node;
		}
	}
	return false;	// Either of the list is empty.
}

template <typename T>
void List<T>::dedup() {
	// Possible implementation
	// Sort the list, obtain pairs of data, and remove one of the element from the original list.
}

template <typename T>
void List<T>::display() {
	Node* newNode = m_start;
	while (newNode != nullptr) {
		std::cout << newNode->node_data << " -> ";
		newNode = newNode->next_node;
	}
	std::cout << "NULL" << std::endl;
}

template <typename T>
void List<T>::display_from(unsigned int starting_index) {
	if (starting_index > m_length)
		std::cout << "NULL" << std::endl;
	else {
		Node* traveler = get_node(starting_index);
		while (traveler != nullptr) {
			std::cout << traveler->node_data << " -> ";
			traveler = traveler->next_node;
		}
		std::cout << "NULL" << std::endl;
	}
}

template <typename T>
int List<T>::find(T input_data) {
	// TODO: Currently O(n), later implement using sort() and performing binary search.

	Node* traveler = m_start;
	int location = 0;
	while (traveler != nullptr) {
		if (traveler->node_data == input_data)
			return location;
		traveler = traveler->next_node;
		location++;
	}
	return -1;
}

template <typename T>
void List<T>::insert(T input_data) {
	Node* newNode = get_new_node(input_data);

	if (m_length == 0) {
		m_start = m_end = newNode;
		m_length++;
	}
	else {
		m_end->next_node = newNode;
		m_end = newNode;
		m_length++;
	}
}

template <typename T>
void List<T>::insert_beg(T input_data) {
	Node* newNode = get_new_node(input_data);
	if (m_length == 0) {
		m_start = m_end = newNode;
		m_length++;
	}
	else {
		newNode->next_node = m_start;
		m_start = newNode;
		m_length++;
	}
}

template <typename T>
void List<T>::insert_at(T input_data, unsigned int index) {

	if (index <= 0) insert_beg(input_data);
	else if (index >= m_length) insert(input_data);
	else {
		Node* node_to_shift = get_node(index);
		Node* previous = get_node(--index);
		Node* newNode = get_new_node(input_data);

		previous->next_node = newNode;
		newNode->next_node = node_to_shift;
		m_length++;
	}
}

template <typename T>
void List<T>::intersect(List* second_list) {
	/*
	* Given lists A and B having nodes
	* a > b > c > d > e > f > null
	* and
	* d > e > f > a > m > x > null
	*
	* A statement A.intersect(B) would result in A having nodes d > e > f > NULL
	*/

	if (intersect_at(second_list) != -1) {
		// do_something
	}
}

template <typename T>
int List<T>::intersect_at(List* second_list) {
	if (m_start == nullptr || second_list->m_start == nullptr)
		return -1;

	Node* first_head = m_start;
	Node* second_head = second_list->m_start;

	int lenA = m_length;
	int lenB = second_list->m_length;
	int diff = abs(lenA - lenB);	// Get absolute difference

	if (lenA > lenB)
		while (diff-- > 0)
			first_head = first_head->next_node;
	else
		while (diff-- > 0)
			second_head = second_head->next_node;

	for (; first_head != nullptr && second_head != nullptr;
		first_head = first_head->next_node, second_head = second_head->next_node)
		if (first_head->node_data == second_head->node_data)
			return first_head->node_data;
	return -1;
}

template <typename T>
bool List<T>::isEmpty() {
	return (m_length == 0);
}

template <typename T>
void List<T>::join(List& second_list) {
	m_end->next_node = second_list.get_node(0);
	m_end = second_list.get_node(second_list.length() - 1);
	m_length += second_list.length();
}

template <typename T>
size_t List<T>::length() const {
	return m_length;
}

template <typename T>
bool List<T>::palindrome() {
	// Checks whether the list is Palindrome or has a Palindrome sub_list in it.
	bool isPalindrome = false;

	if (m_length != 0) {
		for (int i = 0; i < m_length / 2; i++) {
			T front = get_node(i)->node_data;
			T end = get_node(m_length - (i + 1))->node_data;
			if (front == end)
				isPalindrome = true;
			else
				isPalindrome = false;
		}
		return isPalindrome;
	}
	return isPalindrome;
}

template <typename T>
T List<T>::peekFirst() const {
	return m_start->node_data;
}

template <typename T>
T List<T>::peekMiddle() const {
	return get_node(m_length / 2)->node_data;
}

template <typename T>
T List<T>::peekLast() const {
	return m_end->node_data;
}

template <typename T>
T List<T>::random() {
	srand((unsigned)time(0));
	unsigned int index = rand() % m_length;
	return get_node(index)->node_data;
}

template <typename T>
void List<T>::remove(T to_remove) {

	if (m_start != nullptr) {						// Runs only if list is not empty
		int index = find(to_remove);
		if (index != -1) {							// If the node exists in the list.
			if (index == 0) {						// If the node exist at the start.
				remove_beg();
			}
			else if (index == m_length - 1) {		// If the node is at the end.
				remove_end();
			}
			else {
				Node* previous = get_node(index - 1);
				Node* to_remove = previous->next_node;
				Node* next = to_remove->next_node;

				to_remove->next_node = nullptr;
				previous->next_node = next;
				delete to_remove;
				m_length--;
			}
		}
	}
}

template <typename T>
void List<T>::remove_all(T to_remove) {
	if (m_start != nullptr || m_end != nullptr) {					// Prep: Checks if the list is not empty
		while (find(to_remove) != -1) {								// Step 1: Run a loop until the value to be removed is present in the list
			remove(to_remove);										// Step 2: Remove.
		}
	}
}

template <typename T>
void List<T>::remove_at(unsigned int to_remove_index) {
	if (m_start != nullptr || m_end != nullptr) {					// Prep: Check if the list is not empty
		if (to_remove_index >= 0 && to_remove_index < m_length)		// Prep: Check if index is not out of range
			if (to_remove_index == 0) {								// If index is 0, remove_beg()
				remove_beg();
			}
			else if (to_remove_index = m_length - 1) {				// If index gives last node, remove_end()
				remove_end();
			}
			else {
				Node* previous = get_node(--to_remove_index);		//
				Node* to_remove = previous->next_node;
				Node* next = to_remove->next_node;

				to_remove->next_node = nullptr;
				previous->next_node = next;
				delete to_remove;
				--m_length;
			}
	}
}

template <typename T>
void List<T>::reverse() {
	Node* temp_ptr = nullptr;
	Node* next_ptr = nullptr;
	Node* index_ptr = m_start;
	unsigned int counter = 0;

	while (counter < m_length) {
		next_ptr = index_ptr->next_node;
		index_ptr->next_node = temp_ptr;
		temp_ptr = index_ptr;
		if (!counter)
			m_end = index_ptr;
		index_ptr = next_ptr;
		counter++;
	}
	m_start = temp_ptr;

	/*
	CURRENT STATUS: WORKING AS EXPECTED. NEED OPTIMIZATION

	The idea is as follows:

	Consider this list,
	N1 --> N2 --> N3 --> N4 --> N5 --> N6 --> nullptr
	Initially, start_ptr -> N1 & end_ptr -> N6

	Create two pointers as follows
	temp_ptr = nullptr;
	next_temp_ptr = nullptr;
	index_ptr = m_start;

	while(this.length)
		next_temp_ptr = index_ptr->next_node;
		index_ptr->next_node = temp_ptr;
		temp_ptr = index_ptr;
		index_ptr = next_temp_ptr;

	then
	m_start = temp_ptr

	Working:
	Would run for (m_length) iterations

	Before Itr 1:
	temp_ptr = nullptr;
	next_temp = nullptr;
	index_ptr = m_start (N1 > N2 > N3 > N4 > N5 > N6 > nullptr)

	During Itr 1:
	next_temp = index_ptr->next 	N2 > N3 > N4 > N5 > N6 > nullptr
	index_ptr->next = temp_ptr		So, N1 > nullptr
	temp_ptr = index_ptr			N1 > nullptr
	index_ptr = next_temp			N2 > N3 > N4 > N5 > N6 > nullptr

	After Itr 1 and Befor Itr 2:
	temp_ptr = N1 > nullptr
	next_temp = N2 > N3 > N4 > N5 > N6 > nullptr
	index_ptr = N2 > N3 > N4 > N5 > N6 > nullptr

	During Itr 2:
	next_temp = index_ptr->next		N3 > N4 > N5 > N6 > nullptr
	index_ptr->next = temp_ptr		So, N2 > N1 > nullptr
	temp_ptr = index_ptr			N2 > N1 > nullptr
	index_ptr = next_temp			N3 > N4 > N5 > N6 > nullptr

	After Itr 2 and before Itr 3:
	temp_ptr = N2 > N1 > nullptr
	next_temp = N3 > N4 > N5 > N6 > nullptr
	index_ptr = N3 > N4 > N5 > N6 > nullptr

	During Itr 3:
	next_temp = index_ptr->next		N4 > N5 > N6 > nullptr
	index_ptr->next = temp_ptr		So, N3 > N2 > N1 > nullptr
	temp_ptr = index_ptr			N3 > N2 > N1 > nullptr
	index_ptr = next_temp			N4 > N5 > N6 > nullptr

	After Itr 3 and before Itr 4:
	temp_ptr = N3 > N2 > N1 > nullptr
	next_temp = N4 > N5 > N6 > nullptr
	index_ptr = N4 > N5 > N6 > nullptr

	During Itr 4:
	next_temp = index_ptr->next		N5 > N6 > nullptr
	index_ptr->next = temp_ptr		So, N4 > N3 > N2 > N1 > nullptr
	temp_ptr = index_ptr			N4 > N3 > N2 > N1 > nullptr
	index_ptr = next_temp			N5 > N6 > nullptr

	After Itr 4 and before Itr 5:
	temp_ptr = N4 > N3 > N2 > N1 > nullptr
	next_temp = N5 > N6 > nullptr
	index_ptr = N5 > N6 > nullptr

	During Itr 5:
	next_temp = index_ptr->next		N6 > nullptr
	index_ptr->next = temp_ptr		So, N5 > N4 > N3 > N2 > N1 > nullptr
	temp_ptr = index_ptr			N5 > N4 > N4 > N3 > N2 > N1 > nullptr
	index_ptr = next_temp			N6 > nullptr

	After Itr 5 and before Itr 6:
	temp_ptr = N5 > N4 > N4 > N3 > N2 > N1 > nullptr
	next_temp = N6 > nullptr
	index_ptr = N6 > nullptr

	During Itr 6:
	next_temp = index_ptr->next		nullptr
	index_ptr->next = temp_ptr		So, N6 > N5 > N4 > N3 > N2 > N1 > nullptr
	temp_ptr = index_ptr			N6 > N5 > N4 > N4 > N3 > N2 > N1 > nullptr
	index_ptr = next_temp			nullptr

	After iteration 6:
	temp_ptr = N6 > N5 > N4 > N4 > N3 > N2 > N1 > nullptr
	next_temp = null;
	index_ptr = N6 > nullptr

	m_start = temp_ptr				So, N6 > ...
	m_end =
	*/
}

template <typename T>
void List<T>::shuffle() {

	List<T> shuffled;											// Prep: New shuffled list will be here.

	while (m_length != 0) {										// Step 1: Initiate a loop that runs till the length of the current List
		T random_data = this->random();							// Step 2: Store data of random node in a variable
		shuffled.insert(random_data);							// Step 3: Insert the random data into shuffled list.
		this->remove(random_data);								// Step 4: Remove the first occurence of random data from current list. Thereby reducing m_length by 1 automatically.
	}

	this->clear();												// Step 5: Empty the current list

	// Iterator Method
	// for(auto each_node : shuffled)	this.insert(eachNode);

	unsigned int counter = 0;
	while (counter < shuffled.length()) {
		this->insert(shuffled.at(counter));
		counter++;
	}
	shuffled.clear();
}

template <typename T>
int List<T>::size() {
	// Returns size of the list in bytes
	return sizeof(T) * m_length;
}

template <typename T>
void List<T>::sort(bool ASC) {
	// Something is wrong with this one. INCOMPLETE.
	if (ASC) {
		// Ascending order sort
		int i = 1;
		int j = 0;
		for (; i < m_length; i++)
			for (; j < m_length - i; j++) {
				int current = this->get_node(j)->node_data;
				int next = this->get_node(j + 1)->node_data;

				if (current > next)
					swap(j + 1, j + 2);		// <-- This is the problem maybe
				this->display();
			}
	}
	else {
		// Descending order sort
	}
}


template <typename T>
Pair<List<T>> List<T>::split(unsigned int split_from_index) {

	List<T> first_halve, second_halve;
	Pair<List<T>> split_pair(first_halve, second_halve);

	if (m_start != nullptr || m_end != nullptr) {
		if (split_from_index < m_length) {

			unsigned int counter = 0;
			while (counter < split_from_index) {
				first_halve.insert(this->at(counter));
				counter++;
			}

			counter = split_from_index;
			while (counter < m_length) {
				second_halve.insert(this->at(counter));
				counter++;
			}

			split_pair.first = first_halve;
			split_pair.second = second_halve;

			return split_pair;
		}
		else
			return split_pair;	// Splitting index is out of bounds. Returns empty split lists.
	}
	return split_pair; // Parent list is empty. Returns empty split lists.

	// Note: A more true to its name implementation might be just trimming the
	// parent list from the end to the splitting index and returning a new list
	// that just contains the trimmed elements. The new list will represent the
	// second half whereas the parent list would be the first half. But I chose
	// to not do this primarily on the 'What if?' factor. What if the end user
	// wanted to keep the original list preserved and just wanted to create a
	// new copy of splitted parts for whatever usage?
}

template <typename T>
//Trims the list from the start.
void List<T>::trim_tail(unsigned int trim_amount) {

	short trim_by = m_length - trim_amount;
	if (trim_by > 0) {
		if (m_length == trim_amount) {
			clear();
		}
		else {
			unsigned int counter = 0;
			while (counter < trim_amount) {
				remove_end();
				counter++;
			}
		}
	}
	// Primary intinct to solve this problem would be just detaching all the
	// nodes from the list after a particular index (The index can be found by
	// subtracting trim_amount from the length of the string). But doing so will
	// cause serious memory leaks and orphan nodes. Thus, implementation needs
	// confirmed deletion of the trimmed nodes from the system memory.
}

template <typename T>
//Trims the list from the start.
void List<T>::trim_head(unsigned int trim_amount) {

	short trim_by = m_length - trim_amount;
	if (trim_by > 0) {
		if (m_length == trim_amount) {
			clear();
		}
		else {
			unsigned int counter = 0;
			while (counter < trim_amount) {
				remove_beg();
				counter++;
			}
		}
	}
	// Just like explained in trim_trail(), the primary solution for this fx
	// would be just assigning m_start with whatever node that is present at
	// trim_amount index. Subsequently orphaning all the nodes preceding it.
	// That would cause memory leakage thus it is necessary to delete all the
	// unwanted nodes from the system memory.
}


// Private functions implementations

template <typename T>
void List<T>::remove_beg() {
	if (m_start != nullptr || m_end != nullptr) {
		Node* temp = m_start;					// Step 1: Storing the current start in a temporary variable
		m_start = m_start->next_node;			// Step 2: Overwriting the start with its 'next_node', thereby making the 'next_node' a new start of the list.
		delete temp;							// Step 3: Deleting temp (previous start) and releasing memory.
		--m_length;								// Step 4: Reducing the length of the list by one.
	}
	/*
	* Note: This function will work fine without Step 1 and Step 3,
	* but I wrote them to release memory occupied the 'previous' start.
	*/
}

template <typename T>
void List<T>::remove_end() {
	if (m_start != nullptr || m_end != nullptr) {
		Node* previous = get_node(m_length - 2);	// Step 1: Fetching the node previous to the end.
		previous->next_node = nullptr;				// Step 2: Bypassing the current 'end' by directly pointing 'previous' to nullptr
		delete m_end;								// Step 3: Now the current end is detached from the list, we can delete it from memory.
		m_end = previous;							// Step 4: Making the 'previous' node a new end of the system.
		--m_length;									// Step 5: Reducing the length of the list by one.
	}
	/*
	* Note 1: m_length is natural number, meanwhile the internal indexing uses
	* whole numbers, i.e: the list starts from 0. So,
	* get_node(m_length) returns nullptr,
	* get_node(m_length) returns pointer to the end node.
	* and, get_node(m_length - 2) returns the node prior to end node.
	*
	* Note 2: This program will work fine if we ignore Step 3, but it is not recommended. Figure out why.
	*/
}

template<typename T>
void List<T>::swap(unsigned int A, unsigned int B) {
	// Internal indexing uses whole numbers, thus converting.

	if (A == 0) {
		if (B == 0) {
			B++;
		}
		B--;
	}
	else if (B == 0) {
		--A;
	}
	else {
		--A; --B;
	}

	// This function doesn't have bounds checking implemented in it.
	// Proceed with caution.

	if (abs(B - A) == 1) {
		if (A == 0) {
			Node* Node_A = m_start;
			Node* Node_B = Node_A->next_node;
			Node* bNext = Node_B->next_node;

			Node_A->next_node = bNext;		// Step 1
			Node_B->next_node = Node_A;		// Step 2
			m_start = Node_B;				// Step 3

			// WORKING
			/*
			(INITIAL STATE):	A -> B -> b		(m_start = A)

			After Step 1:
			A -> b			(m_start = A)
				 |
				 '<- B

			After Step 2:
			B -> A -> b		(m_start = A)

			After Step 3:
			B -> A -> b		(m_start = B)
			*/
		}
		else
		{
			Node* aPrev = get_node(A - 1);
			Node* Node_A = get_node(A);
			Node* Node_B = Node_A->next_node;
			Node* bNext = Node_B->next_node;
			Node* temp = Node_A;
			Node* temp_2 = bNext;

			aPrev->next_node = Node_B;		// Step 1
			Node_B->next_node = temp;		// Step 2
			Node_A->next_node = temp_2;		// Step 3 

			// WORKING:

			/*
			(INITIAL STATE): a -> A -> B -> b

			After Step 1:
			a -> B -> b
				 |
				 '<- A

			After Step 2:
			a -> B -> A
				 |	  |
				 '<--<'

			After Step 3:
			a -> B -> A -> b
			*/
		}
	}
	else {
		if (A == 0) {
			Node* Node_A = m_start;
			Node* aNext = Node_A->next_node;
			Node* bPrev = get_node(B - 1);
			Node* Node_B = get_node(B);
			Node* bNext = Node_B->next_node;

			Node_B->next_node = aNext;	// Step 1
			Node_A->next_node = bNext;	// Step 2
			bPrev->next_node = Node_A;	// Step 3
			m_start = Node_B;			// Step 4

			// Working
			/*
			(INITIAL STATE): A -> aNext -> bPrev -> B -> bNext		(m_start = A)

			After Step 1:
			A -> aNext -> bPrev -> B	b		(m_start = A)
				   |			   |
				   '---<--------<--'

			After Step 2:
			A -> b								(m_start = A)

			After Step 3:
			B -> aNext -> bPrev -> A -> b		(m_start = A)

			After Step 4:
			B -> aNext -> bPrev -> A -> b		(m_start = B)
			*/
		}
		else {
			Node* aPrev = get_node(A - 1);
			Node* Node_A = get_node(A);
			Node* aNext = Node_A->next_node;
			Node* bPrev = get_node(B - 1);
			Node* Node_B = get_node(B);
			Node* bNext = Node_B->next_node;
			Node* temp, * temp_2;

			temp = Node_A; temp_2 = bNext;	// Step 1
			aPrev->next_node = Node_B;		// Step 2
			Node_B->next_node = aNext;		// Step 3
			bPrev->next_node = temp;		// Step 4
			Node_A->next_node = temp_2;		// Step 5

			// WORKING

			/*
			(INITIAL STATE): aPrev -> A -> aNext -> n -> bPrev -> B -> bNext

			After Step 1:
			aPrev -> A -> aNext -> n -> bPrev -> B -> bNext
					 |								  |
				temp-'						   temp_2-'

			After Step 2:
			aPrev -> B -> bNext
					 |
					 '-bPrev <- n <- aNext <- A	(Orphan List)

			After Step 3:
			aPrev -> B -> aNext -> n -> bPrev
					 |					  |
					 '-----<------<-------'
					  (We have a loop here)

			After Step 4:
			aPrev -> B -> aNext -> n -> bPrev -> A
							|					 |
							'----------<---------'
						 (We shifted the loop a bit)

			After Step 5:
			aPrev -> B -> aNext -> n -> bPrev -> A -> bNext

			*/
		}
	}
}
