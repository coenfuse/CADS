#pragma once

template <class T>
struct Pair {
	T first;
	T second;
	Pair(T first_ptr, T second_ptr) : first(first_ptr), second(second_ptr) {}
};
