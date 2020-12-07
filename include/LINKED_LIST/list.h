#pragma once
#include <iostream>

namespace CDS
{
	template <typename T>

	class List {
		#define NOT_FOUND -1
		#define EMPTY 0
	public:
		using _VALUE_TYPE = T;
	private:
		using _REFERENCE = _VALUE_TYPE&;
		using _CONST_REFERENCE = const _VALUE_TYPE&;
		using _POINTER = _VALUE_TYPE*;
	private:
		struct Node {
			T node_data;
			Node* next;
			Node* previous;

		public:
			Node() :node_data(), next(nullptr), previous(nullptr) { }
			Node(const T& _init_data) :node_data(_init_data), previous(nullptr), next(nullptr) {}
			~Node() { }

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
		size_t m_length;
		Node* m_head;
		Node* m_tail;

	public:
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
		void insert_front(const T&);
		void insert_back(const T&);
		void insert(const size_t& _insert_at, const T& _data);
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
	};

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

	// Private Method definitions

	// Interface definitions
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
		Node* prev_ptr = nullptr;
		Node* next_ptr = nullptr;
		Node* index_ptr = m_head;
		size_t counter = 0;
		while (counter < m_length) {
			if (index_ptr->next == nullptr)
				break;
			next_ptr = index_ptr->next;
			index_ptr->previous = next_ptr;
			index_ptr->next = prev_ptr;
			prev_ptr = index_ptr;
			index_ptr = next_ptr;
		}
		m_head = prev_ptr;
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
*  Copy Constructor
*  Member Initialization List
*  Fix Node Operator Overloads
*  List Operator Overloads
*  Sort
*  Reverse
*  Iterators
* 
*/