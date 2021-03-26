#pragma once
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
		
	};

}
