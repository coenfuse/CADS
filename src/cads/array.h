#pragma once
#include <array>

#include <stdexcept>

namespace cads {

	template <typename TYPE, size_t SIZE>
	class array {

		using REF = TYPE&;
		using CONST_REF = const TYPE&;
		using PTR = TYPE*;
		using CONST_PTR = const TYPE*;

		// Private containers are defined here below

		TYPE container[SIZE];

		// Private methods are defined here below

	public:

		// Publicly available ctors and dtors are defined below

		array(){
			for (size_t index = 0; index < SIZE; index++)
				container[index] = static_cast<TYPE>(0);
		}

		array(const array<TYPE, SIZE>& _second_array) {
			for (size_t index = 0; index < SIZE; index++)
				container[index] = _second_array[index];
		}

		// Define Initializer List Constructor here

		~array(){}

		// Publicly available members defined here
		
		static constexpr auto NPOS{
			static_cast<TYPE>(-1)
		};

		// Publicly available operator overloads are defined below

		REF operator[](const size_t& _index) {
			if (_index >= 0 && _index < SIZE)
				return container[_index];
			throw std::out_of_range("Invalid index value");
		}

		CONST_REF operator[](const size_t& _index) const {
			if (_index >= 0 && _index < SIZE)
				return container[_index];
			throw std::out_of_range("Invalid index value");
		}

		// Publicly available methods are defined below.

		// Returns const reference to element at last index of the container.
		CONST_REF back() {
			return container[SIZE - 1];
		}

		// Clears the container by filling it with 0.
		void clear() {
			for (size_t index = 0; index < SIZE; index++)
				container[index] = static_cast<TYPE>(0);
			// begin = end = 0;
		}

		// Returns pointer to the interal container.
		PTR data() {
			return container;
		}

		// Fills the array with specified value
		void fill(CONST_REF _to_fill) {
			for (size_t index = 0; index < SIZE; index++)
				container[index] = _to_fill;
		}

		// Returns const reference to element at starting index of the container.
		CONST_REF front() {
			return container[0];
			// return begin;
		}

		// Checks whether container is empty or not (Experimental)
		bool is_empty() {
			for (size_t index = 0; index < SIZE; index++)
				if (container[index] != static_cast<TYPE>(0))
					return false;
			return true;
			//return start == end;
		}

		// Returns the number of elements container can store
		size_t length() {
			return SIZE;
		}

		// Returns the total size of the container in bytes
		size_t size() {
			return SIZE * sizeof(TYPE);
		}

		// Swaps the elements stored at specified indexes inside the container
		void swap(const size_t _index_A, const size_t _index_B) {
			if (_index_A < SIZE && _index_B < SIZE) {
				TYPE temp = container[_index_A];
				container[_index_A] = container[_index_B];
				container[_index_B] = temp;
			}
		}
		
	};

}

// TODO : Make use of const, NODISCARD and noexcept wherever necessary
// TODO : Make a dependency section in each method's documentation illustrating how the container is build upon itself.
// TODO : Make a modification section that tells how to remove a method (in its own documentation) and add a modification section in parent array documentation defining how to add your own new function.
// TODO : Consult EASTL and learn few design practises, keywords and required expressions.
// TODO : Abnormal behavior with strings and other custom data-types.
// TODO : Not a generic container right now, constructor casting is the bottleneck.