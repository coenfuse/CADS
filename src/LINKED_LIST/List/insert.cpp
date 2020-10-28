#include "../include/LINKED_LIST/list.h"

void List::insert(T data){
    Node *newNode = new Node(data, nullptr);
    if(m_length == 0){
        m_start = m_end = newNode;
        m_length++;
    }
    else{
        m_end -> set_next(newNode);
        m_end = newNode;
        m_length++;
    }
}
