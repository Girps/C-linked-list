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
void askNode(struct Node** headptr);
void remove_Node(int index,struct Node** head);
void askRemove(struct Node** head); 

struct Node
{
    struct Node* next; 
    int data; 
};
// Rename struct Node as Node 
 

int main()
{
    // Pointer to first node in the list
   Node* head;
   head = NULL;
   char desc = ' '; 
   int sentienal = 0; 

   do
   {
   printMenu(); 
   // Ask for char input
   scanf(" %c",&desc);
    // Caste to ascii code integer
    switch((int)desc)
    {
        case(49) :   // add node
                    askNode(&head); 
                break; 
        case(50):    // print list
                    if(head != NULL)
                    iteration(head);
                    else 
                    printf("\nEmpty list\n"); 
                break;
        case(51):    // Reverse list
                    reverse(&head); 
                break; 
        case(52):    // Free nodes 
                    free_Nodes(&head);
                break;
        case(53):  // remove node indicated by index 
                    if(get_Size(head) == 0)
                    {
                        printf("Can't remove node in empty list");
                    } 
                    else
                    {
                        askRemove(&head);
                    } 
                break; 
        case(54):  // Get size of the linked list 
                    printf("\nList size: %d\n",get_Size(head)); 
                break; 
        case(55):    // Exit program
                sentienal = 1;  
                printf("\nProgram terminated!\n"); 
                break;
        default:    // Repeat loop 
                printf("\nError wrong input!\n");  

    }   // If not zero loop menu 
   }while(sentienal == 0 ); 

    // If head pointer is not NULL then free all nodes in linked list
    if(head != NULL)
    {
        free_Nodes(head);
    }
    return 0;
}

/*Void function asks user for integer input and removes node in that index*/ 
void askRemove(struct Node** head)
{
    int index = 0;  
    printf("Enter index between 0 and %d", get_Size(*head));
    scanf(" %d",&index);
    remove_Node(index,head);

}

void remove_Node(int index,struct Node** head)
{
    int count = index - 1; 
     // Remove first node 
    if(index ==  0)
    {
            Node* target = (*head)->next; 
            free(*head); // free node
            (*head) = target;  // assign pointer to next node

    }   // if index is above first node
    else if(index > 0 || (index <= (get_Size(*head) - 1)))
    {
        Node* cursor = *head; 
        // Get node behind the targeted node
            while(count > 0 )
            {   
                // traverse the list 
                cursor = cursor->next; 
                count--; 
            }
        // Point to targeted node 
            struct Node* target = cursor->next; // Targeted node
            int data = target->data;            // Get remove node data
            cursor->next = target->next;         // have list point to next node on the list
            free(target);                       
            printf("Node [%d] removed from linked list",data); 
    }
    else
    {
        printf("\nindex %d is out of range did not remove node.\n",index); 
    }
}

/*Void function ask user for int data to add into linked list */ 
void askNode(struct Node** headptr)
{
    printf("\nEnter an integer to be added to linked list");
    int data = 0; 
    scanf(" %d",&data);               // takes in one character  
    add_Node(headptr,data);    // type cast data into an integer  
    printf("[ %d] added",data); // print data added into node

}

/*Void function prints output for instructions*/
void printMenu()
{
    printf("\tPress a key for a selection\n");
    printf("\t1)Add node\n\t2)Print list\n\t3)Reverse list\n\t4)Clear linked list\n\t5)Remove a node\n\t6)Linked list size\n\t7)Exit program\n"); 
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
    if(*headptr == NULL)
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
