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
void iteration(struct Node* ptr); 
Node* reverse_Helper(struct Node** headptr, Node* cursor);
void reverse(struct Node** ptr); 
void printMenu(); 

struct Node
{
    struct Node* next; 
    int data; 
};
// Rename struct Node as Node 
 

int main()
{
    // Pointer to first node in the list
   struct Node** head = NULL; 
   int desc = 0; 
   do
   {
   printMenu(); 
   // Ask for int input
   scanf("%d",&desc); 
    switch(desc)
    {
        case(1) :   // add node
                break; 
        case(2):    // print list
                break;
        case(3):    // Reverse list
                break; 
        case(4):    // Remove node
                break;
        case(5):    // Clear list 
                break; 
        case(6):    // Exit program
                desc = 6;  
                printf("\nProgram terminated!\n"); 
                break;
        default: 
                printf("\nError wrong input!\n");  

    }
   }while(desc != 6 ); 
    return 0;
}




void printMenu()
{
    printf("\tPress a key for a selection\n");
    printf("\t1)Add node\n\t2)Print list\n\t3)Reverse list\n\t4)Remove a node\n\t5)Clear list\n\t6)Exit program"); 
}

/* Void reverse, calls recrusive helper function and reassigns headpointer after recursive call */ 
void reverse(struct Node** headptr)
{
    // Pointer pass is not null 
    if( headptr != NULL && *headptr != NULL) 
    {
        reverse_Helper(headptr,*headptr); 
        // Reassign head pointer
    }
}

/* Node pointer returning reassigns pointers with each stack frame pop */
Node* reverse_Helper(struct Node** headptr, struct Node* cursor)
{
    // Base case if next node is null return and assign head
    if(cursor->next == NULL)
    {
        // Set next pointer of head to null 
        (*headptr)->next = NULL; 
        // Set new head 
        *headptr = cursor; 
        return cursor; 
    }
    else 
    {
        Node* prev = reverse_Helper(headptr,cursor->next); 
        // have prevous node
        prev->next = cursor; 
        return cursor; 
    }
}

/*Void function adds a node in the linked list and reassigns pointers */ 
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
