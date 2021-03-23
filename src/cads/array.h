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

		array(){}

		// Define Parameterized Constructor here
		// Define Copy Constructor here

		~array(){}

		// Publicly available operator overloads are defined below

		REF operator[](size_t& _index) {
			if (_index >= SIZE || _index < 0)
				throw std::out_of_range("Index out of valid range");	// TODO : Remove this std exception class dependency.
			return container[_index];
		}

		CONST_REF operator[](size_t& _index) const {
			if (_index >= SIZE || _index < 0)
				throw std::out_of_range("Index out of valid range");	// TODO : Remove this std exception class dependency.
			return container[_index];
		}

		// Publicly available methods are defined below.

	};

}
