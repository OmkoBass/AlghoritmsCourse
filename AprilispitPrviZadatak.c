#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *next;
    struct node *previous;
}NODE;

NODE *first = NULL;
NODE *last = NULL;
NODE *temp = NULL;

NODE *first2 = NULL;
NODE *last2 = NULL;

void create(int vrednost)
{
    temp = (NODE*) malloc(sizeof(NODE));
    temp->x = vrednost;
    if(first == NULL)
    {
        temp->next = NULL;
        temp->previous = NULL;
        first = temp;
        last = temp;
    }
    else
    {
        temp->previous = last;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void create2(int vrednost)
{
    temp = (NODE*) malloc(sizeof(NODE));
    temp->x = vrednost;
    if(first == NULL)
    {
        temp->next = NULL;
        temp->previous = NULL;
        first = temp;
        last = temp;
    }
    else
    {
        temp->previous = last;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void ubaciPosle(NODE *pom, int vrednost)
{
    temp = (NODE*) malloc(sizeof(NODE));
    temp->x = vrednost;
    temp->next = pom->next;
    temp->previous = pom;
    pom->next = temp;
    if(pom == last)
    {
        temp = last;
    }
}

void ubaciNaPoziciji(int pozicija)
{
    int vrednost;
    printf("Unesi vrednost: ");
        scanf("%d", &vrednost);
    NODE *p;
    p = first;
    int brojac = 1;
    if(pozicija == 1)
    {
        ubaciPosle(p,vrednost);
    }
    else
    {
        while(pozicija != brojac)
        {
            p = p->next;
            brojac++;
        }
            ubaciPosle(p,vrednost);
    }
}

void brisiElement(NODE *pom)
{
    temp = pom->next;
    pom->next = temp->next;
    temp->next = temp->previous = NULL;
    free(temp);
}

void display()
{
    temp = first;
    while(temp != NULL)
    {
        printf(" <-- |%d| --> ", temp->x);
        temp = temp->next;
    }
        printf("NULL \n");
}

void spajanje(NODE *list1, NODE *list2)
{
    if(list1 == NULL)
    {
        return list2;
    }
    else
    {
        return list1;
    }
    NODE *p = first;
    while(p->next != NULL)
    {
        p = p->next;
    }
        p->next = list2;
        return list1;
}

int main()
{
    create(32);
    create(320);
    ubaciPosle(last, 32000);
    create2(69);
    spajanje(first, first2);
    display();

    return 0;
}