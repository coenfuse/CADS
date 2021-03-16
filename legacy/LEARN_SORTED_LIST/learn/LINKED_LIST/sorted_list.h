#pragma once
#pragma once
#include <iostream>

namespace learn {

	template <typename T>
	// Only works for 'comparable' data types. Requires overloading of relational operators for usage with custom data types.
	class sorted_list {

		struct Node {
			T data;
			Node* next;
			Node* previous;

			Node() : data(0), next(nullptr), previous(nullptr) {}
			Node(T _init_data) : data(_init_data), next(nullptr), previous(nullptr) {}
			~Node() {}
		};

	private:

		Node* m_head;
		Node* m_tail;
		size_t m_length;
		bool(*compare_func)(T var_1, T var_2);

	private:

		Node* get_node(const size_t& index) const {

			if (index < m_length) {

				Node* traveler = m_head;
				size_t counter = 0;

				while (traveler != nullptr) {
					if (counter == index)
						break;
					traveler = traveler->next;
					counter++;
				}

				return traveler;
			}

			return nullptr;
		}

		int get_apt_index(T element) const {

			// Finding index to insert at in a sorted list using linear search

			int apt_index = 0;
			Node* traveler = m_head;

			if (m_length != 0) {

				while (traveler != nullptr) {
				
					T current = traveler->data;
					T next = m_tail->data;

					if(traveler->next != nullptr)
						next = (traveler->next)->data;

					if (element <= m_head->data)
						return 0;
					else if (element >= m_tail->data)
						return (int)m_length;
					else if (current < element && element <= next)
						return ++apt_index;
					else {
						traveler = traveler->next;
						apt_index++;
					}

				}

			}
			else
				return apt_index;	// If list is empty, you insert at starting. Duh!

			//
			//if (m_length >= 2) {
			//	T current = traveler->data;
			//	T next = (traveler->next)->data;
			//	
			//	if (current <= element || element <= next)
			//		return apt_index;
			//	traveler = traveler->next;
			//	apt_index++;
			//}
			//
			//if (element < m_head->data)
			//	return apt_index;
			//else if (m_head->data <= element && element <= m_tail->data)
			//	return ++apt_index;
			//else
			//	return m_length;
			

			//while (traveler != nullptr) {
			//
			//	if (traveler->data < element)
			//		return ++apt_index;
			//	else if (traveler->data > element)
			//		return --apt_index;
			//	else if (traveler->data == element)
			//		return apt_index;
			//
			//	traveler = traveler->next;
			//}
			//return m_length;
		}


		Node* create_node(T element) {
			return new Node(element);
		}

		void push_head(const T& element) {
			
			Node* new_node = create_node(element);
			
			new_node->next = m_head;
			m_head->previous = new_node;
			m_head = new_node;

			m_length++;

		}

		void push_tail(const T& element) {

			Node* new_node = create_node(element);

			m_tail->next = new_node;
			new_node->previous = m_tail;
			m_tail = new_node;

			m_length++;

		}

	public:

		sorted_list();
		sorted_list(bool(*given_compare_func)(T _A, T _B));
		~sorted_list();

		//class iterator;
		//class reverse_iterator;
		//class const_iterator;
		//class const_reverse_iterator;

		T& at(const size_t& index) const;
		bool find(T element) const {}
		void display() const;
		bool empty() const {}
		void reverse() {}
		//T remove(iterator){}
		void push(const T& element);
		T pop() {}
		T peek_head() const {}
		T peek_tail() const {}
		size_t size() const {}

		//iterator begin(){}
		//iterator end(){}

		//const_iterator cbegin(){}
		//const_iterator cend(){}

		//reverse_iterator rbegin(){}
		//reverse_iterator rend(){}

		//const_reverse_iterator crbegin(){}
		//const_reverse_iterator crend(){}

	};

	template <typename T>
	sorted_list<T>::sorted_list() : m_head(nullptr), m_tail(nullptr), m_length(0) {}

	template <typename T>
	sorted_list<T>::sorted_list(bool(*given_comparision_func)(T _A, T _B)) : compare_func(given_comparision_func) {}

	template <typename T>
	sorted_list<T>::~sorted_list() {}

	template <typename T>
	T& sorted_list<T>::at(const size_t& index) const {
		
		Node* to_return = get_node(index);
		return to_return->data;

	}

	template <typename T>
	void sorted_list<T>::display() const {

		if (m_length != 0) {		// We can also use the syntax if(m_length) {...} but we didn't. Why?

			Node* traveler = m_head;
			std::cout << "START -> ";
			while (traveler != nullptr) {
				std::cout << traveler->data << " <-> ";
				traveler = traveler->next;
			}
			std::cout << " END" << std::endl;
		}
		else
			std::cout << "EMPTY" << std::endl;
	}

	template <typename T>
	void sorted_list<T>::push(const T& element) {

		if (m_length != 0) {

			int position = get_apt_index(element);

			if (position <= 0)
				push_head(element);
			else if (position >= m_length)
				push_tail(element);
			else {

				Node* new_node = create_node(element);

				size_t pos = (size_t)position;
				Node* insert_after = get_node(--pos);
				Node* temp = insert_after->next;
				insert_after->next = new_node;
				new_node->next = temp;
				new_node->previous = insert_after;
				m_length++;
			}
	
		}
		else {
			Node* new_node = create_node(element);
			m_head = m_tail = new_node;
			m_length++;
		}

	}
}

// DEVELOPMENT NOTES:

// TODO : ISSUES WITH POINTER:
// ----------------------------------------------------------------------------
// This algorithm doesn't work as intended if the initialization data type is a
// pointer. For example if the initialization is of type:
// 
//		sorted_list <compound*> sorted_compounds;
//
// Then the list is sorted by the values of each node's address, not with the
// value stored in that node.

