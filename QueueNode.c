#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *next;
}NODE;

NODE *front = NULL;
NODE *back = NULL;
NODE *temp = NULL;

int isEmpty()
{
    if(front == NULL) { printf("Prazan red.\n"); return 1; }
    else { return 0; }
}

void Enque(int vrednost)
{
    if(front = NULL) { front = temp; back = temp; }
    else{ back = temp->next; back = temp; }
}

void Deque()
{
    temp = front;
    front = front->next;
    free(temp);
}

void display()
{
    temp = front;
    while(temp)
    {
        printf("|%d|-", temp->x);
        temp = temp->next;
    }
        printf("Kraj reda.\n");
}

void nadji(int vrednost)
{
    temp = front;
    int poz = 1;
    while(temp->x != vrednost)
    {
        temp = temp->next;
        poz++;
    }
    printf("Nasli smo element %d na %d poziciji.\n", temp->x, poz);
}

int main()
{
    Enque(5);
    Enque(10);
    Enque(15);
    Deque();
    display();
    nadji(10);

    return 0;
}