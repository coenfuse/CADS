#pragma once

#include<iostream>
#include<time.h>
#include"..\UTIL.h"

#define END nullptr
#define NONE nullptr
#define NOT_FOUND -1
#define EMPTY 0

namespace learn
{
	// Singly linked list
	template<typename T>
	class List {

		struct Node {
			T node_data;
			Node* next_node;

			Node() : node_data(), next_node(END) {}
			Node(T input_data, Node* new_next_node = END) {
				node_data = input_data;
				next_node = new_next_node;
			}
			~Node() {}

			Node operator++() {
				return this->next_node;
			}
			Node operator++(int) {
				Node before_increment = this;
				this = this->next_node;
				return before_increment;
			}
		};

	private:
		// List attributes
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
				return nullptr;
		}

		Node* create_node(T input_data) {
			return new Node(input_data);
		}

		bool compare(List<T>&) const;
		void remove_head();
		void remove_tail();
		List<T>& local_intersection(Node*, Node*);

	public:

		class iterator;
		class const_iterator;
		class reverse_iterator;
		class const_reverse_iterator;

		List<T>();
		List<T>(T input_data);
		List<T>(List<T>& second_list);
		~List<T>();

		void add(List<T>&);
		T& at(const unsigned int index) const;
		void clear();
		bool common(List<T>&);
		void dedup();
		void display();
		void display_from(unsigned int);
		bool empty();
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
		void remove_at(unsigned int&);
		void reverse();
		void shuffle();
		size_t size();
		void sort(bool ASC = true);
		Pair<List<T>>& split(unsigned int);
		void swap(unsigned int, unsigned int);
		void trim_head(unsigned int);
		void trim_tail(unsigned int);

		T& operator[](size_t);
		T& operator[](size_t) const;
		bool operator==(List<T>&) const;
		bool operator!=(List<T>&) const;
		bool operator<(List<T>&) const;
		bool operator>(List<T>&) const;
		bool operator<=(List<T>&) const;
		bool operator>=(List<T>&) const;
		void operator+(List<T>&);
		void operator=(List<T>&);

		iterator begin() { return iterator(m_start); }
		iterator end() { return iterator(nullptr); }
		const_iterator cbegin() const { return const_iterator(m_start); }
		const_iterator cend() const { return const_iterator(nullptr); }
		reverse_iterator rbegin() { return reverse_iterator(m_end); }
		reverse_iterator rend() { return reverse_iterator(nullptr); }
		const_reverse_iterator crbegin() const { return const_reverse_iterator(m_end); }
		const_reverse_iterator crend() const { return const_reverse_iterator(nullptr); }
	};

	template <typename T>
	List<T>::List() : m_length(0), m_start(END), m_end(END) {}

	template<typename T>
	List<T>::List(T input_data) {
		Node* new_node = create_node(input_data);
		m_start = m_end = new_node;
		m_length++;
	}

	template<typename T>
	List<T>::List(List<T>& second_list) {
		clear();
		add(second_list);
	}

	template <typename T>
	List<T>::~List<T>() {}	// { clear(); } <- SEE DOCUMENTATION

	template <typename T>
	T& List<T>::operator[](size_t index) {
		if (index == 0)
			return m_start->node_data;
		else
			return get_node((unsigned int)index)->node_data;
	}

	template <typename T>
	T& List<T>::operator[](size_t index) const {
		if (index == 0)
			return m_start->node_data;
		else
			return get_node((unsigned int)index)->node_data;
	}

	template <typename T>
	bool List<T>::operator==(List<T>& second_list) const {
		if (m_length == second_list.m_length)
			return compare(second_list);
		else
			return false;
	}

	template <typename T>
	bool List<T>::operator!=(List<T>& second_list)const {
		if (m_length != second_list.m_length)
			return false;
		else
			return !compare(second_list);
	}

	template <typename T>
	void List<T>::operator+(List<T>& second_list) {
		add(second_list);
	}

	template <typename T>
	void List<T>::operator=(List<T>& second_list) {
		clear();
		join(second_list);
	}

	template <typename T>
	bool List<T>::operator<(List<T>& second_list) const {
		return (m_length < second_list.m_length);
	}

	template <typename T>
	bool List<T>::operator>(List<T>& second_list) const {
		return (m_length > second_list.m_length);
	}

	template <typename T>
	bool List<T>::operator<=(List<T>& second_list) const {
		return (m_length <= second_list.m_length);
	}

	template <typename T>
	bool List<T>::operator>=(List<T>& second_list) const {
		return (m_length >= second_list.m_length);
	}

	template <typename T>
	void List<T>::add(List<T>& second_list) {

		unsigned int traverse_length = second_list.m_length;
		unsigned int local_counter = 0;
		while (local_counter < traverse_length) {
			insert(second_list[local_counter]);
			local_counter++;
		}
		second_list.clear();
	}

	template <typename T>
	T& List<T>::at(const unsigned int index) const {
		if (index > m_length)
			return m_end->node_data;
		else if (index == 0)
			return m_start->node_data;
		else
			return get_node(index)->node_data;
	}

	template <typename T>
	void List<T>::clear() {
		Node* traveler = m_start;
		while (traveler != END) {
			Node* to_delete = traveler;
			traveler = traveler->next_node;
			delete to_delete;
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
					T inner_element = second_traveler->node_data;
					T outer_element = first_traveler->node_data;
					if (inner_element == outer_element)
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
		List<T> unique;
		Node* traveler = m_start;
		while (traveler != END) {
			T suspect = traveler->node_data;
			if (unique.find(suspect) == NOT_FOUND)
				unique.insert(suspect);
			traveler = traveler->next_node;
		}
		clear();

		m_start = unique.m_start;
		m_end = unique.m_end;
		m_length = unique.m_length;
	}

	template <typename T>
	void List<T>::display() {
		Node* traveler = m_start;
		while (traveler != END) {
			std::cout << traveler->node_data << " -> ";
			traveler = traveler->next_node;
		}
		std::cout << "END" << std::endl;
	}

	template <typename T>
	void List<T>::display_from(unsigned int starting_index) {
		if (starting_index > m_length)
			std::cout << "END" << std::endl;
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
	bool List<T>::empty() {
		return m_length == 0;
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
			Node* previous = get_node(index - 1);
			Node* node_to_shift = previous->next_node;
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
		while (first_traveler != END) {
			while (second_traveler != END) {
				if (first_traveler->node_data == second_traveler->node_data) {
					intersection_list.join(local_intersection(first_traveler->next_node, second_traveler->next_node));
				}
				second_traveler = second_traveler->next_node;
			}
			first_traveler = first_traveler->next_node;
		}
		return intersection_list;
	}

	template <typename T>
	void List<T>::join(List<T>& second_list) {
		if (m_length == EMPTY) {
			m_start = second_list.m_start;
			m_end = second_list.m_end;
			m_length = second_list.m_length;
		}
		else {
			m_end->next_node = second_list.m_start;
			m_end = second_list.m_end;
			m_length += second_list.m_length;
		}
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
	void List<T>::remove_at(unsigned int& index) {
		if (m_length != EMPTY) {
			if (index == 0) {
				remove_head();
			}
			else if (index >= m_length - 1) {
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
			if (counter == 0)
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

		m_start = shuffled.m_start;
		m_end = shuffled.m_end;
		m_length = shuffled.m_length;
	}

	template <typename T>
	size_t List<T>::size() {
		return sizeof(T) * m_length;
	}

	template<typename T>
	void List<T>::sort(bool ASC) {
		if (ASC) {
			if (!empty()) {
				List<T> sorted;
				while (!empty()) {
					size_t index = 0;
					if (sorted.empty()) {
						sorted.insert(peek_head());
						this->remove_head();
						//index++;
					}
					else {
						Node* sorted_traveler = sorted.m_start;
						while (sorted_traveler != nullptr) {
							if (peek_head() < sorted_traveler->node_data) {
								sorted.insert_head(peek_head());
								this->remove_head();
								//index++;
								break;	// To come out of loop
							}
							else if (peek_head() > sorted_traveler->node_data) {
								//sorted.insert_at(peek_head(), index);
								//this->remove_head();
								//index++;
								sorted.insert(peek_head());
								this->remove_head();
								//sorted_traveler = sorted_traveler->next_node;
								index++;
								break;
							}
							else if (sorted_traveler->next_node == nullptr) {
								sorted.insert(peek_head());
								this->remove_head();
								sorted_traveler = sorted.m_start;
								index = 0;
								break;
							}
							else {
								index++;
								sorted_traveler = sorted_traveler->next_node;
							}
							//sorted.display();
						}
					}
				}//sorted.display();
			}
		}
		else {
			size_t index = 0;
			Node* traveler = m_start;
			while (traveler != nullptr) {
				auto current = traveler->node_data;
				auto next = traveler->next_node;
				if (next == nullptr)
					break;
				//auto next_data = next->node_data;
				else if (current > next->node_data) {
					traveler = traveler->next_node;
					swap(index, index + 1);
					index++;
					//display();
				}
				else {
					index++;
					traveler = traveler->next_node;
					if (traveler == nullptr)
						traveler = m_start;
					//display();
				}
			}
			//display();

			// sort
			// reverse
			// join
		}
	}

	template <typename T>
	Pair<List<T>>& List<T>::split(unsigned int split_from_index) {
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

				return split_pair;
			}
			else
				return split_pair;
		}
		return split_pair;
	}

	template<typename T>
	void List<T>::swap(unsigned int A, unsigned int B) {

		// Issues:
		// Abnormal Behavior when swap index is (last, first)
		// Abnormal reduction in list's length by one when index is (first,second)
		// No bounds check



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

	template <typename T>
	void List<T>::trim_head(unsigned int trim_by) {
		/*
		ITERATOR METHOD

		if (trim_by < m_length)
			for (auto counter : trim_by)
				remove_head();
		*/

		short trim_amount = m_length - trim_by;
		if (trim_amount > 0) {
			if (m_length == trim_by) {
				clear();
			}
			else {
				unsigned int counter = 0;
				while (counter < trim_by) {
					remove_head();
					counter++;
				}
			}
		}
	}

	template <typename T>
	void List<T>::trim_tail(unsigned int trim_by) {
		/*
		ITERATOR METHOD

		if (trim_by < m_length)
			for (auto counter : trim_by)
				remove_tail();
		*/

		short trim_amount = m_length - trim_by;
		if (trim_amount > 0) {
			if (m_length == trim_by) {
				clear();
			}
			else {
				unsigned int counter = 0;
				while (counter < trim_by) {
					remove_tail();
					counter++;
				}
			}
		}
	}

	template<typename T>
	bool List<T>::compare(List<T>& second_list) const {
		bool response = false;
		Node* this_traveler = m_start;
		Node* second_traveler = second_list.m_start;

		while (this_traveler != END) {
			if (this_traveler->node_data == second_traveler->node_data) {
				response = true;
				this_traveler = this_traveler->next_node;
				second_traveler = second_traveler->next_node;
			}
			else {
				response = false;
				break;
			}
		}
		return response;
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

	template <typename T>
	List<T>& List<T>::local_intersection(Node* first_traveler, Node* second_traveler) {
		List<T> intersection;
		if (first_traveler == END || second_traveler == END) {
			return intersection;
		}
		else if (first_traveler->node_data == second_traveler->node_data) {
			intersection.join(local_intersection(first_traveler->next_node, second_traveler->next_node));
			return intersection;
		}
		else
			return intersection;
	}

	template<typename T>
	class List<T>::iterator {
		Node* m_node;

	public:

		iterator() :
			m_node(nullptr){}

		iterator(Node* _init) :
			m_node(_init){}

		// Copy ctor and dtor not implemented. Why?

		iterator& operator=(Node& _other) {
			m_node = _other;
			return *this;
		}

		iterator& operator++() {
			m_node = m_node->next_node;
			return *this;
		}

		iterator& operator++(int) {
			iterator temporary = *this;
			++* this;
			return temporary;
		}

		bool operator==(const iterator& _other) {
			return m_node == _other.m_node;
		}

		bool operator!=(const iterator& _other) {
			return m_node != _other.m_node;
		}

		T& operator*() {
			return m_node->node_data;
		}

	};

	template <typename T>
	class List<T>::const_iterator {

		const Node* m_node;

	public:

		const_iterator() :
			m_node(nullptr){}

		const_iterator(const Node* _init) :
			m_node(_init){}

		// Copy ctor and dtor not implemented. Why?

		const_iterator& operator=(const Node* _other) {
			m_node = _other;
			return *this;
		}

		const_iterator& operator++() {
			m_node = m_node->next_node;
			return *this;
		}

		const_iterator& operator++(int) {
			const_iterator temporary = *this;
			++* this;
			return temporary;
		}

		bool operator==(const const_iterator& _other) {
			return m_node == _other.m_node;
		}

		bool operator!=(const const_iterator& _other) {
			return m_node != _other.m_node;
		}

		const T& operator*() {
			return m_node->node_data;
		}
	};

	template<typename T>
	class List<T>::reverse_iterator {

		Node* m_node;

	public:
		
		reverse_iterator() :
			m_node(nullptr){}

		reverse_iterator(Node* _init) :
			m_node(_init){}

		// Copy ctor and dtor not implemented. Why?

		reverse_iterator& operator=(Node* _other) {
			m_node = _other;
			return *this;
		}

		reverse_iterator& operator++() {
			// The sandbagging function of this class.
			return *this;
		}

		reverse_iterator& operator++(int) {
			reverse_iterator temporary = *this;
			++* this;
			return temporary;
		}

		T& operator*() {
			return m_node->node_data;
		}
	};

	template<typename T>
	class List<T>::const_reverse_iterator {

		const Node* m_node;

	public:

		const_reverse_iterator() :
			m_node(nullptr){}

		const_reverse_iterator(const Node* _init) :
			m_node(_init){}

		// Copy ctor and dtor not implemented. Why?

		const_reverse_iterator& operator=(const Node* _other) {
			m_node = _other;
			return *this;
		}

		const_reverse_iterator& operator++() {
			// The sandbagging function of this class
			return *this;
		}

		const_reverse_iterator& operator++(int) {
			const_reverse_iterator temporary = *this;
			++* this;
			return temporary;
		}

		bool operator==(const const_reverse_iterator& _other) {
			return m_node == _other.m_node;
		}

		bool operator!=(const const_reverse_iterator& _other) {
			return m_node != _other.m_node;
		}

		const T& operator*() {
			return m_node->node_data;
		}
	};
}

// DOCUMENTATION:

/* TO-DO:
* -----------------------------------------------------------------------------
* Iterators (NOT TESTED)
* Initializer List
* Don't Overloaded operators for Node (Almost there) [ Do not overload stuff u-
* nless extremely necessary. If it makes code unreadable its a simple no go.]
* ::npos for at()
* Bounds checking in swap()
* Improve sort()
* Improve palindrome()
* Improve intersect()
*/

// PUBLIC INTERFACE

// List(List&) -> STATUS: Uncertain
// Copy constructor. Initializes current list by copying all the elements of a-
// nother list into itself.
// Complexity: O(n)

//~List() -> STATUS: Uncertain
//-----------------------------------------------------------------------------
// Previously it has clear() inside it that has the responsibility of dealloca-
// ting all the nodes that might have been inside the list. But doing so posed
// problems in other functions that makes use of another List object inside of
// them. For example, in dedup() a List named 'unique'. After the operation is
// finished the head and tail as well as the length variable are attached (not
// copied) to the current list. But once the dedup() function is finished the
// List obj goes out of scope thereby rendering the attachments as invalid.
// Thus, whenever the List object goes out of scope, it becomes an orphan list
// and it is the responsibility of the user to deallocate all the memory that
// has been occupied by the list manually by invoking the clear() function.

// add() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Adds another list into the parent list. It destroys the child list after
// operation. It copies each node from child to parent thus is extremely slow.
// Complexity: O(n)

// at() -> STATUS: Incomplete
//-----------------------------------------------------------------------------
// Currently returns the value at the end of the node whenever the index is out
// of bounds. Need to incorporate a procedure that return something other than
// T to make more usable in real scenarios. The following is used in STL.
// static constexpr auto npos{ static_cast<T>(-1) };
// Complexity: O(n) or O(1)

// clear() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Clears the list and release all the memory that it has been occupying by
// deleting all the nodes fron the system. Time complexity O(n).

// common() -> STATUS: Abnormal behavior in IDE
//-----------------------------------------------------------------------------
// Returns true if any of the list contains a common element. Complexity: O(n*m)

// dedup() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Removes all the duplicate elements from the list. It iterates over the given
// list and adds individual elements on a unique list. The insertion in unique
// list is done by checking if there doesn't exists any previous copy of the
// element in it. If it does, the insertion skips one iteration. Once finished
// the current list is cleared and then unique list is joined to it.
// Complexity is O(2*n) = O(iteration) + O(clear) + 2 * O(1). Here, O(1)=join.

// display() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Fancy function to print whole list on the console.
// Complexity: O(n)

// display_from() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Prints list from given index to end on the console.
// It first iterates to the node from which it would start displaying the list.
// Takes it as the starting index and prints all the rest of data on console.
// Complexity: O(n)

// empty() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Returns a bool value representing whether the list is empty or not.
// Complexity: O(1)

// find() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Performs linear search on the list and finds the input element.
// Returns element's index if found otherwise returns -1
// Complexity: O(n)

// insert() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Inserts a new element at the end of the list.
// Complexity: O(1)

// insert_at() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Inserts a new element at the specified index in the list.
// It first iterates to the node after which the new element is to be inserted.
// Obtains the 'node_to_shift' from previous's next pointer and adds the new
// node in between them.
// The worst case is when the index is just before the end of the list because
// then the function would have to run for (length - index) iterations. So, O(i)
// If index >= length then insertion is done at the end that is O(1). Thus,
// Complexity: O(i) or O(1) where i is the index at which the insertion is done

// insert_head() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Inserts a new element at the head of the list
// Complexity: O(1);

// intersect() -> STATUS: Not Working
//-----------------------------------------------------------------------------
// Returns a List object that contains the longest common sub-list present bet-
// ween the two lists. To accomplish this, this method tries to use recursion
// where at each level of recursion a new list is created that contains each
// common element of the list. Once the recursion ends by being true to one of
// the mentioned conditions. It traverses back by joining every list that has
// been created in each stage of the recursion.
// Complexity: O(n*m)

// join() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Joins the two list together while maintaining the integrity of the second l-
// ist. It does so by attaching the head of the second list at the end of the
// first list, overwriting the current end by the end of the second list and
// adding the lengths of both the list together to create a new length. No cop-
// ying of the nodes or element is done. Thus, it is exponentially faster than
// add() method but has a drawback. For the joined list to work properly, the
// second list has to stay in scope as long as the first list stays in system.
// If the second list goes out of scope (get deallocated) before the first list
// then it would make the first list's end and length invalid. Thereby causing
// illegal memory access errors.
// Complexity: O(1)

// length() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Returns an integer denoting the current amount of nodes present in the list.
// Complexity: O(1)

// operator[] -> STATUS: Complete
//-----------------------------------------------------------------------------
// Used to access element present at the given index in the list. Unlike at()
// it doesn't feature bounds checking thus throws exception whenver the limits
// are violated.
// Complexity: O(n);

// const operator[] -> STATUS: Complete
//-----------------------------------------------------------------------------
// If the list happens to be initialized as a const type then this operator
// doesn't works for both reading and writing operation. Thus it is needed
// to write a const overload for this operator.
// Complexity: O(n)

// operator== -> STATUS: Complete
//-----------------------------------------------------------------------------
// Returns TRUE if the two lists are identical to each other.
// Complexity: O(n)

// operator!= -> STATUS: Complete
//-----------------------------------------------------------------------------
// Returns TRUE if the two lists are NOT identical to each other.
// Complexity: O(n)

// operator< -> STATUS: Complete
//-----------------------------------------------------------------------------
// Returns TRUE if this.length < second_list.length;
// Complexity: O(1)

// operator> -> STATUS: Complete
//-----------------------------------------------------------------------------
// Returns TRUE if this.length > second_list.length;
// Complexity: O(1)

// operator<= -> STATUS: Complete
//-----------------------------------------------------------------------------
// Returns TRUE if this.length <= second_list.length;
// Complexity: O(1)

// operator>= -> STATUS: Complete
//-----------------------------------------------------------------------------
// Returns TRUE if this.length >= second_list.length;
// Complexity: O(1)

// operator+ -> STATUS: Complete
//-----------------------------------------------------------------------------
// Adds two lists together. Destroys the second list.
// Complexity: O(n)

// operator= -> STATUS: Complete
//-----------------------------------------------------------------------------
// Clears the current list and attaches the second list over it.
// Complexity: O(1)

// palindrome() -> STATUS: Incomplete
//-----------------------------------------------------------------------------
// Returns TRUE if there is a palindrome inside the linked list symmetric from
// the center. If the list has a palindrome anywhere beyond the middle of the
// list then It is not detected. It works by creating two data containers that
// carry value from the head and end of the list respectively. At each iterati-
// on of the loop, the variables contain the next element from the list (end v-
// ariable contains previous element). The time_complexity of this procedure is
// driven by obtaining the value at the end. That process takes O(n) time at e-
// ach iteration and since the length of end is reduced by one at each iteration
// Complexity: O(n!) estimated

// peek_head() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Returns the value present at the head of the list
// Complexity: O(1)

// peek_middle() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Returns the value present at the middle of the list.
// Uses whole number as indexing an rounds off by upper ceiling if the list is
// of odd length.
// Complexity: O(n)/2

// peek_tail() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Returns the value present at the end of the list
// Complexity: O(1)

// random() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Returns a random element from the list
// Complexity: O(n)

// remove() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Removes the first occurence of the input data from the list.
// Complexity: O(n)

// remove_all() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Removes all the occurence of the given data from the list.
// Complexity: O(n)

// remove_at() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Removes the element present at the specified index from the list.
// Complexity: O(n) or O(1)

// reverse() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Reverses the whole list start to end. It does so by flipping all the pointer
// backwards to the previous nodes and using temporary containers to carry
// orphan sublists.
// Complexity: O(n)
/* The idea is as follows:

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

// shuffle() -> STATUS: Complete
//-----------------------------------------------------------------------------
// It creates a new list named 'shuffled' and fills it by randomly accessing
// the current list and at each iteration deletes the first occurence of the
// accessed element from the current list. Thereby emptying the current list
// at the end of the operation. Then it joins start and end pointers of the
// shuffled list to the current node.
// Complexity: O(n)
/* List<T> shuffled;						Prep: New shuffled list will be here.
   while (m_length != EMPTY) {				Step 1: Initiate a loop that runs till the length of the current List
		T random_data = this->random();		Step 2: Store data of random node in a variable
		shuffled.insert(random_data);		Step 3: Insert the random data into shuffled list.
		this->remove(random_data);			Step 4: Remove the first occurence of random data from current list. Thereby reducing m_length by 1 automatically.
*/

// size() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Returns the size of the list in bytes. It does so by multiplying the data
// type of the list with its current length.
// Complexity: O(1)

// sort() -> STATUS: Incomplete
//-----------------------------------------------------------------------------
// Complexity: TBA

// split() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Returns reference to a List<T> pair that contains two halves of the splitted
// list in it. Both the halves can be accessed with 'first' & 'second' keyword.
// The method splits the list by iterating till the split_index and copies each
// element it has traveled into a splitted half that is wrapped in Pair object.
// This method doesn't ruins the integrity of the original list.

// NOTE: A more true to its name implementation might be just trimming the
// parent list from the end to the splitting index and returning a new list
// that just contains the trimmed elements. The new list will represent the
// second half whereas the parent list would be the first half. But I chose
// to not do this primarily on the 'What if?' factor. What if the end user
// wanted to keep the original list preserved and just wanted to create a
// new copy of splitted parts for whatever usage?
// Complexity: O(n)

// swap() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Swaps the nodes present in the list at the given index.
// Currently doesn't not perform a bounds check. Throws exception instead.
// It has 4 variants inside it that works differently:
/*
	================================================		
			When ( A - B == 1 && A == 0 )
	================================================
	Node_A->next_node = bNext;		// Step 1
	Node_B->next_node = Node_A;		// Step 2
	m_start = Node_B;				// Step 3

	(INITIAL STATE):	A -> B -> b		(m_start = A)

	After Step 1:
	A -> b			(m_start = A)
		 |
		 '<- B

	After Step 2:
	B -> A -> b		(m_start = A)

	After Step 3:
	B -> A -> b		(m_start = B)

	================================================
			When ( A - B == 1 && A != 0 )
	================================================
	aPrev->next_node = Node_B;		// Step 1
	Node_B->next_node = temp;		// Step 2
	Node_A->next_node = temp_2;		// Step 3

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

	================================================
			When ( A - B != 1 && A == 0 )
	================================================
	Node_B->next_node = aNext;	// Step 1
	Node_A->next_node = bNext;	// Step 2
	bPrev->next_node = Node_A;	// Step 3
	m_start = Node_B;			// Step 4

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

	================================================
			When ( A - B != 1 && A != 0 )
	================================================
	temp = Node_A; temp_2 = bNext;	// Step 1
	aPrev->next_node = Node_B;		// Step 2
	Node_B->next_node = aNext;		// Step 3
	bPrev->next_node = temp;		// Step 4
	Node_A->next_node = temp_2;		// Step 5

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
// Complexity: O(n)

// trim_tail() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Trims the list from the front by the specified amount.
// Primary intinct to solve this problem would be just detaching all the
// nodes from the list after a particular index (The index can be found by
// subtracting trim_amount from the length of the string). But doing so will
// cause serious memory leaks and orphan nodes. Thus, implementation needs
// confirmed deletion of the trimmed nodes from the system memory.
// Complexity: O(n)

// trim_head() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Just like explained in trim_tail(), the primary solution for this fx
// would be just assigning m_start with whatever node that is present at
// trim_amount index. Subsequently orphaning all the nodes preceding it.
// That would cause memory leakage thus it is necessary to delete all the
// unwanted nodes from the system memory.
// Complexity: O(n)

// PRIVATE INTERFACE:

// compare() -> STATUS: Complete
//-----------------------------------------------------------------------------
// 
// Complexity: O(1)

// remove_head() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Node* new_start = m_start->next_node;	Step 1: Storing the current start in a temporary variable
// delete m_start;							Step 2: Overwriting the start with its 'next_node', thereby making the 'next_node' a new start of the list.
// m_start = new_start;						Step 3: Deleting temp (previous start) and releasing memory.
// --m_length;								Step 4: Reducing the length of the list by one.

// Note: This function will work fine without Step 1 and Step 3,
// but I wrote them to release memory occupied the 'previous' start.
// Complexity: O(1)

// remove_tail() -> STATUS: Complete
//-----------------------------------------------------------------------------
// Node* new_end = get_node(m_length - 2);		Step 1: Fetching the node previous to the end.
// new_end->next_node = END;					Step 2: Bypassing the current 'end' by directly pointing 'new_end' to nullptr
// delete m_end;								Step 3: Now the current end is detached from the list, we can delete it from memory.
// m_end = new_end;								Step 4: Making the 'new_node' node a new end of the system.
// --m_length;									Step 5: Reducing the length of the list by one.

// Note 1: m_length is natural number, meanwhile the internal indexing uses
// whole numbers, i.e: the list starts from 0. So,
// get_node(m_length) returns nullptr,
// get_node(m_length) returns pointer to the end node.
// and, get_node(m_length - 2) returns the node prior to end node.
//	
// Note 2: This program will work fine if we ignore Step 3, but it is not recommended. Figure out why.
// Complexity: O(1)

// local_intersection -> STATUS: Incomplete
//-----------------------------------------------------------------------------
// Complexity: O(n!)