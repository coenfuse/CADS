#include "../inc/LINKED_LIST/list.cpp"

T List::peekFirst(){
    return m_start->get_data();
}