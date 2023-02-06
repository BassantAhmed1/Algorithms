#include "Linked_List.h"


void  main ()
{
    // Node_t* head = NULL;
    Node_t* head = (Node_t*) malloc (sizeof(Node_t));
    head->data = 10;
    head ->next =NULL;
    tail_Insert (head , 5);
    tail_Insert (head , 15);
    tail_Insert (head , 20);
    Node_t* temp = head;
    if (insert_item(head, 15 ,30) == no_error)
    {
        while (temp != NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        
    }
    else 
        printf("no linked list available");

    Remove_node(head, 15);
    temp = head;
    printf("\n");
    while (temp != NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    // printf ("add=%lu \ndata=%d",temp , temp->data);
    // printf ("%lu",sizeof(Node_t));
}

void tail_Insert (Node_t* head , int item)
{
    if (head == NULL)
    {
        head = (Node_t*) malloc (sizeof(Node_t));
        head->data = item;
        head->next = NULL;
    }
    else
    {
        Node_t* temp_node = head;

        while (head->next != NULL)
            head = head->next;
        
        head->next = (Node_t*) malloc (sizeof(Node_t));
        head = head->next;
        head->data = item;
        head->next = NULL;

        head = temp_node;
    }
}
    
void head_insert (Node_t* head , int item)
{
    if (head == NULL)
    {
        head = (Node_t*) malloc (sizeof(Node_t));
        head->data = item;
        head->next = NULL;
    }
    else
    {
        Node_t* temp_node = head;
        head = (Node_t*) malloc (sizeof(Node_t));
        head->data = item;
        head->next = temp_node;
    } 
}

Node_Status NodeSearch (Node_t* head , int item , Node_t* searchedItem)
{
    if (head == NULL)
        return Null_head;
    if (head ->data == item)
    {
        searchedItem = head;
        return no_error;
    }
    
    Node_t* temp_node = head;

    while (temp_node->data != item && temp_node !=NULL)
        temp_node = temp_node->next;

    if (temp_node == NULL)
        return No_node;

    searchedItem =temp_node;
    return no_error;
}

Node_Status insert_item (Node_t * head , int after_me ,int item){
    if (head !=NULL)
    {
        Node_t *temp_node = head;
        Node_t *item_node =(Node_t*) malloc (sizeof(Node_t));
        item_node->data = item;
        while (temp_node->next != NULL && temp_node->data != after_me)
            temp_node= temp_node->next;

        if (temp_node->data == after_me)
        {
            item_node->next = temp_node->next;
            temp_node->next = item_node;
            return no_error;
        }
        return No_node;
    }
    else
        return Null_head;
}

Node_Status Remove_node (Node_t* head , int nodeData)
{
    if (head == NULL)
        return Null_head;

    Node_t* temp = head;
    if (head->data == nodeData)
    {
        head = head->next;
        free (temp);
        return no_error;
    }
    while ((temp->next)->data != nodeData && temp->next != NULL)
        temp = temp->next;
    if (temp->next == NULL)
        return No_node;
    
    else 
    {
        Node_t *prev = temp;
        temp = temp->next;
        prev->next = temp->next;
        free(temp);
        return no_error;
    }
    return No_node;
}