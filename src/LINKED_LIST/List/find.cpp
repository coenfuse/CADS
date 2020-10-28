#include "../include/LINKED_LIST/list.h"

int List::find(T data){
    // Returns the index of the first occurence of data in the list.

    if(m_length != 0){
        Node *traveler = m_start;
        int index = 0;
        while(traveler != nullptr){
            if(traveler->get_data()==data)
                return index;
            index++;
        }
        return -1;
    }
    return -1;
}