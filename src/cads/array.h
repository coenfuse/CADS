#pragma once

// TODO Clean all the explainatory comments from the code. And then add it into the documentation.

namespace cads {

	template <typename TYPE, size_t SIZE>
	class array {

		using REF = TYPE&;
		using CONST_REF = const TYPE&;
		using PTR = TYPE*;
		using CONST_PTR = const TYPE*;

		// Private containers are defined here below

		PTR container;

		// Private methods are defined here below

	public:

		// Publicly available ctors and dtors are defined below

		array() : container(new TYPE[SIZE]) {}

		// Define Parameterized Constructor here
		// Define Copy Constructor here

		~array(){}

		// Publicly available operator overloads are defined below

		REF operator[](size_t& _index);

		// Publicly available methods are defined below.

	};

}
