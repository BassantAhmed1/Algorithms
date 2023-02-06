#include <stdio.h>
#include <string.h>

#define elem_type   char
#define Buff_length 5

typedef struct {
    unsigned elem_type * head;
    unsigned elem_type * base;
    unsigned int lenght;
    unsigned int count;
}LIFO_Buf_t;

typedef enum 
{
    LIFO_no_error,
    LIFO_full,
    LIFO_empty,
    LIFO_NULL
}Buffer_status;

elem_type LIFO_Buf [Buff_length] = {0};
LIFO_Buf_t Lifo ;

Buffer_status LIFO_Add_item (LIFO_Buf_t * LIFO, elem_type item);
Buffer_status LIFO_Pop_item (LIFO_Buf_t * LIFO, elem_type * item);
Buffer_status LIFO_Is_Full (LIFO_Buf_t * LIFO);
Buffer_status LIFO_init (LIFO_Buf_t * LIFO , elem_type * lifo_buf);


void main (){
    
    char str [400];
    char *sptr = str;
    char temp;

    

    if (LIFO_init (&Lifo , LIFO_Buf) == LIFO_no_error)
    {

        gets(str);

        printf("%d\n", check_Parenthises(sptr));


        
        
        // int i=0, temp;
        // while (1)
        // {
        //     if (LIFO_Add_item(&Lifo,i) == LIFO_full)
        //         break;
        //     i++;
        // }    
        // printf("i=%d\n count=%d \nlength=%d",i,Lifo.count,Lifo.lenght);
        // i = 0;
        // while(1)
        // {
        //     if (LIFO_Pop_item(&Lifo , &temp) == LIFO_empty)
        //         break;
        //     printf ("item no %d: %d\n",i,temp);
        //     i++;
        // }
    }
    
}

Buffer_status LIFO_Is_Full (LIFO_Buf_t * LIFO)
{
    if (LIFO->count == LIFO->lenght)
        return LIFO_full;
    if (LIFO->count==0)
        return LIFO_empty;

    return LIFO_no_error;
}

Buffer_status LIFO_init (LIFO_Buf_t * LIFO , elem_type * lifo_buf)
{
    LIFO->base = lifo_buf;
    LIFO->head = lifo_buf;

    LIFO->count =  0;
    LIFO->lenght = Buff_length;

    if (!LIFO || !LIFO->base || !LIFO->head)
        return LIFO_NULL;
    return LIFO_no_error;
}

Buffer_status LIFO_Add_item (LIFO_Buf_t * LIFO, elem_type item)
{
    if (!LIFO || !LIFO->base || !LIFO->head)
        return LIFO_NULL;
    if (LIFO_Is_Full(LIFO) == LIFO_full)
        return LIFO_full;
    
    *LIFO->head = item;
    LIFO->head++;
    LIFO->count++;

    return LIFO_no_error;
    
}
Buffer_status LIFO_Pop_item (LIFO_Buf_t * LIFO, elem_type * item)
{
    if (!LIFO || !LIFO->base || !LIFO->head)
        return LIFO_NULL;
    if (LIFO_Is_Full(LIFO) == LIFO_empty)
        return LIFO_empty;
    
    LIFO->head --;
    *item = *LIFO->head;
    LIFO->count--;

    return LIFO_no_error;


}
