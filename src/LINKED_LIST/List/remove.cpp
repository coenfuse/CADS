#include "../include/LINKED_LIST/list.h"

void List::remove(T data){
    // Removes the first occurance of given data;
    int index = find(data);
    if(index == 0){
        remove_beg();
    }
    else if(index > 0){
        remove_at(index);
    }
}