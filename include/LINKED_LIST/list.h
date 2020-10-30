#pragma once
#include<iostream>

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
	List<T>() : m_size(0), m_start(nullptr), m_end(nullptr) {}
	List<T>(T input_data) {
		Node* newNode = new Node;
		newNode->node_data = input_data;
		newNode->next_node = nullptr;
		m_start = newNode;
		m_size++;
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
		Node(): node_data(NULL), next_node(nullptr){}
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

	unsigned int m_size;
	Node* m_start;
	Node* m_end;

	Node* get_node(int index) {
		if (index <= 0) return m_start;
		else if (index >= m_size) return m_end;
		else {
			Node* m_traveler;
			m_traveler = m_start;
			unsigned int counter = 0;
			while (counter != index) {
				m_traveler = m_traveler->next_node;
			}
			return m_traveler;
		}
	}

public:

	//iterator<List> begin();
	//iterator<List> end();

	T at(int index);
	void clear();
	void display();
	void display_from(int starting_index);
	void insert(T input_data);
	int find(T input_data);
	void insert_beg(T input_data);
	void insert_at(T input_data, int index);
	bool isEmpty();
	void join(List<T>*);
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
	void sort();
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
T List<T>::at(int index) {

}

template <typename T>
void List<T>::clear() {

}

template <typename T>
void List<T>::display() {
	Node* newNode = m_start;
	while (newNode != nullptr) {
		std::cout << newNode->node_data << " -> ";
		newNode = newNode->next_node;
	}
}

template <typename T>
void List<T>::display_from(int starting_index) {

}

template <typename T>
int List<T>::find(T input_data) {

}

template <typename T>
void List<T>::insert(T input_data) {
	Node* newNode = new Node;
	newNode->node_data = input_data;
	newNode->next_node = nullptr;
	m_start->next_node = newNode;
	m_size++;
}

template <typename T>
void List<T>::insert_beg(T input_data) {

}

template <typename T>
void List<T>::insert_at(T input_data, int index) {

}

template <typename T>
bool List<T>::isEmpty() {
	return (m_size == 0);
}

template <typename T>
void List<T>::join(List* second_list) {

}

template <typename T>
unsigned int List<T>::length() {
	return m_size;
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
void List<T>::sort() {

}
