#include "../include/LINKED_LIST/list.h"

void List::remove_all(T data){
    int index = 0;
    while(find(data)!= -1){
        index = find(data);
        remove_at(index);
    }
}