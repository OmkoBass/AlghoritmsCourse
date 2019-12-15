#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *next;
}NODE;

NODE *top = NULL;
NODE *temp = NULL;

int isEmpty()
{
    (top == NULL) ? 1 : 0;
}

void Push(int vrednost)
{
    temp = (NODE*) malloc(sizeof(NODE));
    temp->x = vrednost;
    temp->next = top;
    top = temp;
}

void Pop()
{
    temp = top;
    top = top->next;
    free(temp);
}

void display()
{
    temp = top;
    while(temp != NULL)
    {
        printf("|%d|^\n", temp->x);
        temp = temp->next;
    }
}

int main()
{
    Push(3);
    Push(6);
    Push(9);
    Pop();
    display();

    return 0;
}