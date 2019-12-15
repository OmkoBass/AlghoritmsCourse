#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *next;
}NODE;

NODE *first = NULL;
NODE *last = NULL;
NODE *temp = NULL;

void create(int brElemenata)
{
    int i = 0;
    for(i = 0; i < brElemenata; i++)
    {
        temp = (NODE*) malloc(sizeof(NODE));
        printf("Unesite %d element: ", i+1);
            scanf("%d", &temp->x);
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
}

void display()
{
    temp = first;
    printf("Prvi -> ");
    while(temp != NULL)
    {
        printf("|%d| --> ", temp->x);
        temp = temp->next;
    }
        printf("NULL \n");
}

void nadjiElement(int vrednost)
{
    NODE *p, *q;
    int br = 0;
    p = first;
    q = NULL;
    while(p != NULL)
    {
        if(p->x == vrednost)
        {
            printf("Element je %d, na poziciji %d \n", p->x, br+1);
            p = p->next;
        }
        else
        {
            q = p;
            p = p->next;
            br++;
        }
    }
}

void pojavljujuElementi(int element)
{
    NODE *p, *q;
    int brP = 0;
    p = first;
    q = NULL;
    while(p != NULL)
    {
        if(p->x == element)
        {
            brP++;
            p = p->next;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
    printf("%d se pojavljuje %d puta\n", element, brP);
}

int main()
{
    int size;
    int trazi;
    int brojPuta;
    printf("Unesite broj elemenata prve liste: ");
        scanf("%d", &size);
    create(size);
    display();
    printf("Unesite element koji zelite da trazite: ");
        scanf("%d", &trazi);
    nadjiElement(trazi);
    printf("Unesite element koji zelite da znate kol'ko puta se pojavljuje: ");
        scanf("%d", &brojPuta);
    pojavljujuElementi(brojPuta);

    return 0;
}