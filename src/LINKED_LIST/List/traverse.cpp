#include "../include/LINKED_LIST/list.h"
#include <iostream>

void List::traverse(int index){
    if(index != -1){
        if(index == 0){
            display();
        }
        else{
            Node *trav = get_node(index);
            while(trav != nullptr){
                std::cout<< trav->get_data() + "-> ";
                trav = trav->get_next();
            }
        }
    }
}