#pragma once

template <typename T>

class SLL{
private:
    class Node{
        private:
            T m_data;
            Node *m_next;

        public:
            set_data(T data){
                m_data = data;
            }
            set_next(Node *node){
                m_next = node;
            }
            T get_data {
                return m_data;
            }
            Node * get_next(){
                return m_next;
            }
            Node(T data, Node next){
                set_data(data);
                set_next(next);
            }
    }

private:
    int m_size = 0;
    Node *m_start, *m_end, *m_trav, *m_temp, *m_node;
    Node * get_node(int index){
        if(index >= 0 && index <= m_size){
            m_trav = m_start;
            unsigned int count = 0;
            while(count != index){
                m_trav = m_trav.get_next();
            }
            return m_trav;
        }
        else return NULL;
    }

public:
    Node * begin();
    Node * end();

    T at(int index);
    void clear();
    void display();
    int find(T data);
    void insert(T data);
    void insert_beg(T data);
    void insert_at(T data, int index);
    bool isEmpty();
    int length();
    void shuffle();
    void remove(T data);
    void remove_beg();
    void remove_at(int index);
    void reverse();
    void sort(int input = 0);
    void traverse(int index);

    SLL(T data);
    ~SLL();
}