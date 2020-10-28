#include "../include/LINKED_LIST/list.h"
#include <stdlib.h>
#include <ctime>

void List::shuffle(){
    
    if(m_length > 1){
        
        int index = 0;
        Node *sequential_nodes[m_length];
        Node *traverser = m_start;
        while(traverser != nullptr){
            sequential_nodes[index] = traverser;
            traverser = traverser->get_next();
            index++;
        }
        
        index = 0;

        // Shuffling the array of nodes
        srand((unsigned) time(0));
        Node *shuffled_nodes[m_length];
        int random_index;

        for(index ; index < m_length ; index++){
            random_index = rand() % sequential_nodes.size();
            for(int j ; j < shuffled_nodes.size() ; j++){       // Checks duplication
                if(shuffled_nodes[j] != sequential_nodes[random_index])
                    shuffled_nodes[index] = sequential_nodes[random_index];
            }
        }

        //Creating a new list with shuffled list which would automatically link the nodes.
        
        index = 0;
        T data;
        List newList;

        for(index = 0; index < m_length; index++){
            T data = shuffled_nodes[index]->get_data();
            newList.insert(data);
        }

        //Copying the new list onto current instanc of the list.
        
        this = newList;
    }
}