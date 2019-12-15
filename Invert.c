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

void create(int vrenodost)
{
    temp = (NODE*)malloc(sizeof(NODE));
    temp->x = vrenodost;
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

void display()
{
    temp = first;
    while(temp != NULL)
    {
        printf(" %d -> ", temp->x);
        temp = temp->next;
    }
    printf("\n");
}

void invertuj()
{
    NODE *current = first;
    NODE *next = NULL;
    NODE *prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    first = prev;
}

int main()
{
    create(3);
    create(63);
    create(43);
    create(12);
    display();
    invertuj();
    display();

    return 0;
}