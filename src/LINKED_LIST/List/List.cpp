#include "..\inc\LINKED_LIST\List.h"

List::List(){
    m_length = 0;
    m_start = m_end = nullptr;
}

List::List(T data){
    Node node = new Node(data, nullptr);
    m_start = m_end = node;
}