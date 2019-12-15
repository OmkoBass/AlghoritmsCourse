#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *next;
}NODE;

typedef struct doubly
{
    int x;
    struct doubly *next;
    struct doubly *prev;
}DOUBLY;

NODE *first = NULL;
NODE *last = NULL;
NODE *temp = NULL;

DOUBLY *Dfirst = NULL;
DOUBLY *Dlast = NULL;
DOUBLY *Dtemp = NULL;

void create(int vrednost)
{
    temp = (NODE*)malloc(sizeof(NODE));
    temp->x = vrednost;
    temp->next = NULL;
    if(first == NULL) { first = temp; last = temp; }
    else
    {
        last->next = temp;
        last = temp;
        last->next = first;
    }
}

void toDvostruka()
{
    temp = first;
    while(temp->next != first)
    {
        Dtemp = (DOUBLY*) malloc(sizeof(DOUBLY));
        Dtemp->x = temp->x;
        Dtemp->next = NULL;
        if(Dfirst == NULL)
        {
            Dfirst = Dtemp;
            Dlast = Dtemp;
            Dfirst->prev = NULL;
        }
        else
        {
            Dlast->next = Dtemp;
            Dtemp->prev = Dlast;
            Dlast = Dtemp;
        }
        temp = temp->next;
    }
    DOUBLY *help;
    help = (DOUBLY*) malloc(sizeof(DOUBLY));
    help->x = last->x;
    help->next = NULL;
    help->prev = Dlast;
    Dlast = help;
}

void displayDvostruka()
{
    Dtemp = Dlast;
    printf("LAST ->");
    while(Dtemp != NULL)
    {
        printf(" %d -> ", Dtemp->x);
        Dtemp = Dtemp->prev;
    }
    printf("\n");
}

void display()
{
    temp = first;
    while(temp->next != first)
    {
        printf(" %d -> ", temp->x);
        temp = temp->next;
    }
    printf(" -> %d -> FIRST", last->x);
    printf("\n");
}

int main()
{
    create(3);
    create(5);
    create(12);
    toDvostruka();
    displayDvostruka();

    return 0;
}