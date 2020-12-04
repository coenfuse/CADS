#pragma once

// Need to specify iterator for this class
// Need to specify a variable length constructor. Maybe done by operator overloading.

namespace CDS
{
	template <typename T>
	class List {
	private:
		// Internal classes and functions
		class Node {
		private:
			T data;
			Node* next;
		public:
			T get_data() { return data };
			Node* get_next() { return next };
			void set_data(T input) : data(input) {};
			void set_next(Node* next_node) : next(next_node) {};
		};

		Node& new_node(const T& data);
		Node& get_node(const unsigned int& index);

	private:
		Node* m_start = nullptr;
		Node* m_end = nullptr;
		unsigned int m_length = 0;

	public:
		// Public Interface of List
		List();
		~List();
		T at(const unsigned int& index);
		unsigned int count(const T& to_check);
		int find(const T& to_find);
		void insert(const T& data);
		void insert_at(const unsigned int& index, const T& data);
		unsigned int& length() const;
		void remove(const T& data);
		void remove_at(const unsigned int& index);
		T& peek_head() const;
		T& peek_tail() const;
	};

	// Public definitions

	template <typename T>
	T List<T>::at(const unsigned int& index) {
		return T;
	}

	template <typename T>
	unsigned int List<T>::count(const T& to_check) {
		unsigned int count = 0;
		for (auto itr : this)
			if (itr->get_data() == to_check)
				count++;
		return count;
	}

	template <typename T>
	int List<T>::find(const T& to_find) {
		int index = 0;
		bool found = false;
		for (auto itr : this) {
			if (itr->get_data() == to_find) {
				found = true;
				break;
			}
			index++;
		}
		if (found)
			return index;
		else
			return -1;
	}

	template <typename T>
	void List<T>::insert(const T& data) {

	}

	template <typename T>
	void List<T>::insert_at(const unsigned int& index, const T& data) {

	}

	template <typename T>
	unsigned int& List<T>::length() const {
		return m_length;
	}

	template <typename T>
	T& List<T>::peek_head() const {
		return m_start->get_data();
	}

	template <typename T>
	T& List<T>::peek_tail() const {
		return m_end->get_data();
	}

	template <typename T>
	void List<T>::remove(const T& data) {
		unsigned int index_to_remove = find(data);
		Node* prev = get_node(index_to_remove - 1);
		Node* to_remove = get_node(index_to_remove);
		Node* next = to_remove->get_next();

		prev->set_next(next);
		delete to_remove;
		--m_length;
	}

	template <typename T>
	void List<T>::remove_at(const unsigned int& index) {

	}

	// Private definitions

	template<typename T>
	List<T>::Node& List<T>::new_node(const T& data) {
		Node* newNode = new Node;
		newNode->set_data(data);
		newNode->set_next(nullptr);
		return newNode;
	}

	template <typename T>
	List<T>::Node& List<T>::get_node(const unsigned int& index) {

	}
}
