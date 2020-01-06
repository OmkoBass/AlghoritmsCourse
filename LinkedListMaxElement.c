#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}NODE;

NODE *first = NULL;
NODE *last = NULL;

void AddNode(int x)
{
    NODE *newNode = malloc(sizeof(NODE));
    newNode->value = x;
    newNode->next = NULL;

    if(first == NULL)
    {
        first = newNode;
        last = newNode;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
}

int findMax(NODE *firstOf)
{
    //Return the max value, not the entire node
    NODE *temp = firstOf;

    int max = temp->value;
    while(temp != NULL)
    {
        if(temp->value > max)
            max = temp->value;

        temp = temp->next;
    }
    
    return max;
}

void printList(NODE *firstOf)
{
    NODE *temp = firstOf;

    while(temp != NULL)
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    AddNode(50);
    AddNode(150);
    AddNode(950);
    AddNode(250);
    AddNode(350);

    printList(first);

    printf("The biggest element is: %d\n", findMax(first));

    return 0;
}