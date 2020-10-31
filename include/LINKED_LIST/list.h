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

	Node* get_node(unsigned int index) {
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
	unsigned int length();
	T peekFirst();
	T peekMiddle();
	T peekLast();
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
T List<T>::at(unsigned int index) {
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
unsigned int List<T>::length() {
	return m_length;
}

template <typename T>
T List<T>::peekFirst() {

}

template <typename T>
T List<T>::peekMiddle() {

}

template <typename T>
T List<T>::peekLast() {

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