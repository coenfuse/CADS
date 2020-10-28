#pragma once

class List{
    public:
        Node* begin();
        Node* end();

        T at(int index);
        void clear();
        void display();
        int find(T data);
        void insert(T data);
        void insert_beg(T data);
        void insert_at(T data, int index);
        bool isEmpty();
        int length();
        T peekFirst();
        T peekLast();
        void remove(T data);
        void remove_all(T data);
        void remove_at(int index);
        void remove_beg();
        void reverse();
        void shuffle();
        void sort(int input = 0);
        void traverse(int index);

        List();
        List(T data);
        ~List();

    private:
        unsigned int m_size = 0;
        Node *m_start, *m_end;

        class Node{
                T m_data;
                Node* m_next;
            public:
                T get_data(){ return m_data; }
                Node* get_next(){ return &m_next; }
                void set_data(T newData){ m_data = newData; }
                void set_next(Node* newNode){ m_next = newNode; }
                Node(){
                    m_data = NULL;
                    m_next = nullptr;
                }
                Node(T input, Node* newNode){
                    set_data(input);
                    set_next(newNode);
                }
        }

        Node* get_node(int index){
            if(index <= 0){
                if(m_size != 0){
                    Node *temp_node = m_start;
                    int count = 0;
                    while(count != index){
                        temp_node = temp_node -> get_next();
                    }
                    return temp_node;
                }
                else return nullptr;        // List is empty
            }
            else return nullptr;    // Invalid index
        }
}

void List::shuffle(){

}

void List::reverse(){

}