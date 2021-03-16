#include <iostream>
#include <process>

struct Node{
    int info;
    Node *next;
} *start, *newptr, *save, *ptr, *rear;

Node * create_new_node(int);
void insert_beg(Node *);
void display (Node *);
void insert_end(Node *);
void remove();
void traverse();
Node * get_node(index);

int main(){
    start = NULL;
    int information;
    char choice = 'y';
    while(choice == 'Y' || choice == 'y'){
        system("cls");
        std::cout<<"Enter information for new node"<<std::endl;
        std::cin>>information;  // Data inside information
        std::cout<<"Creating a new node. Wait bitch"<<std::endl;
        system("pause");
        newptr = create_new_node(information);
        if(newptr != NULL){
            std::cout<<"Node created successfully"<<std::endl;
            system("pause");
        }
        else{
            std::cout<<"Can't create new node. Aborting"<<std::endl;
            system("pause");
            exit(1);
        }
        std::cout<<"Inserting this node into a list"<<std::endl;
        std::cout<<"Press enter to continue"<<std::endl;
        system("pause");
        insert_beg(newptr);
        std::cout<<"Now the list is"<<std::endl;
        display(start);
        std::cout<<"Press Y to enter more nodes N to exist"std::endl;
        std::cin>>choice;
    }
    return 0;
}

Node * create_new_node (int data){
    ptr->information = data;
    ptr->next = NULL;
    return ptr;
}

void insert_beg(Node *ptr){
    if(start == NULL){
        start = ptr;
    }
    else {
        save = start;
        start = ptr;
        ptr->next = save;
    }
}

void display(Node *np){
    while(np != NULL){
        std::cout<<np->information<<"->";
        np = np->next;
    }
}

void insert_end(Node *np){
    if(start == NULL){
        start = end = np;
    }
    else {
        rear->next = np;
        rear = np;
    }
}

void remove(){
    // Removes a node from the beginning of the list
    if(start == NULL){
        throw new OutOfBoundsException "List is empty!";
    }
    else{
        ptr = start;
        start = start->next;
        delete ptr;
    }
}

void traverse(){
    ptr = start;
    while(ptr == NULL){
        std::cout<<ptr->information<<std::endl;
        ptr = ptr->next;
    }
}