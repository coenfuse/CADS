#pragma once

namespace cads {

	template <typename T, size_t SIZE>
	class array {

		// Private containers are defined here below

		T* container;

		// Private methods are defined here below

	public:

		// Publicly available ctors and dtors are defined below

		array() {
			container = new T[SIZE];
			fill_level = 0;
		}

		~array(){}

	public:

		// Publicly available operator overloads are declared below

		T& operator[](size_t&);

		// Publicly available methods are declared below.

		const T& at(size_t);		// Here const prevents indirect assignment. i.e; Using at() to assign value.
		T& back();
		void clear();
		T* data();
		bool empty();
		void fill(const T);
		T& front();
		size_t size();
		void swap(size_t&, size_t&);

	};

	// Publicly availabe operator overloads are defined below.

	template <typename T, size_t SIZE>
	T& array<T, SIZE>::operator[](size_t& _index) {
		// ++fill_level;							<-- Look into this.
		return container[_index];
	}

	// Publicly available methods are defined below.

	template <typename T, size_t SIZE>
	const T& array<T, SIZE>::at(size_t _index) {
		return container[_index];
	}

	template <typename T, size_t SIZE>
	T& array<T, SIZE>::back() {
		return *container[SIZE - 1];
	}

	template <typename T, size_t SIZE>
	void array<T, SIZE>::clear() {
		while (fill_level != 0) {
			delete* container[fill_level];	// Should use typecast here
			fill_level--;
		}
	}

	template <typename T, size_t SIZE>
	T* array<T, SIZE>::data() {
		return container;
	}

	template <typename T, size_t SIZE>
	bool array<T, SIZE>::empty() {
		return fill_level == 0;
	}

	template <typename T, size_t SIZE>
	void array<T, SIZE>::fill(const T _val) {
		for (size_t index = 0; index < SIZE; index++)
			container[index] = _val;
		fill_level = SIZE;
	}

	template <typename T, size_t SIZE>
	T& array<T, SIZE>::front() {
		return *container;
	}

	template <typename T, size_t SIZE>
	size_t array<T, SIZE>::size() {
		return SIZE;
	}

	template <typename T, size_t SIZE>
	void array<T, SIZE>::swap(size_t& _index_A, size_t& _index_B) {
		
		if (_index_A < SIZE && _index_B < SIZE) {
			const T temp = container[_index_A];
			container[_index_A] = container[_index_B];
			container[_index_B] = temp;
		}

	}

}
