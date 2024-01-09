#ifndef LINK_LIST_H
#define LINK_LIST_H
#define list_add_at_end list_add


/* Linked list node { data and pointer to next node } */
struct  ll_node {
        int     data;
        struct  ll_node *next;
};

typedef struct ll_node    NODE;
typedef struct ll_node *  PNODE;
typedef struct ll_node ** PPNODE;

/* Function to create link list node
 * return pointer to node created
 */
PNODE   create_node (int data){

        PNODE temp = (PNODE)malloc(sizeof(NODE));
        if (temp){
                temp->data = data;
                temp->next = NULL;
                return temp;
        }
        exit(EXIT_FAILURE);
}

/* Function to add node to the list (end of list)
 * return pointer to newly added node
 */
PNODE   list_add(PPNODE HEAD, int data){

        PNODE current = *HEAD;

        // If it is the first node
        if ( *HEAD == NULL ){
                *HEAD = create_node(data);
                return *HEAD;
        }

        // Goto end of list and add node
        for(;current->next != NULL; current = current->next);
        current->next = create_node(data);
        return current->next;
}

/* Function to add node to the beginning of list
 * return pointer to newly added node
 */
PNODE   list_add_at_beg(PPNODE HEAD, int data){
        PNODE new_node = create_node(data);
        new_node->next = *HEAD;
        *HEAD = new_node;
        return *HEAD;
}

/* Function to delete node from beginning */
void    list_delete_at_beg(PPNODE HEAD){
        if (*HEAD){
                PNODE current = *HEAD;
                *HEAD = current->next;
                free(current);
        }
}

void    list_delete_at_end(PPNODE HEAD){
        if(*HEAD){

                if ( (*HEAD)->next == NULL ){
                        free(*HEAD);
                        *HEAD = NULL;
                        return;
                }

                PNODE curr = *HEAD;
                PNODE prev = *HEAD;
                while( curr->next != NULL ){
                        prev = curr;
                        curr = curr->next;
                }

                prev->next = NULL;
                free(curr);
        }
}

void    list_delete_by_key(PPNODE HEAD, int data){
        if(*HEAD){

                PNODE curr = *HEAD;
                PNODE prev = *HEAD;

                if (curr->data == data){
                        list_delete_at_beg(HEAD);
                        return;
                }

                while(curr->next != NULL){
                        if (curr->data == data){
                                prev->next = curr->next;
                                free(curr);
                                return;
                        }
                        prev = curr;
                        curr = curr->next;
                }

                if (curr->data == data)
                        list_delete_at_end(HEAD);
        }
        return;
}

/* Function to define all entries from the list */
void    list_delete(PPNODE HEAD){
        if(*HEAD){
                PNODE curr = *HEAD;
                PNODE prev = *HEAD;
                while( curr->next != NULL ){
                        prev = curr;
                        curr = curr->next;
                        free(prev);
                }
                free(curr);
                *HEAD = NULL;
        }
        return;
}

/* Function to print list */
void    print_list(PPNODE HEAD){
        if (*HEAD){
                PNODE current = *HEAD;
                for(;current != NULL; current = current->next){
                        printf("[%5d] - ", current->data);
                }
        }
        printf("\n");
        return;
}
#endif