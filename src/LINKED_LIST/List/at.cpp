#include "../include/LINKED_LIST/list.h"

T List::at(int index){
    Node *temp_node = get_node(index);
    return temp_node -> get_data();
}