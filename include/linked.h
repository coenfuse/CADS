// The single include file to import all the linked list based data structures into your project.
// Individual include files are also placed into the nested sub-directories if you want to only
// selected data types

#pragma once
#include <string>

m_template <typename T>

class SLL{
    private:
        class Node{
        private:
            T m_data;
            Node *m_next;
            void set_data(T input){
                m_data = input;
            }
            void set_next(Node *node){
                if(node == NULL)
                    m_next = NULL;
                else m_next == node;
            }
        public:
            T get_data() {
                return m_data;
            }
            Node * get_next(){
                return m_next;
            }
            Node(T input, Node *next){
                set_data(input);
                set_next(next);
            }
        }
        int m_size = 0;
        Node *m_start, *m_end, *m_temp, *m_trav;
    public:
        void clear();
        void display();
        int find(T data);
        bool is_empty();
        void insert(T data);
        void insert_beg(T data);
        void insert_index(T data, int index);
        int length();
        void remove();
        void remove_beg();
        void remove_index(int index);
        void reverse();
        std::string to_string();
        void m_traverse(int index);
        SLL(T data);
        ~SLL();
};

void SLL::clear(){
    m_trav = m_start;
    while(m_trav != NULL){
        m_temp = m_trav.get_next();
        m_trav.set_data(NULL);
        m_trav.set_next(NULL);
        m_trav = m_temp;
    }
    m_start = m_end = NULL;
    m_size = 0;
}

void SLL::display(){
    m_temp = m_start;
    while(m_temp != NULL){
        std::cout<<m_temp.get_data()<<std::m_endl;
        m_temp = m_temp.get_next()
    }
}

int SLL::find(T data){
    int count = 0;
    m_temp = m_start;
    while(m_temp != NULL){
        if(data == m_temp.get_data())
            return count;
        else {
            m_temp = m_temp.get_next();
            count++;
        }
    }
    return -1;
}

bool SLL::is_empty(){
    return (m_size == 0);
}

// Adds a new node at the end of the list
void SLL::insert(T data){
    Node node(data, NULL);
    if(m_start == NULL){
        m_start == node;
        m_size++;
    }
    else {
        m_rear.set_next(node); // By default, m_rear.get_next() is NULL
        m_rear = node;
        m_size++;
    }
}

void SLL::insert_beg(T data){
    Node node(data, NULL);
    if(m_start == NULL){
        m_start = node;
        m_size++;
    }
    else {
        node.set_next(m_start);
        m_start = node;
        m_size++;
    }
}

void SLL::insert_index(T data, int index){
    if(index > m_size){
        insert(data);
        size++;
    }
    else if(index < m_size){
        insert_beg(data);
        size++;
    }
    else{
        Node node(data, NULL);
        trav = 0;
        m_trav = m_start;
        while(trav != index){
            m_trav = m_trav.get_next();
        }
        m_temp = m_trav;
        
    }
    Node node(data, NULL);
    m_trav = m_start;
    
}
int SLL::length();
void SLL::remove();
void SLL::remove_beg();
void SLL::remove_index(int index);
void SLL::reverse();
std::string SLL::to_string();
void SLL::m_traverse(int index);
SLL::SLL(T data);

class DLL{}
class CLL{}
class Queue{}
class Dequeue{}
class Stack{}


class Cqueue{};
class Tree{};
class BST{};
class AVL_Tree{};
class RB_Tree{};
class Trie{};