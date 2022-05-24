#include <stdio.h>
#include <stdlib.h>

/*
* Author : Jesse Jimenez 
* Date   : 5/23/2022 
* File   : Implementing a linked list data structure in C. 
*/

// Forward declaration
struct Node; 
typedef struct Node Node; 

// Function prototype declaration
void add_Node(Node** headptr,int data_Param); 
void iteration(struct Node* ptr); 
int get_Size(Node* cursor);
Node* create_Node(int data_Param);
void iteration(struct Node* ptr);
void free_Nodes(Node **cursor); 

struct Node
{
    struct Node* next; 
    int data; 
};
// Rename struct Node as Node 
 


void iteration(struct Node* ptr); 

int main()
{
    Node* head = create_Node(1); 
    printf("Size of linked-list %d\n", get_Size(head)); 
    if(get_Size(head) != 0)
    {
        free_Nodes(&head); 
    }

    printf("Size of linked-list %d\n", get_Size(head)); 
    return 0;
}

void add_Node(struct Node** headptr,int data_Param)
{
    // If list is empty first node becomes the head
    if(headptr == NULL)
    {
        // Create node assign it to head
        *headptr = create_Node(data_Param); 
    } // Otherwise reassign old head to become the next node of new node
    else 
    {
        Node* temp = create_Node(data_Param); 
        // temp-> next = headptr
        temp->next = *headptr; 
        // Now reassign head to new node
        *headptr = temp; 
    }
}



/*Int returning function iterates linked list and returns size of list */ 
int get_Size(Node* cursor)
{
    int count =0; 
    // Traverse list until null is reached
    while(cursor != NULL)
    {
        cursor = cursor->next; 
        count++;
    }
    // Return list's size 
    return count; 
}


/*Node pointer retuning function allocates node in the heap and initalizes 
    data members and returns it address in a pointer */ 
Node* create_Node(int data_Param)
{
    // Calloc allocates memory and zero initalizes our data members
    Node* temp = (Node* )calloc(sizeof(Node),1); 
    temp->data = data_Param;
    return temp;  
}


/* Void function iterate through a linked list print data until NULL is reached */
void iteration(struct Node* ptr)
{
    while(ptr != NULL)
    {
        printf("[%d]---",ptr->data); 
        ptr = ptr->next; 
    }
    printf("NULL\n"); 
}

/*Void returning functions frees all nodes in the linked-list*/ 
void free_Nodes(struct Node** headptr)
{
    Node* target = *headptr; 
    Node* cursor = target; 
    // While not null traverse 
    while(cursor != NULL)
    {
        cursor = cursor->next; 
        // Free prior node
        free(target); 
        target = cursor; 
    } 

    // Now reassign headptr to NULL
    (*headptr) = NULL;
}
