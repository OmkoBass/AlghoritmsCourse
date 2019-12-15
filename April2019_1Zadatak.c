#include <stdio.h>
#include <stdlib.h>

typedef struct nodek
{
    int x;
    struct node *next;
}NODEK;

typedef struct node
{
    int x;
    struct node *next;
    struct node *prev;
}NODE;

NODEK *firstk = NULL;
NODEK *lastk = NULL;

NODE *first = NULL;
NODE *last = NULL;

void create(int vrednost)
{
    NODEK *temp;
    temp = (NODEK*) malloc(sizeof(NODEK));
    temp->x = vrednost;
    temp->next = NULL;
    if(firstk == NULL)
    {
        firstk = temp;
        lastk = temp;
    }
    else
    {
        lastk->next = temp;
        lastk = temp;
        lastk->next = firstk;
    }
}

void toDvostruka(NODEK *prvi)
{
    NODEK *temp;
    NODE *pom;
    NODE *p;
    temp = prvi;
    while(temp != lastk)
    {
        pom = (NODE*) malloc(sizeof(NODE));
        pom->x = temp->x;
        temp = temp->next;
        if(first == NULL)
        {
            first = pom;
            last = pom;
        }
        else
        {
            last->next = pom;
            last = pom;
        }
    }
    pom = (NODE*) malloc(sizeof(NODE));
    pom->x = lastk->x;
    last->next = pom;
    last = pom;
    last->next = first;
    NODE *q, *r;
    q = first;
    r = first->next;
    while(r != last)
    {
        r->prev = q;
        r = r->next;
        q = q->next;
    }
    r->prev = q;
    first->prev = last;
    last->next = first;
}

void display()
{
    NODEK *temp;
    temp = firstk;
    while(temp != lastk)
    {
        printf(" |%d| -> ", temp->x);
        temp = temp->next;
    }
        printf(" |%d| -> prvi\n", lastk->x);
}

void displayDvostruku()
{
    NODE *temp;
    temp = last;
    printf(" -> ");
    while(temp != first)
    {
        printf(" |%d| -> ", temp->x);
        temp = temp->prev;
    }
    printf(" <- |%d| -> \n", first->x);
}

int main()
{
    create(3);
    create(6);
    create(9);
    toDvostruka(firstk);
    displayDvostruku();
    
    return 0;
}