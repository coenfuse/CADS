#include "../include/LINKED_LIST/list.h"
#include <iostream>

void List::display(){
    Node *temp_node = m_start;
    while(temp_node != NULL){
        std::cout<<temp_node->get_data() + "-> ";
        temp_node = temp_node->get_next();
    }
}