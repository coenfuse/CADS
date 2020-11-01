#pragma once
#include<iostream>
#include<exception>

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
	List<T>() : m_length(0), m_start(nullptr), m_end(nullptr) {}
	List<T>(T input_data) {
		Node* newNode = new Node;
		newNode->node_data = input_data;
		newNode->next_node = nullptr;
		m_start = m_end = newNode;
		m_length = 1;
	}
	~List<T>() {};

	class iterator;
	class constIterator;

private:
	class Node {
	public:
		T node_data;
		Node* next_node;

	public:
		Node(): node_data(), next_node(nullptr){}
		Node(T input_data, Node* new_next_node = nullptr) {
			node_data = input_data;
			next_node = new_next_node;
		}
		~Node() {
			//delete this;	// I do not know if this is logical or not.
		}

		//T get_data() { return node_data; }
		//Node* get_next() { return next_node; }
		//void set_data(T input_data) : node_data(input_data) {}
		//void set_next(Node* new_next_node) : next_node(new_next_node) {}
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

public:

	//iterator<List> begin();
	//iterator<List> end();

	T at(unsigned int index);
	void clear();
	void display();
	void display_from(unsigned int starting_index);
	void insert(T input_data);
	int find(T input_data);
	void insert_beg(T input_data);
	void insert_at(T input_data, unsigned int index);
	bool isEmpty();
	void join(List<T>);
	size_t length() const;
	T peekFirst() const;
	T peekMiddle() const;
	T peekLast() const;
	void remove(T to_remove);
	void remove_all(T to_remove);
	void remove_at(int to_remove_index);
	void remove_beg();
	void reverse();
	void shuffle();
	int size();
	void sort();
	List<T>* split(int split_from_index);
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
T List<T>::at(const unsigned int index) {
	std::string IOOR = "Index_Out_of_Range: ";
	try {
		if (index > m_length)
			throw IOOR;
	}
	catch (std::string e) {
		std::cout << e << "Returning value at end." << std::endl;
		return m_end->node_data;
	}
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
bool List<T>::isEmpty() {
	return (m_length == 0);
}

template <typename T>
void List<T>::join(List second_list) {
	int length = second_list.length();
	int local_counter = 0;
	while (local_counter < length) {
		insert(second_list.at(local_counter));
		local_counter++;
	}
}

template <typename T>
size_t List<T>::length() const {
	return m_length;
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
void List<T>::remove(T to_remove) {

}

template <typename T>
void List<T>::remove_all(T to_remove) {

}

template <typename T>
void List<T>::remove_at(int to_remove_index) {

}

template <typename T>
void List<T>::remove_beg() {

}

template <typename T>
void List<T>::reverse() {
	Node* temp_ptr = nullptr;
	Node* next_temp_ptr = nullptr;
	Node* index_ptr = m_start;
	unsigned int counter = 0;
	while (counter < m_length) {
		next_temp_ptr = index_ptr->next_node;
		index_ptr->next_node = temp_ptr;
		temp_ptr = index_ptr;
		index_ptr = next_temp_ptr;
		counter++;
	}
	m_start = temp_ptr;
	m_end = get_node(counter);

	/*
	CURRENT STATUS: NOT WORKING AS EXPECTED.

	The idea is as follows:

	Consider this list,
	N1 --> N2 --> N3 --> N4 --> N5 --> N6 --> nullptr
	Initially, start_ptr -> N1 & end_ptr -> N6

	Create two pointers as follows
	temp_ptr = next_temp_ptr = nullptr;
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
	index_ptr = m_start (N1 > N2 > N3 > N4 > N5 > N6)

	During Itr 1:
	next_temp = index_ptr->next 	N2 > N3 > N4 > N5 > N6 > nullptr
	index_ptr->next = temp_ptr		So, N1 > nullptr
	temp_ptr = index_ptr			N1 > nullptr
	index_ptr = next_temp			N2 > N3 > N4 > N5 > N6

	After Itr 1 and Befor Itr 2:
	temp_ptr = N1 > nullptr
	next_temp = N2 > N3 > N4 > N5 > N6 > nullptr
	index_ptr = N2 > N3 > N4 > N5 > N6 > nullptr

	During Itr 2:
	next_temp = index_ptr->next		N3 > N4 > N5 > N6 > nullptr
	index_ptr->next = temp_ptr		So, N2 > N1 > nullptr
	temp_ptr = index_ptr			N2 > N1 > nullptr
	index_ptr = next_temp			N3 > N4 > N5 > N6

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

}

template <typename T>
int List<T>::size() {
	return sizeof(m_start) * m_length;
}

template <typename T>
void List<T>::sort() {

}

template <typename T>
List<T>* split(int split_from_index) {
	List<T>* split = new List;

	return split;
}
