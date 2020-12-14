#pragma once

namespace learn {

	template <typename T>
	class Ring {

	#define NOT_FOUND -1
	#define EMPTY 0

	private:
		struct Node {
			T node_data;
			Node* next;
			Node* previous;

			Node() :node_data(), next(nullptr), previous(nullptr) {}
			Node(T& _init_data) :node_data(_init_data), next(nullptr), previous(nullptr) {}
			Node(Node& _copy) :node_data(_copy.node_data), next(_copy.next), previous(_copy.previous) {}
			~Node() {}

			bool operator==(Node& _other) {
				return (node_data == _other.node_data && next == _other.next && previous == _other.previous);
			}
			bool operator!=(Node& _other) {
				return !(this == _other);
			}
			T& operator<<(Node& _node) {
				return _node->node_data;
			}
			void operator>>(T& _data) {
				node_data = _data;
			}
			Node& operator++() {
				return this->next;
			}
			Node& operator++(int) {
				Node* temp = this;
				this = this->next;
				return temp;
			}
			Node& operator--() {
				return this->previous;
			}
			Node& operator--(int) {
				Node* temp = this;
				this = this->next;
				return temp;
			}
		};

	private:
		Node* m_head;
		size_t m_size;

	private:
		Node& get_node(size_t& index) {
			if (index >= 0 || index < m_size) {

				Node* carrier = m_head;
				size_t travel_to = m_size - index;
				size_t counter = 0;

				if (travel_to <= index) {
					while (true) {
						if (counter == travel_to)
							return carrier;
						carrier = carrier->previous;
						counter++;
					}
				}
				else {
					while (true) {
						if (counter == travel_to)
							return carrier;
						carrier = carrier->next;
						counter++;
					}
				}
			}
			return;
		}

		Node& create_node(T& _init_data) {
			return new Node(_init_data);
		}

	public:
		using _VALUE_TYPE = T;

		template<typename T>
		class iterator {
			Node* itr_node;

			iterator() : itr_node(nullptr){}
			iterator(Node& _init_node) : itr_node(_init_node){}
			iterator(iterator& _to_copy):itr_node(_to_copy.itr_node){}

			Node& operator++(int) {		// Postfix
				Node temp = this;
				this = itr_node->next;
				return temp;
			}
			Node& operator++() {		// Prefix
				return itr_node->next;
			}
			Node& operator--(int) {		// Postfix
				Node temp = this;
				this = itr_node->previous;
				return temp;
			}
			Node& operator--() {		// Prefix
				return itr_node->previous;
			}
			bool operator==(iterator& _other) {
				return (itr_node == _other.itr_node);
			}
			bool operator!=(iterator& _other) {
				return !(this == _other);
			}
			T& operator<<(iterator& _other) {
				return _other.itr_node->node_data;
			}
		};

		//friend class const_iterator {
		//
		//};

	private:
		// Private Functions

		bool compare(Ring<T>& _other);
		void swap(size_t& A, size_t& B);
	public:

		Ring() : m_head(nullptr), m_size(0) {}
		Ring(T& _init_data);
		Ring(Ring<T>& _copy);
		~Ring() {}

		T& at(const size_t& index);
		const T& at(const size_t& index) const;
		iterator<T> begin();
		void clear();
		void display() const;
		T& erase(const T& _to_erase);
		bool empty();
		void emplace_front(const T&);
		void emplace_back(const T&);
		void emplace(const size_t _emplace_at, const T&);
		iterator<T> end();
		size_t find(const T& _to_find);
		void push_front(const T&);
		void push_back(const T&);
		void push(const size_t& _insert_at, const T& _data);
		void join(Ring<T>&);
		T& peek_head();
		const T& peek_head() const;
		T& peek_back();
		const T& peek_back() const;
		T& pop_front();
		T& pop_back();
		T& pop(const size_t& _pop_at);
		void reverse();
		const size_t size() const;
		void sort();

		T& operator[](const size_t&);
		T& operator[](const size_t&) const;
		bool operator==(Ring<T>&) const;
		bool operator!=(Ring<T>&) const;
		bool operator<(Ring<T>&) const;
		bool operator>(Ring<T>&) const;
		bool operator<=(Ring<T>&) const;
		bool operator>=(Ring<T>&) const;
		void operator+(Ring<T>&);
		void operator=(Ring<T>&);
	};

	// Constructor and Destructors
	template <typename T>
	Ring<T>::Ring(T& _init_data) {
	}

	template <typename T>
	Ring<T>::Ring(Ring<T>& _copy) {

	}

	// Operator Overloads
	template <typename T>
	T& Ring<T>::operator[](const size_t& _index) {
		return get_node(_index)->node_data;
	}

	template <typename T>
	T& Ring<T>::operator[](const size_t& _index) const {
		return get_node(_index)->node_data;
	}

	template<typename T>
	bool Ring<T>::operator==(Ring<T>& _other) const {
		if (this->m_size == _other->m_size)
			return compare(_other);
		else
			return false;
	}
	template <typename T>
	bool Ring<T>::operator!=(Ring<T>& _other) const {
		return !(this == _other);
	}
	template <typename T>
	bool Ring<T>::operator<(Ring<T>& _other) const {
		return (this->m_size < _other->m_size);
	}
	template<typename T>
	bool Ring<T>::operator>(Ring<T>& _other) const {
		return (this->m_size > _other->m_size);
	}
	template <typename T>
	bool Ring<T>::operator<=(Ring<T>& _other) const {
		return (this->m_size <= _other->m_size);
	}
	template <typename T>
	bool Ring<T>::operator>=(Ring<T>& _other) const {
		return (this->m_size >= _other->m_size);
	}
	template <typename T>
	void Ring<T>::operator+(Ring<T>& _other) {

	}
	template<typename T>
	void Ring<T>::operator=(Ring<T>& _other) {
		clear();
		join(_other);
	}

	// Private Implementations
	template<typename T>
	bool Ring<T>::compare(Ring<T>& _other) {

	}

	template<typename T>
	void Ring<T>::swap(size_t& A, size_t& B) {

	}

	// Interface Implementations
	template <typename T>
	T& Ring<T>::at(const size_t& index) {
		return noexcept(get_node(index)->node_data);
	}

	template <typename T>
	const T& Ring<T>::at(const size_t& index) const {
		return noexcept(get_node(index)->node_data);
	}

	template<typename T>
	Ring<T>::iterator<T> Ring<T>::begin() {
		return iterator(this->m_start);
	}

	template <typename T>
	void Ring<T>::clear() {

	}

	template <typename T>
	void Ring<T>::display() const {

	}

	template <typename T>
	T& Ring<T>::erase(const T& _to_erase) {

	}

	template <typename T>
	bool Ring<T>::empty() {

	}

	template <typename T>
	void Ring<T>::emplace_front(const T& _to_emplace) {
	}

	template <typename T>
	void Ring<T>::emplace_back(const T& _to_emplace) {

	}

	template <typename T>
	void Ring<T>::emplace(const size_t _emplace_at, const T& _to_emplace) {

	}

	template <typename T>
	Ring<T>::iterator<T> Ring<T>::end() {
		return iterator(nullptr);
	}

	template <typename T>
	size_t Ring<T>::find(const T& _to_find) {

	}

	template <typename T>
	void Ring<T>::push_front(const T& _to_push) {
	}

	template <typename T>
	void Ring<T>::push_back(const T& _to_push) {

	}

	template <typename T>
	void Ring<T>::push(const size_t& _insert_at, const T& _to_push) {

	}

	template <typename T>
	void Ring<T>::join(Ring<T>& _to_join) {

	}

	template <typename T>
	T& Ring<T>::peek_head() {

	}

	template <typename T>
	const T& Ring<T>::peek_head() const {
	
	}

	template <typename T>
	T& Ring<T>::peek_back() {

	}

	template <typename T>
	const T& Ring<T>::peek_back() const {
	
	}

	template <typename T>
	T& Ring<T>::pop_front() {

	}

	template <typename T>
	T& Ring<T>::pop_back() {

	}

	template <typename T>
	T& Ring<T>::pop(const size_t& _pop_at) {

	}

	template <typename T>
	void Ring<T>::reverse() {

	}

	template <typename T>
	const size_t Ring<T>::size() const {

	}

	template <typename T>
	void Ring<T>::sort() {

	}
}