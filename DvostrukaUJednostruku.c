#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *next;
}NODE;

typedef struct dnode
{
    int x;
    struct dnode *next;
    struct dnode *prev;
}DNODE;

NODE *temp = NULL;
NODE *first = NULL;
NODE *last = NULL;

DNODE *Dfirst = NULL;
DNODE *Dlast = NULL;

void create(int vrednost)
{
    temp = (NODE*) malloc(sizeof(NODE));
    temp->x = vrednost;
    temp->next = NULL;
    if(first == NULL)
    {
        first = temp;
        last = temp;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}

void parniToDoubly()
{
    int br = 0;
    NODE *help = first;
    while(help != NULL)
    {
        if(br % 2 == 0)
        {
            createDoubly(help->x);
        }
        help = help->next;
        br++;
    }
}

void createDoubly(int vrednost)
{
    DNODE *doubly = (DNODE*) malloc(sizeof(DNODE));
    doubly->x = vrednost;
    doubly->next = NULL;
    doubly->prev = NULL;
    if(Dfirst == NULL)
    {
        Dfirst = doubly;
        Dlast = doubly;
        Dlast->prev = Dfirst;
    }
    else
    {
        Dlast->next = doubly;
        doubly->prev = Dlast;
        Dlast = doubly;
    }
}

void printLinked()
{
    NODE *help = first;
    while(help != NULL)
    {
        printf("%d -> ", help->x);
        help = help->next;
    }
    printf("\n");
}

void printDoubly()
{
    NODE *help = Dfirst;
    while(help != NULL)
    {
        printf(" <- %d -> ", help->x);
        help = help->next;
    }
    printf("\n");
}

int main()
{
    create(3);
    create(6);
    create(12);
    create(15);
    create(20);
    create(25);
    create(30);
    parniToDoubly();
    printLinked();
    printDoubly();

    return 0;
}