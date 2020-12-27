#pragma once
#include <iostream>
#include<list>

namespace CADS
{
	template <typename T>
	class List {

		#include <initializer_list>
		#define NOT_FOUND -1
		#define EMPTY 0

	private:

		struct Node {
			T node_data;
			Node* next;
			Node* previous;
		
			Node() :node_data(), next(nullptr), previous(nullptr) { }
			Node(const T& _init_data) :node_data(_init_data), previous(nullptr), next(nullptr) {}
			~Node() { }									// INCOMPLETE

			/*
			Node& operator=(const Node* _other) {
				node_data = _other->node_data;
				next = _other->next;
				previous = _other->previous;
				return *this;
			}
			bool operator==(Node& other) {
				return (next == other.next && previous == other.previous && node_data == other.node_data);
			}

			bool operator!=(Node& other) {
				return !(this==other);
			}
		
			Node& operator++() {
				return *(this->next);
			}
			Node& operator++(int) {
				Node temp = *this;
				++* this;
				return temp;
			}
			Node& operator--() {
				return *(this->previous);
			}
			Node& operator--(int) {
				Node temp = this;
				--* this;
				return temp;
			}
			*/
		};

	private:

		Node* create_node(const T& init_data) {
			return new Node(init_data);
		}
		Node* get_node(size_t index) {
			Node* traveler = nullptr;
			if (index < m_length && index >= 0) {
				size_t traverse_distance = m_length - index;
				if (index <= traverse_distance) {
					Node* traveler = m_head;
					size_t counter = 0;
					while (traveler != nullptr) {
						if (counter == index)
							return traveler;
						traveler = traveler->next;
						//traveler++;
						counter++;
					}
					return traveler;
				}
				else {
					Node* traveler = m_tail;
					size_t counter = m_length - 1;
					while (traveler != nullptr) {
						if (counter == index)
							return traveler;
						traveler = traveler->previous;
						//traveler--;
						counter--;
					}
					return traveler;
				}
			}
			return traveler;
		}
		bool compare(List<T>&);

	private:

		size_t m_length;
		Node* m_head;
		Node* m_tail;

	public:

		class iterator;
		class const_iterator;
		class reverse_iterator;
		class const_reverse_iterator;
		class init_list;

		// List() = default;		Weird syntax :/
		List() :m_length(0), m_head(nullptr), m_tail(nullptr){}
		List(const T& _init_data);
		List(List<T>& _copy_this);
		List(std::initializer_list<T>& init_list);		// INCOMPLETE
		~List(){} // { this->clear(); }					// Why?

		T& at(const size_t& index);
		const T& at(const size_t& index) const;
		void clear();
		void display() const;
		void erase(const T& _to_erase);
		bool empty() const;
		void emplace_front();							// INCOMPLETE
		void emplace_back();							// INCOMPLETE
		void emplace(const size_t _emplace_at);			// INCOMPLETE
		size_t find(T& _to_find);
		void push_front(const T&);
		void push_back(const T&);
		void push(const size_t& _insert_at, const T& _data);
		void join(List<T>&);
		T& peek_front();
		T& peek_front() const;
		T& peek_back();
		T& peek_back() const;
		T& pop_front();
		T& pop_back();
		T& pop(const size_t& _remove_at);
		T& pop(iterator&);								
		T& pop(const_iterator) const;					// INCOMPLETE
		T& pop(reverse_iterator&);						// INCOMPLETE
		T& pop(const_reverse_iterator) const;			// INCOMPLETE
		void reverse();
		const size_t size() const;
		void sort();

		T& operator[](const size_t&);
		const T& operator[](const size_t&) const;
		bool operator==(List<T>&) const;
		bool operator!=(List<T>&) const;
		bool operator<(List<T>&) const;
		bool operator>(List<T>&) const;
		bool operator<=(List<T>&) const;
		bool operator>=(List<T>&) const;
		void operator+(List<T>&);
		void operator=(List<T>&);

		_NODISCARD iterator begin() { return iterator(m_head); }
		_NODISCARD iterator end() { return iterator(nullptr); }
		_NODISCARD reverse_iterator rbegin() { return reverse_iterator(m_tail); }
		_NODISCARD reverse_iterator rend() { return reverse_iterator(nullptr); }
		_NODISCARD const_iterator cbegin() const { return const_iterator(m_head); }
		_NODISCARD const_iterator cend() const { return const_iterator(nullptr); }
		_NODISCARD const_reverse_iterator crbegin() const { return const_reverse_iterator(m_tail); }
		_NODISCARD const_reverse_iterator crend() const { return const_reverse_iterator(nullptr); }
	};

	template <typename T>
	class List<T>::init_list {

	};

	// Constructor and Destructor definitions
	template <typename T>
	List<T>::List(const T& _init_data) {
		Node* new_node = create_node(_init_data);
		m_head = m_tail = new_node;
		new_node->next = nullptr;
		new_node->previous = nullptr;
		m_length++;
	}

	template <typename T>
	List<T>::List(List<T>& _copy_this) {
		clear();
		join(_copy_this);
	}

	template <typename T>
	List<T>::List(std::initializer_list<T>& init_list) : List(static_cast<T>(init_list.size())) {
		for (auto each : init_list)
			push_back(each);
		~List();
	}

	// Overloaded Operators definitions
	template<typename T>
	T& List<T>::operator[](const size_t& _index) {
		if (_index == m_length - 1)
			return m_tail->node_data;
		else if (_index == 0)
			return m_head->node_data;
		else
			return get_node(_index)->node_data;
	}
	template<typename T>
	const T& List<T>::operator[](const size_t& _index) const {
		if (_index == m_length - 1)
			return m_tail->node_data;
		else if (_index == 0)
			return m_head->node_data;
		else
			return get_node(_index)->node_data;
	}
	template <typename T>
	bool List<T>::operator==(List<T>& other) const {
		if (m_length == other.m_length) {
			return compare(other);
		}
		else
			return false;
	}
	template <typename T>
	bool List<T>::operator!=(List<T>& other) const {
		return !(this == other);
	}
	template <typename T>
	bool List<T>::operator<(List<T>& other) const {
		return (m_length < other.m_length);
	}
	template <typename T>
	bool List<T>::operator>(List<T>& other) const {
		return (m_length > other.m_length);
	}
	template <typename T>
	bool List<T>::operator<=(List<T>& other) const {
		return (m_length <= other.m_length);
	}
	template <typename T>
	bool List<T>::operator>=(List<T>& other) const {
		return (m_length >= other.m_length);
	}
	template <typename T>
	void List<T>::operator+(List<T>& other) {
		Node* traveler = other.m_head;
		while (traveler != nullptr) {
			insert_back(traveler->node_data);
			traveler = traveler->next;
		}
		other.clear();
	}
	template <typename T>
	void List<T>::operator=(List<T>& other) {
		clear();
		join(other);
	}

	// Iterator Implementations
	template <typename T>
	class List<T>::iterator {
		Node* m_node;
	public:
		iterator() :
			m_node(nullptr){}
		iterator(Node* _init) :
			m_node(_init){}
		// Copy constructor isn't defined yet

		iterator& operator=(Node* _other) {
			return *(this->m_node = _other);
		}
		iterator& operator++() {
			m_node = m_node->next;
			return *this;
		}
		iterator operator++(int) {
			iterator temp = *this;
			++* this;
			return temp;
		}
		bool operator==(const iterator& _other) {
			return (m_node == _other.m_node);
		}
		bool operator!=(const iterator& _other) {
			return (m_node != _other.m_node);
		}
		T& operator*() const {
			return m_node->node_data;
		}
		Node* get_prev() {
			return m_node->previous;
		}
		Node* get_next() {
			return m_node->next;	// or ++* this (But that wouldn't be much readable IMO)
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
		// Copy ctor is not defined yet

		const_iterator& operator=(const Node& _other) {
			return *(this->m_node = _other);
		}
		const_iterator& operator++() {
			m_node = m_node->next;
			return *this;
		}
		const_iterator operator++(int) {
			const_iterator temp = *this;
			++* this;
			return temp;
		}
		bool operator==(const const_iterator& _other) {
			return m_node == _other.m_node;
		}
		bool operator!=(const const_iterator& _other) {
			return m_node != _other.m_node;
		}
		const T& operator*() const {
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

		reverse_iterator& operator=(Node* _other) {
			return *(this->m_node = _other);
		}
		reverse_iterator& operator++() {
			m_node = m_node->previous;
			return *this;
		}
		reverse_iterator operator++(int) {
			reverse_iterator temp = *this;
			++* this;
			return temp;
		}
		bool operator==(const reverse_iterator& _other) {
			return (m_node == _other.m_node);
		}
		bool operator!=(const reverse_iterator& _other) {
			return (m_node != _other.m_node);
		}
		T& operator*() const {
			return m_node->node_data;
		}
		Node* get_prev() {
			return m_node->next;
		}
		Node* get_next() {
			return m_node->previous;
		}
	};

	template <typename T>
	class List<T>::const_reverse_iterator {
		const Node* m_node;
	public:
		const_reverse_iterator() :
			m_node(nullptr){}
		const_reverse_iterator(const Node* _init) :
			m_node(_init){}

		const_reverse_iterator& operator=(const Node* _other) {
			return *(this->m_node = _other);
		}
		const_reverse_iterator& operator++() {
			m_node = m_node->previous;
			return *this;
		}
		const_reverse_iterator operator++(int) {
			const_reverse_iterator temp = *this;
			++* this;
			return temp;
		}
		bool operator==(const const_reverse_iterator& _other) {
			return m_node == _other.m_node;
		}
		bool operator!=(const const_reverse_iterator& _other) {
			return m_node != _other.m_node;
		}
		const T& operator*() const {
			return m_node->node_data;
		}
	};

	// Private Method definitions

	template <typename T>
	bool List<T>::compare(List<T>& other) {
		bool response = false;
		Node* traveler = m_head;
		Node* other_traveler = other.m_head;

		while (traveler != nullptr) {
			if (traveler->node_data == other_traveler->node_data) {
				response = true;
				traveler = traveler->next;
				other_traveler = other_traveler->next;
			}
			else {
				response = false;
				break;
			}
		}
		return response;
	}

	// Interface definitions
	template<typename T>
	T& List<T>::at(const size_t& index) {
		return noexcept(get_node(index)->node_data);
	}
	template<typename T>
	const T& List<T>::at(const size_t& index) const {
		return noexcept(get_node(index)->node_data);
	}
	template <typename T>
	void List<T>::clear() {
		Node* traveler = m_head;
		//Node* temp;
		while (traveler != nullptr) {
			Node* temp = traveler->next;
			delete traveler;
			traveler = temp;
			m_length--;
		}
	}
	template<typename T>
	void List<T>::display() const {
		Node* traveler = m_head;
		std::cout << "HEAD <-> ";
		while (traveler != nullptr) {
			std::cout << traveler->node_data << " <-> ";
			traveler = traveler->next;
			//traveler++;
		}
		std::cout << "TAIL" << std::endl;
	}
	template <typename T>
	bool List<T>::empty()const {
		return (m_length == EMPTY);
	}
	template <typename T>
	void List<T>::erase(const T& to_remove) {
		if (!empty()) {
			size_t index_to_pop = 0;
			Node* traveler = m_head;
			while (traveler != nullptr) {
				T current = traveler->node_data;
				if (to_remove == current) {
					this->remove(index_to_pop);
					return;
				}
				traveler = traveler->next;
				index_to_pop++;
			}
		}
	}
	template <typename T>
	void List<T>::push_back(const T& _data) {
		if (empty()) {
			Node* new_node = create_node(_data);
			m_head = m_tail = new_node;
			m_length++;
		}
		else {
			Node* new_node = create_node(_data);
			m_tail->next = new_node;
			new_node->previous = m_tail;
			new_node->next = nullptr;			// This line is trivial
			m_tail = new_node;
			m_length++;
		}
	}
	template<typename T>
	void List<T>::push_front(const T& _data) {
		if (empty()) {
			Node* new_node = create_node(_data);
			m_head = m_tail = new_node;
			m_length++;
		}
		else {
			Node* new_node = create_node(_data);
			new_node->next = m_head;
			m_head->previous = new_node;
			m_head = new_node;
			m_length++;
		}
	}
	template<typename T>
	void List<T>::push(const size_t& _insert_at, const T& _data) {
		if (empty()) {
			Node* new_node = create_node(_data);
			m_head = m_tail = new_node;
			m_length++;
		}
		else if (_insert_at <= 0)
			insert_front(_data);
		else if (_insert_at >= m_length)
			insert_back(_data);
		else {
			Node* to_shift = get_node(_insert_at);
			Node* _PREV = to_shift->previous;
			Node* new_node = create_node(_data);

			_PREV->next = new_node;
			to_shift->previous = new_node;
			new_node->previous = _PREV;
			new_node->next = to_shift;
			m_length++;
		}
	}
	template<typename T>
	void List<T>::join(List<T>& other) {
		if (empty()) {
			m_head = other.m_head;
			m_tail = other.m_tail;
			m_length = other.m_length;
		}
		else {
			m_tail->next = other.m_head;
			other.m_head->previous = m_tail;
			m_tail = other.m_tail;
			m_length = m_length + other.m_length;
		}
	}
	template<typename T>
	T& List<T>::peek_back(){
		return m_tail->node_data;
	}
	template<typename T>
	T& List<T>::peek_back() const {
		return m_tail->node_data;
	}
	template<typename T>
	T& List<T>::peek_front(){
		return m_head->node_data;
	}
	template<typename T>
	T& List<T>::peek_front() const {
		return m_head->node_data;
	}
	template<typename T>
	T& List<T>::pop(const size_t& _remove_at) {
		if (!empty()) {
			if (_remove_at >= m_length)
				pop_back();
			else if (_remove_at <= 0) {
				pop_front();
			}
			else {

				Node* coffin = get_node(_remove_at);
				T& pop_val = coffin->node_data;
				Node* _PREV = coffin->previous;
				Node* _NEXT = coffin->next;

				_PREV->next = _NEXT;
				_NEXT->previous = _PREV;
				m_length--;

				delete coffin;
				return pop_val;
			}
		}
	}
	template<typename T>
	T& List<T>::pop_back() {
		if (!empty()) {
			Node* coffin = m_tail;
			T& pop_val = coffin->node_data;
			m_tail = m_tail->previous;
			m_tail->next = nullptr;
			m_length--;
			delete coffin;
			return pop_val;
		}
	}
	template<typename T>
	T& List<T>::pop_front() {
		if (!empty()) {
			Node* coffin = m_head;
			T& pop_val = coffin->node_data;
			m_head = m_head->next;
			m_head->previous = nullptr;
			m_length--;
			delete coffin;
			return pop_val;
		}
	}
	template<typename T>
	T& List<T>::pop(iterator& itr) {
		// Possible memory leak here. No deletion of that popped node has taken place.
		if (itr != nullptr) {

			T& pop_val = *itr;

			Node* pre_pop = itr.get_prev();
			Node* post_pop = itr.get_next();

			if (post_pop == nullptr) {
				pre_pop->next = post_pop;
				m_tail = pre_pop;
			}
			else {
				pre_pop->next = post_pop;
				post_pop->previous = pre_pop;
			}
			m_length--;

			return pop_val;
		}
		else
			throw std::exception("Iterator not initialized");
	}
	template<typename T>
	T& List<T>::pop(reverse_iterator& ritr) {
		if (ritr != nullptr) {
			return *ritr;
		}
		else
			throw std::exception("Iterator not initialized");
	}
	template <typename T>
	void List<T>::reverse() {

		Node* reversed_head = nullptr;
		Node* current = m_head;
		Node* unreversed_head = nullptr;
		
		bool initial_iteration = true;

		while (true) {
			if (current->next == nullptr) {
				current->next = reversed_head;
				current->previous = unreversed_head;
				reversed_head = current;
				break;
			}
			unreversed_head = current->next;
			current->next = reversed_head;
			current->previous = unreversed_head;
			reversed_head = current;
			if (initial_iteration) {
				m_tail = current;
				initial_iteration = false;
			}
			current = unreversed_head;
		}
		m_head = reversed_head;
	}
	template <typename T>
	const size_t List<T>::size() const {
		return m_length;
	}
	template <typename T>
	void List<T>::sort() {
		
	}
}

// DOCUMENTATION
// ----------------------------------------------------------------------------
/* To-Do:
*  ----------------------------------------------------------------------------
*  std::initializer_list : When a compiler sees an initializer list, it automa-
*  tically converts it into an object of type std::initializer_list. Therefore,
*  if we create a constructor that takes a std::initializer_list parameter, we
*  can create objects using the initializer list as an input.
*  std::initializer_list lives in the <initializer_list> header.
*  std::initializer_list is templated class object. We need to specify the data
*  type we'll be using whenever we make use this initializer list.
*  Second, std::initializer_list has a (misnamed) size() function which returns
*  the number of elements in the list. This is useful when we need to know the
*  length of the list passed in.
* 
*  Fix Node Operator Overloads
*  Sort
*  Improve Reverse
*  _NODISCARD
*  Throw proper exceptions
*/
