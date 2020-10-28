#include "../include/LINKED_LIST/list.h"

void List::remove_at(int index){
    if(index == 0){
        remove_beg();
    }
    else{
        Node *prev = get_node(--index);
        Node *toRemove = prev->get_next();
        Node *next = toRemove->get_next();
        
        toRemove->set_data(NULL);
        toRemove->set_next(nullptr);
        delete toRemove;

        //Linking the previous and next nodes
        prev->set_next(next);
        m_length--;
    }
}