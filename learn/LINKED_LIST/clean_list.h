#pragma once

#include<iostream>
#include<time.h>
#include"..\UTIL.h"

template<typename T>
class List {

# define END nullptr
# define NONE nullptr
# define NOT_FOUND -1
# define EMPTY 0

private:
	struct Node {
		T node_data;
		Node* next_node;
	};

	size_t m_length = 0;
	Node* m_start = END;
	Node* m_end = END;

private:
	Node* get_node(unsigned int index) const {
		if (index < m_length) {

			Node* m_traveler = m_start;
			unsigned int counter = 0;

			while (m_traveler != END) {
				if (counter == index)
					break;
				m_traveler = m_traveler->next_node;
				counter++;
			}
			return m_traveler;
		}
		else
			return NONE;
	}

	Node* create_node(T input_data) {
		Node* newNode = new Node;
		newNode->node_data = input_data;
		newNode->next_node = END;
		return newNode;
	}

	void remove_head();
	void remove_tail();
	void swap(unsigned int, unsigned int);

public:
	List() {}
	List(T);
	~List() { clear(); }

	void add(List<T>&);
	T& at(const unsigned int index) const;
	void clear();
	bool common(List<T>&);
	void dedup();
	void display();
	void display_from(unsigned int);
	int find(const T&);
	void insert(const T&);
	void insert_at(const T&, unsigned int);
	void insert_head(const T&);
	List<T>& intersect(const List<T>&);
	void join(List<T>&);
	size_t length() const;
	bool palindrome();
	T& peek_head()const;
	T& peek_middle() const;
	T& peek_tail() const;
	T& random() const;
	void remove(const T&);
	void remove_all(const T&);
	void remove_at(const unsigned int&);
	void reverse();
	void shuffle();
	size_t size();
	void sort(bool ASC = true);
	Pair<List<T>> split(unsigned int);
	void trim_head(unsigned int);
	void trim_tail(unsigned int);

	T& operator[](size_t);
	T& operator[](size_t) const;
};

template<typename T>
List<T>::List(T input_data) {
	Node* new_node = create_node(input_data);
	new_node->next_node = END;
	m_length++;
}

template <typename T>
T& List<T>::operator[](size_t index) {
	return noexcept(get_node((unsigned int)index)->node_data);
}

template <typename T>
T& List<T>:: operator[](size_t index) const {
	return noexcept(get_node((unsigned int)index)->node_data);
}

template <typename T>
void List<T>::add(List<T>& second_list) {

	unsigned int traverse_length = second_list.m_length;
	unsigned int local_counter = 0;
	while (local_counter <= traverse_length) {
		insert(second_list.at(local_counter));
		local_counter++;
		second_list.remove_head();
	}
	second_list.clear();

}

template <typename T>
T& List<T>::at(const unsigned int index) const {

	if (index > m_length) {}
	else
		return get_node(index)->node_data;
}

template <typename T>
void List<T>::clear() {
	Node* traveler = m_start;
	while (traveler != END) {
		Node* temp = traveler;
		traveler = traveler->next_node;
		delete temp;
		m_length--;
	}
	m_start = m_end = END;
}

template <typename T>
bool List<T>::common(List<T>& second_list) {

	if (m_length > 0 && second_list.m_length > 0) {

		Node* first_traveler = m_start;
		Node* second_traveler = second_list.m_start;

		while (first_traveler != END) {
			while (second_traveler != END) {
				if (first_traveler->node_data == second_traveler->node_data)
					return true;
				second_traveler = second_traveler->next_node;
			}
			first_traveler = first_traveler->next_node;
		}
	}
	return false;
}

template <typename T>
void List<T>::dedup() {
	List<T> stack;
	unsigned int counter = 0;
	while (counter <= m_length) {
		T suspect = get_node(counter)->node_data;
		if (stack.find(suspect) != -1)
			stack.insert(suspect);
		remove(suspect);
		counter++;
	}
	stack.clear();
}

template <typename T>
void List<T>::display() {
	Node* traveler = m_start;
	while (traveler != END) {
		std::cout << traveler->node_data << " -> ";
		traveler = traveler->next_node;
	}
	std::cout << " END" << std::endl;
}

template <typename T>
void List<T>::display_from(unsigned int starting_index) {
	if (starting_index > m_length)
		std::cout << " END" << std::endl;
	else {
		Node* traveler = get_node(starting_index);
		while (traveler != END) {
			std::cout << traveler->node_data << " -> ";
			traveler = traveler->next_node;
		}
		std::cout << " END" << std::endl;
	}
}

template <typename T>
int List<T>::find(const T& input_data) {
	Node* traveler = m_start;
	int index = 0;
	while (traveler != END) {
		if (traveler->node_data == input_data)
			return index;
		traveler = traveler->next_node;
		index++;
	}
	return NOT_FOUND;
}

template <typename T>
void List<T>::insert(const T& input_data) {
	Node* new_node = create_node(input_data);

	if (m_length == 0) {
		m_start = m_end = new_node;
		m_length++;
	}
	else {
		m_end->next_node = new_node;
		m_end = new_node;
		m_length++;
	}
}

template <typename T>
void List<T>::insert_head(const T& input_data) {
	Node* new_node = create_node(input_data);

	if (m_length == 0) {
		m_start = m_end = new_node;
		m_length++;
	}
	else {
		new_node->next_node = m_start;
		m_start = new_node;
		m_length++;
	}
}

template<typename T>
void List<T>::insert_at(const T& input_data, unsigned int index) {
	if (index == 0)
		insert_head(input_data);
	else if (index >= m_length)
		insert(input_data);
	else {
		Node* node_to_shift = get_node(index);
		Node* previous = get_node(index - 1);
		Node* new_node = create_node(input_data);

		previous->next_node = new_node;
		new_node->next_node = node_to_shift;
		m_length++;
	}
}

template <typename T>
List<T>& List<T>::intersect(const List<T>& second_list) {
	List<T> intersection_list;

	Node* first_traveler = m_start;
	Node* second_traveler = second_list.m_start;
	while (first_traveler != END || second_traveler != END) {
		// Maybe Recursion or DP is implemented here
	}
}

template <typename T>
void List<T>::join(List<T>& second_list) {
	m_end->next_node = second_list.get_node(0);
	m_end = second_list.get_node(second_list.m_length - 1);
	m_length += second_list.m_length;
}

template <typename T>
size_t List<T>::length() const {
	return m_length;
}

template <typename T>
bool List<T>::palindrome() {
	bool isPalindrome = false;

	if (m_length != EMPTY) {
		for (int i = 0; i < m_length / 2; i++) {
			T _front = get_node(i)->node_data;
			T _end = get_node(m_length - (i + 1))->node_data;
			if (_front == _end)
				isPalindrome = true;
			else
				isPalindrome = false;
		}
		return isPalindrome;
	}
	return isPalindrome;
}

template <typename T>
T& List<T>::peek_head() const {
	return m_start->node_data;
}

template <typename T>
T& List<T>::peek_middle() const {
	return get_node(m_length / 2)->node_data;
}

template <typename T>
T& List<T>::peek_tail() const {
	return m_end->node_data;
}

template <typename T>
T& List<T>::random() const {
	srand((unsigned)time(NULL));
	unsigned int index = rand() % m_length;
	return get_node(index)->node_data;
}

template <typename T>
void List<T>::remove(const T& to_remove) {
	if (m_start != END) {
		int index = find(to_remove);
		if (index != NOT_FOUND) {
			if (index == 0) {
				remove_head();
			}
			else if (index == m_length - 1) {
				remove_tail();
			}
			else {
				Node* previous = get_node(index - 1);
				Node* to_remove = previous->next_node;
				Node* next = to_remove->next_node;

				to_remove->next_node = END;
				previous->next_node = next;
				delete to_remove;
				m_length--;
			}
		}
	}
}

template <typename T>
void List<T>::remove_all(const T& to_remove) {
	if (m_length != EMPTY) {
		while (find(to_remove) != NOT_FOUND) {
			remove(to_remove);
		}
	}
}

template <typename T>
void List<T>::remove_at(const unsigned int& index) {
	if (m_length != EMPTY) {
		if (index == 0) {
			remove_head();
		}
		else if (index = m_length - 1) {
			remove_tail();
		}
		else {
			Node* previous = get_node(index - 1);
			Node* to_remove = previous->next_node;
			Node* next = to_remove->next_node;

			to_remove->next_node = END;
			previous->next_node = next;
			delete to_remove;
			m_length--;
		}
	}
}

template <typename T>
void List<T>::reverse() {
	Node* temp_ptr = END;
	Node* next_ptr = END;
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
}

template <typename T>
void List<T>::shuffle() {
	List<T> shuffled;
	while (m_length != EMPTY) {
		T random_data = this->random();
		shuffled.insert(random_data);
		this->remove(random_data);
	}
	this->clear();
	unsigned int counter = 0;
	while (counter < shuffled.m_length) {
		this->insert(shuffled[counter]);
		counter++;
	}
	shuffled.clear();
}

template <typename T>
size_t List<T>::size() {
	return sizeof(T) * m_length;
}

template<typename T>
void List<T>::sort(bool ASC) {
	if (m_length != EMPTY) {
		if (ASC) {
			int i = 0;
			int j = 1;
			while (i < m_length) {
				while (j < m_length - i) {
					auto current = get_node(j)->node_data;
					auto next = get_node(j + 1)->node_data;
					if (current > next)
						swap(j, j + 1);
					display();
					j++;
				}
				i++;
			}
		}
		else {
			int i = 0;
			int j = 1;
			while (i < m_length) {
				while (j < m_length - i) {
					auto current = get_node(j)->node_data;
					auto next = get_node(j + 1)->node_data;
					if (current < next)
						swap(j, j + 1);
					display();
					j++;
				}
				i++;
			}
		}
	}
}

template <typename T>
Pair<List<T>> List<T>::split(unsigned int split_from_index) {
	List<T> first_halve, second_halve;
	Pair<List<T>> split_pair(first_halve, second_halve);

	if (m_length != EMPTY) {
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

			first_halve.clear();
			second_halve.clear();

			return split_pair;
		}
		else
			return split_pair;
	}
	return split_pair;
}

template <typename T>
void List<T>::trim_head(unsigned int trim_by) {
	if (trim_by < m_length)
		for (auto counter : trim_by)
			remove_head();
}

template <typename T>
void List<T>::trim_tail(unsigned int trim_by) {
	if (trim_by < m_length)
		for (auto counter : trim_by)
			remove_tail();
}

template <typename T>
void List<T>::remove_head() {
	if (m_length != EMPTY)
	{
		Node* new_start = m_start->next_node;
		delete m_start;
		m_start = new_start;
		--m_length;
	}
}

template <typename T>
void List<T>::remove_tail() {
	if (m_length != EMPTY)
	{
		Node* new_end = get_node(m_length - 2);
		new_end->next_node = END;
		delete m_end;
		m_end = new_end;
		--m_length;
	}
}

template<typename T>
void List<T>::swap(unsigned int A, unsigned int B) {
	if (abs(B - A) == 1) {
		if (A == 0) {
			Node* Node_A = m_start;
			Node* Node_B = Node_A->next_node;
			Node* b_Next = Node_B->next_node;

			Node_A->next_node = b_Next;
			Node_B->next_node = Node_A;
			m_start = Node_A;
		}
		else {
			Node* a_Prev = get_node(A - 1);
			Node* Node_A = get_node(A);
			Node* Node_B = Node_A->next_node;
			Node* b_Next = Node_B->next_node;
			Node* temp = b_Next;

			a_Prev->next_node = Node_B;
			Node_B->next_node = Node_A;
			Node_A->next_node = temp;
		}
	}
	else {
		if (A == 0) {
			Node* Node_A = m_start;
			Node* a_Next = Node_A->next_node;
			Node* b_Prev = get_node(B - 1);
			Node* Node_B = b_Prev->next_node;
			Node* b_Next = Node_B->next_node;
			Node* temp = a_Next;
			Node* temp_2 = b_Next;

			Node_B->next_node = temp;
			Node_A->next_node = temp_2;
			b_Prev->next_node = Node_A;
			m_start = Node_B;

		}
		else {
			Node* a_Prev = get_node(A - 1);
			Node* Node_A = a_Prev->next_node;
			Node* a_Next = Node_A->next_node;
			Node* b_Prev = get_node(B - 1);
			Node* Node_B = b_Prev->next_node;
			Node* b_Next = Node_B->next_node;
			Node* temp = Node_A;
			Node* temp_2 = b_Next;

			a_Prev->next_node = Node_B;
			Node_B->next_node = a_Next;
			b_Prev->next_node = temp;
			Node_A->next_node = temp_2;
		}
	}
}