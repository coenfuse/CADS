#pragma once

namespace learn {

	template <typename T>
	class Ring {

		using NOT_FOUND = -1;
		using EMPTY = 0;

	private:
		struct Node {
			T node_data;
			Node* next;
			Node* previous;

			Node():node_data(),next(nullptr),previous(nullptr){}
			Node(T& _init_data):node_data(_init_data),next(nullptr),previous(nullptr){}
			Node(Node& _copy):node_data(_copy.node_data),next(_copy.next),previous(_copy.previous){}
			~Node(){}

			bool operator==(Node& _other) {
				return (node_data == _other.node_data && next == _other.next && previous == _other.previous);
			}
			bool operator!=(Node& _other) {
				return !(this == _other);
			}
			T& operator<<() {
				return node_data;
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
						counter++
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

	private:
		// Private Functions
		using _REFERENCE = _VALUE_TYPE&;
		using _CONST_REFERENCE = const _REFERENCE;
		using _POINTER = _VALUE_TYPE*;

		bool compare(Ring<T>& _other);
		bool swap(size& A, size& B);
	public:

		Ring() : m_head(nullptr), m_size(0) {}
		Ring(T& _init_data);
		Ring(Ring<T>& _copy);
		~Ring(){}

		_REFERENCE at(const size_t& index);
		_CONST_REFERENCE at(const size_t& index) const;
		void clear();
		void display() const;
		_REFERENCE erase(const T& _to_erase);
		bool empty() const;
		void emplace_front();
		void emplace_back();
		void emplace(const size_t _emplace_at);
		size_t find(T& _to_find);
		void push_front(const T&);
		void push_back(const T&);
		void push(const size_t& _insert_at, const T& _data);
		void join(Ring<T>&);
		_REFERENCE peek_head();
		_CONST_REFERENCE peek_head() const;
		_REFERENCE peek_back();
		_CONST_REFERENCE peek_back() const;
		_REFERENCE pop_front();
		_REFERENCE pop_back();
		_REFERENCE remove(const size_t& _remove_at);
		void reverse();
		const size_t size() const;
		void sort();

		_REFERENCE operator[](const size_t&);
		_REFERENCE operator[](const size_t&) const;
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

	// Interface Implementations
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
	void join(Ring<T>&);
	_REFERENCE peek_head();
	_CONST_REFERENCE peek_head() const;
	_REFERENCE peek_back();
	_CONST_REFERECE peek_back() const;
	void remove_front();
	void remove_back();
	void remove(const size_t& _remove_at);
	void reverse();
	const size_t size() const;
	void sort();
}