#include "../include/LINKED_LIST/list.h"

void List::clear(){
    Node *temp_node = m_start;
    while(temp_node != nullptr){
        Node *temp_node_2 = temp_node->get_next();
        temp_node->set_data(NULL);
        temp_node->set_next(nullptr);
        temp_node = temp_node_2;
    }
    m_length = 0;
}