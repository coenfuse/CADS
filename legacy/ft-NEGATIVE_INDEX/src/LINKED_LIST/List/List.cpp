#include "..\..\..\include\LINKED_LIST\List.h"
template <typename T>

List<typename T>::List<typename T>() : m_start(nullptr), m_end(nullptr), m_size(0) {}

template <typename T>
List<typename T>::List<typename T>(T input_data) {
	Node* node = new Node(input_data);
	node.next(nullptr);
	m_start = node;
	m_size = 1;
}

template <typename T>
List<typename T>::~List<typename T>() {}