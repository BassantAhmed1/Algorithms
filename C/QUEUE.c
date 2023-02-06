#include <stdio.h>
#include <stdlib.h>

#define element_type    int
#define Buffer_Length   10

typedef struct
{
    element_type *base;
    element_type *head;
    element_type *tail;
    int length;
    int count;
}QUEUE_t;

typedef enum {
    QUEUE_Error,
    QUEUE_empty,
    QUEUE_full,
    QUEUE_no_error
}QUEUE_status;

element_type Buffer [Buffer_Length] = {0};
QUEUE_t QUEUE = {NULL , NULL, NULL , 0 ,0};

QUEUE_status QUEUE_init (QUEUE_t * QUEUE, element_type * Buffer);
QUEUE_status Enqueue (QUEUE_t * QUEUE, element_type item);
QUEUE_status Dequeue (QUEUE_t * QUEUE, element_type *item);
QUEUE_status QUEUE_Is_Full (QUEUE_t * QUEUE);
QUEUE_status QUEUE_Is_Empty (QUEUE_t * QUEUE);


void main ()
{
    QUEUE_init (&QUEUE , Buffer);
    for (int i=0 ; i<12 ; i++)
        if (Enqueue (&QUEUE , i) == QUEUE_full)
            printf("QUEUE is full\n"); 

    int temp = 0;
    

    for (int i = 0; i < 15; i++)
    {
        if (Dequeue (&QUEUE , &temp) != QUEUE_empty)
            printf("%d\n",temp);
        else
            printf("QUEUE is empty\n");
    }
    
}


QUEUE_status QUEUE_init(QUEUE_t *QUEUE, element_type *Buffer)
{
    if (QUEUE == NULL && Buffer == NULL)
        return QUEUE_Error;

    QUEUE->base = QUEUE->head = QUEUE->tail = Buffer;
    QUEUE->length = Buffer_Length;
    QUEUE->count = 0;

    return QUEUE_no_error;
}

QUEUE_status Enqueue(QUEUE_t *QUEUE, element_type item)
{
    if (QUEUE == NULL && QUEUE->head && QUEUE->base && QUEUE->tail)
        return QUEUE_Error;
    
    if (QUEUE_Is_Full(QUEUE) == QUEUE_full)
        return QUEUE_full;

    *QUEUE->head = item;
    QUEUE->head++;
    QUEUE->count++;

    if (QUEUE->head >= (QUEUE->base + QUEUE->length))
        QUEUE->head =QUEUE->base;

    return QUEUE_no_error;
}

QUEUE_status Dequeue(QUEUE_t *QUEUE, element_type *item)
{
    if (QUEUE == NULL && QUEUE->head && QUEUE->base && QUEUE->tail)
        return QUEUE_Error;
    
    if (QUEUE_Is_Empty(QUEUE) == QUEUE_empty)
        return QUEUE_empty;

    *item = *QUEUE->tail;
    QUEUE->tail++;
    QUEUE->count--;

    if (QUEUE->tail >= (QUEUE->base + QUEUE->length))
        QUEUE->tail =QUEUE->base;

    return QUEUE_no_error;
}

QUEUE_status QUEUE_Is_Full(QUEUE_t *QUEUE)
{
    if (QUEUE == NULL && QUEUE->head && QUEUE->base && QUEUE->tail)
        return QUEUE_Error;
    
    if (QUEUE->length == QUEUE->count)
        return QUEUE_full;
    else 
        return QUEUE_no_error;
}

QUEUE_status QUEUE_Is_Empty(QUEUE_t *QUEUE)
{
    if (QUEUE == NULL && QUEUE->head && QUEUE->base && QUEUE->tail)
        return QUEUE_Error;
    
    if (QUEUE->count == 0)
        return QUEUE_empty;
    else 
        return QUEUE_no_error;
}
