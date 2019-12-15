#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *next;
    struct node *prev;
}NODE;

NODE *first = NULL;
NODE *last = NULL;
NODE *temp = NULL;

void ubaci(int vrednost)
{
    temp = (NODE*) malloc(sizeof(NODE));
    temp->x = vrednost;
    temp->next = NULL;
    temp->prev = NULL;
    if(first == NULL)
    {
        first = temp;
        last = temp;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}

void ubaciNaPocetak(int vrednost)
{
    NODE *p;
    temp = (NODE*) malloc(sizeof(NODE));
    p = first->next;
    p->prev = temp;
    first->next = temp;
    temp->next = p;
    temp->prev = first;
    temp->x = vrednost;
}

void display()
{
    temp = first;
    while(temp != NULL)
    {
        printf(" <- %d -> ", temp->x);
        temp = temp->next;
    }
        printf(" NULL \n");
}

void displayUnazad()
{
    temp = last;
    while(temp != NULL)
    {
        printf(" <- %d -> ", temp->x);
        temp = temp->prev;
    }
        printf(" NULL \n");
}

int main()
{
    ubaci(3);
    ubaci(6);
    ubaci(12);
    ubaciNaPocetak(123);
    ubaci(69);
    display();

    return 0;
}