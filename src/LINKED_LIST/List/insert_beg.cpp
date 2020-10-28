#include "../include/LINKED_LIST/list.h"

void List::insert_beg(T data){
    Node *newNode = new Node(data, nullptr);
    if(m_length == 0){
        m_start = m_end = newNode;
        m_length++;
    }
    else{
        newNode -> set_next(m_start);
        m_start = newNode;
        m_length++;
    }
}