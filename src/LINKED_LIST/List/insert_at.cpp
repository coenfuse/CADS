#include "../include/LINKED_LIST/list.h"

void List::insert_at(T data, int index){
    if(index < 0){
        insert_beg(data);
    }
    else if(index > m_length){
        insert(data);
    }
    else{
        Node *newNode = new Node(data, nullptr);
        Node *prev = get_node(--index);
        Node *next = prev->get_next();
        
        // Restructuring the list by adding the node between prev and next
        newNode->set_next(next);
        prev->set_next(newNode);
        m_length++;

    }
}