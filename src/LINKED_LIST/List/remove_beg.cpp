#include "..inc/LINKED_LIST/list.cpp"

void List::remove_beg(){
    if(m_length != 0){
        Node *temp = m_start;
        m_start = m_start->get_next();
        delete temp;
        m_length--;
    }
    else throw RuntimeException "Underflow";   
}