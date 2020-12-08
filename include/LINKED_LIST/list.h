#pragma once
#include <iostream>
#include<list>

namespace CDS
{
	//template <typename T>
	//class NodeBase {
	//protected:
	//	T node_data;
	//	NodeBase* next;
	//	NodeBase* previous;
	//public:
	//	NodeBase() : node_data(), next(nullptr), previous(nullptr) {}
	//	~NodeBase() {}
	//};

	template <typename List>
	class ListIterator;
	template<typename List>
	class ConstListIterator;
	template<typename List>
	class ReverseListIterator;
	template<typename List>
	class ReverseConstListIterator;

	template <typename T>
	class List {
		#define NOT_FOUND -1
		#define EMPTY 0

	private:
		//template <typename T>
		//class Node : public CDS::NodeBase<T> {
		//public:
		//	T node_data;
		//	Node* next;
		//	Node* previous;
		//public:
		//	Node() :node_data(), next(nullptr), previous(nullptr) { }
		//	Node(const T& _init_data) :node_data(_init_data), previous(nullptr), next(nullptr) {}
		//	~Node() { }
		//
		//	Node& operator++() {
		//		this = this->next;
		//	}
		//	Node operator++(int) {
		//		Node* next = this->next;
		//		this->next = next->next;
		//		this->previous = this;
		//		return this;
		//	}
		//	Node& operator--() {
		//		return this->previous;
		//	}
		//	Node& operator--(int) {
		//		return this->previous;
		//	}
		//};

		struct Node {
			T node_data;
			Node* next;
			Node* previous;
		
		public:
			Node() :node_data(), next(nullptr), previous(nullptr) { }
			Node(const T& _init_data) :node_data(_init_data), previous(nullptr), next(nullptr) {}
			~Node() { }

			bool operator==(Node& other) {
				return (next == other.next && previous == other.previous && node_data == other.node_data);
			}

			bool operator!=(Node& other) {
				return !(this==other);
			}
		
			Node& operator++() {
				this = this->next;
			}
			Node operator++(int) {
				Node* next = this->next;
				this->next = next->next;
				this->previous = this;
				return this;
			}
			Node& operator--() {
				return this->previous;
			}
			Node& operator--(int) {
				return this->previous;
			}
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
	private:
		using _REFERENCE = T&;
		using _CONST_REFERENCE = const T&;
		using _POINTER = T*;

		friend ListIterator<List>;
		friend ConstListIterator<List>;
		friend ReverseListIterator<List>;
		friend ReverseConstListIterator<List>;

	public:
		using iterator = ListIterator<List>;
		using const_iterator = ConstListIterator<List>;
		using reverse_iterator = ReverseListIterator<List>;
		using const_reverse_iterator = ReverseConstListIterator<List>;

	private:
		size_t m_length;
		Node* m_head;
		Node* m_tail;

	private:
		bool compare(List<T>&);

	public:
		using _VALUE_TYPE = T;
		using _NODE_TYPE = Node;
		//using _NODE_TYPE = NodeBase<T>;

		List() :m_length(0), m_head(nullptr), m_tail(nullptr){}
		List(const T& _init_data);
		List(List<T>& _copy_this);
		~List(){}

		_REFERENCE at(const size_t& index);
		_CONST_REFERENCE at(const size_t& index) const;
		void clear();
		void display() const;
		void erase(const T& _to_erase);
		bool empty() const;
		void emplace_front();
		void emplace_back();
		void emplace(const size_t _emplace_at);
		size_t find(T& _to_find);
		void insert_front(const T&);
		void insert_back(const T&);
		void insert(const size_t& _insert_at, const T& _data);
		void join(List<T>&);
		_REFERENCE peek_front();
		_CONST_REFERENCE peek_front() const;
		_REFERENCE peek_back();
		_CONST_REFERENCE peek_back() const;
		void remove_front();
		void remove_back();
		void remove(const size_t& _remove_at);
		void reverse();
		const size_t size() const;
		void sort();

		_REFERENCE operator[](const size_t&);
		_CONST_REFERENCE operator[](const size_t&) const;
		bool operator==(List<T>&) const;
		bool operator!=(List<T>&) const;
		bool operator<(List<T>&) const;
		bool operator>(List<T>&) const;
		bool operator<=(List<T>&) const;
		bool operator>=(List<T>&) const;
		void operator+(List<T>&);
		void operator=(List<T>&);

		iterator& begin() { return iterator(m_head); }
		iterator& end() { return iterator(m_tail->next); }
		const_iterator cbegin() const;
		const_iterator cend() const;
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator rcbegin() const;
		const_reverse_iterator rcend() const;
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
	template<typename List>
	class ListIterator {
		using _VALUE = typename List::_VALUE_TYPE;
		using _VALUE_REF = _VALUE&;
		using _VALUE_PTR = _VALUE*;

		using _NODE = typename List::_NODE_TYPE;
		using _NODE_REF = _NODE&;
		using _NODE_PTR = _NODE*;

		_NODE itr_head;
		_VALUE itr_data;

	public:
		ListIterator() : itr_head(nullptr) {}
		ListIterator(ListIterator& copy) :itr_head(copy.itr_head) {}
		ListIterator(_NODE_REF _RECEIVED_HEAD) :itr_head(_RECEIVED_HEAD) {}
		~ListIterator() {}

		_NODE_REF operator++() {
			itr_data = *(this->next);
			return this->next;
		}
		_NODE_REF operator++(int) {
			_NODE_PTR temp = this->next;
			itr_data = *(this->next);
			this = this->next;
			return temp;
		}
		_NODE_REF operator--() {
			itr_data = *(this->next);
			return (this->previous);
		}
		_NODE_REF operator--(int) {
			_NODE temp = this->previous;
			itr_data = *(this->next);
			this = this->previous;
			return temp;
		}
		bool operator==(ListIterator& other) {
			return (itr_head == other.itr_head);
		}
		bool operator!=(ListIterator& other) {
			return !(itr_head == other.itr_head);
		}
		void operator=(ListIterator& other) {
			itr_data = other.itr_data;
			itr_head = other.itr_head;
		}
		_VALUE_REF operator*() {	// There is some problem here.
			return itr_data;
		}
	};

	template <typename List>
	class ConstListIterator {
		using _VALUE = typename List::_VALUE_TYPE;
		using _VALUE_REF = _VALUE&;
		using _VALUE_PTR = _VALUE*;

		using _NODE = typename List::_NODE_TYPE;
		using _NODE_REF = _NODE&;
		using _NODE_PTR = _NODE*;

		_NODE itr_head;
		_VALUE itr_data;
	public:
		ConstListIterator():itr_head(nullptr), itr_data(){}
		ConstListIterator(ConstListIterator<List>& other):
			itr_head(other.itr_head),
			itr_data(*(other.itr_head)){}
		~ConstListIterator() {}

		_NODE_REF operator++() {
			return (this->itr_data);
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
					remove(index_to_pop);
					return;
				}
				traveler = traveler->next;
				index_to_pop++;
			}
		}
	}
	template <typename T>
	void List<T>::insert_back(const T& _data) {
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
	void List<T>::insert_front(const T& _data) {
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
	void List<T>::insert(const size_t& _insert_at, const T& _data) {
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
	const T& List<T>::peek_back() const {
		return m_tail->node_data;
	}
	template<typename T>
	T& List<T>::peek_front(){
		return m_head->node_data;
	}
	template<typename T>
	const T& List<T>::peek_front() const {
		return m_head->node_data;
	}
	template<typename T>
	void List<T>::remove(const size_t& _remove_at) {
		if (!empty()) {
			if (_remove_at >= m_length)
				remove_back();
			else if (_remove_at <= 0) {
				remove_front();
			}
			else {

				Node* coffin = get_node(_remove_at);
				Node* _PREV = coffin->previous;
				Node* _NEXT = coffin->next;

				_PREV->next = _NEXT;
				_NEXT->previous = _PREV;
				m_length--;

				delete coffin;
			}
		}
	}
	template<typename T>
	void List<T>::remove_back() {
		if (!empty()) {
			Node* coffin = m_tail;
			m_tail = m_tail->previous;
			m_tail->next = nullptr;
			m_length--;
			delete coffin;
		}
	}
	template<typename T>
	void List<T>::remove_front() {
		if (!empty()) {
			Node* coffin = m_head;
			m_head = m_head->next;
			m_head->previous = nullptr;
			m_length--;
			delete coffin;
		}
	}
	template <typename T>
	void List<T>::reverse() {

		Node* reversed_head = nullptr;
		Node* unreversed_head = nullptr;
		Node* current = m_head;
		size_t counter = 0;
		while (true) {
			if (current->next == nullptr) {
				current->next = reversed_head;
				reversed_head->previous = current;
				reversed_head = current;
				break;
			}
			unreversed_head = current->next;
			current->previous = current->next;
			current->next = reversed_head;
			if (counter > 0)
				reversed_head->previous = current;
			reversed_head = current;
			if (counter == 0)
				m_tail = current;
			current = unreversed_head;
			counter++;
		}
		m_head = reversed_head;


		//Node* prev_ptr = nullptr;
		//Node* next_ptr = nullptr;
		//Node* index_ptr = m_head;
		//size_t counter = 0;
		//while (counter < m_length) {
		//	if (index_ptr->next == nullptr)
		//		break;
		//	next_ptr = index_ptr->next;
		//	index_ptr->previous = next_ptr;
		//	index_ptr->next = prev_ptr;
		//	prev_ptr = index_ptr;
		//	index_ptr = next_ptr;
		//}
		//m_head = prev_ptr;
	}
	template <typename T>
	const size_t List<T>::size() const {
		return m_length;
	}
	template <typename T>
	void List<T>::sort() {
		// Take average of the list.
		// Assume it in the middle of the list.
		// Create a new list, insert elements by comparing it with the average.
		// Works only for numerical digits.
	}
}

// DOCUMENTATION
// ----------------------------------------------------------------------------
/* To-Do:
*  ----------------------------------------------------------------------------
*  Member Initialization List
*  Fix Node Operator Overloads
*  Sort
*  Reverse
*  Rename Remove functions to Pop and return removed values instead of voids.
*  Rename Insert functions to Push.
*  Iterators
*  (We probably need to specify a pure virtual class called NodeBase and then
*  create a child class Node from it that then can be used inside the List. Why?
*  because defining a public parent Node class, our iterator class can get acc-
*  ess to the structure of Node class. Maybe I'm wrong. Like really wrong)
*/