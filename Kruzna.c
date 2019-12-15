#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *next;
}NODE;

typedef struct Dnode
{
    int x;
    struct Dnode *next;
    struct Dnode *prev;
}DNODE;

NODE *first = NULL;
NODE *last = NULL;
NODE *temp = NULL;

DNODE *Dfirst = NULL;
DNODE *Dlast = NULL;
DNODE *Dtemp = NULL;

void ubaci(int vrednost)
{
    temp = (NODE*) malloc(sizeof(NODE));
    temp->x = vrednost;
    temp->next = NULL;
    if(first == NULL)
    {
        first = temp;
        last = temp;
        last->next = first;
    }
    else
    {
        last->next = temp;
        last = temp;
        last->next = first;
    }
}

void display()
{
    temp = first;
    while(temp != last)
    {
        printf(" -> %d -> ", temp->x);
        temp = temp->next;
    }
        printf(" %d ->", last->x);
        printf("\n");
}

void Dubaci(int vrednost)
{
    Dtemp = (DNODE*) malloc(sizeof(DNODE));
    Dtemp->x = vrednost;
    Dtemp->next = NULL;
    Dtemp->prev = NULL;
    if(Dfirst == NULL)
    {
        Dfirst = Dtemp;
        Dlast = Dtemp;
    }
    else
    {
        Dlast->next = Dtemp;
        Dtemp->prev = Dlast;
        Dtemp->next = Dfirst;
        Dfirst->prev = Dtemp;
        Dlast = Dtemp;
    }
}

void Ddisplay()
{
    Dtemp = Dfirst;
    while(Dtemp != Dlast)
    {
        printf(" <- %d -> ", Dtemp->x);
        Dtemp = Dtemp->next;
    }
        printf(" %d -> ", Dlast->x);
}

int main()
{
    ubaci(3);
    ubaci(32);
    ubaci(321);
    ubaci(123);
    display();
    
    Dubaci(1);
    Dubaci(2);
    Dubaci(5);
    Ddisplay();
    
    return 0;
}