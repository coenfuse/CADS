#include "../include/LINKED_LIST/list.h"

T List::peekLast(){
    return m_end->get_data();
}