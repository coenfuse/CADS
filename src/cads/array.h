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

		TYPE m_container[SIZE];

		// Private methods are defined here below

	public:

		// Publicly available ctors and dtors are defined below

		array(){}

		array(const array<TYPE, SIZE>& p_second_array) {
			for (size_t l_index = 0; l_index < SIZE; l_index++)
				m_container[l_index] = p_second_array[l_index];
		}

		// Define Initializer List Constructor here

		~array(){}

		// Publicly available members defined here
		
		// Publicly available operator overloads are defined below

		REF operator[](const size_t& p_index) {
			if (p_index >= 0 && p_index < SIZE)
				return m_container[p_index];
			throw std::out_of_range("Invalid index value");
		}

		CONST_REF operator[](const size_t& p_index) const {
			if (p_index >= 0 && p_index < SIZE)
				return m_container[p_index];
			throw std::out_of_range("Invalid index value");
		}

		// Publicly available methods are defined below.

		// Returns const reference to element at last index of the container.
		CONST_REF back() {
			return m_container[SIZE - 1];
		}

		// Returns pointer to the interal container.
		PTR data() {
			return m_container;
		}

		// Fills the array with specified value
		void fill(CONST_REF m_fill_with) {
			for (size_t l_index = 0; l_index < SIZE; l_index++)
				m_container[l_index] = m_fill_with;
		}

		// Returns const reference to element at starting index of the container.
		CONST_REF front() {
			return m_container[0];
			// return begin;
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
		void swap(const size_t p_A, const size_t p_B) {
			if (p_A < SIZE && p_B < SIZE) {
				TYPE l_temp = m_container[p_A];
				m_container[p_A] = m_container[p_B];
				m_container[p_B] = l_temp;
			}
		}
		
	};

}

// TODO : Make use of const, NODISCARD and noexcept wherever necessary
// TODO : Make a dependency section in each method's documentation illustrating how the container is build upon itself.
// TODO : Make a modification section that tells how to remove a method (in its own documentation) and add a modification section in parent array documentation defining how to add your own new function.
// TODO : Consult EASTL and learn few design practises, keywords and required expressions.
// TODO : Fix all the warnings, messages and errors if any.