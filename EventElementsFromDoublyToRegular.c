#include <stdio.h>
#include <stdlib.h>

//Better to implement a struct list
//In the list enter struct nodes
//But DUNP teaches us the wrong way

typedef struct node
{
    int value;
    struct node *next;
}NODE;

typedef struct doublyNode
{
    int value;
    struct doublyNode *next;
    struct doublyNode *prev;
}doublyNODE;

NODE *first = NULL;
NODE *last = NULL;

doublyNODE *doublyFirst = NULL;
doublyNODE *doublyLast = NULL;

void AddNode(int x, char which)
{
    if(which == 'l')
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
    else if(which == 'd')
    {
        doublyNODE *newNode = malloc(sizeof(doublyNODE));
        newNode->value = x;
        newNode->next = NULL;
        newNode->prev = NULL;

        if(doublyFirst == NULL)
        {
            doublyFirst = newNode;
            doublyLast = newNode;
        }
        else
        {
            doublyLast->next = newNode;
            newNode->prev = doublyLast;
            doublyLast = newNode;
            printf("%d %d %d \n", doublyFirst->value, doublyLast->value, newNode->value);
        }
    }
    else
        return;
}

void evenToLinked(doublyNODE *firstOf)
{
    doublyNODE *temp = firstOf;

    while(temp != NULL)
    {
        if(temp->value % 2 == 0)
        {
            AddNode(temp->value, 'l');

            //To remove the current node
            //This could be placed inside a new function, but i'm lazy and this is faster
            doublyNODE *tempsprev = temp->prev;

            if(temp->next != NULL)
            {
                doublyNODE *tempsnext = temp->next;
                tempsprev->next = temp->next;
                tempsnext->prev = temp->prev;
            }
            else
            {
                tempsprev->next = NULL;
                doublyLast = tempsprev;
            }
        }
        
        temp = temp->next;
    }
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

void printDoubly(doublyNODE *firstOf)
{
    doublyNODE *temp = firstOf;

    printf("NULL");
    while(temp != NULL)
    {
        printf(" <- %d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    AddNode(50, 'l');
    AddNode(150, 'l');
    AddNode(250, 'l');
    AddNode(350, 'l');
    AddNode(1, 'd');
    AddNode(2, 'd');
    AddNode(3, 'd');
    AddNode(4, 'd');
    AddNode(5, 'd');

    printList(first);
    printDoubly(doublyFirst);

    evenToLinked(doublyFirst);

    printf("The lists look like this now\n");
    printList(first);
    printDoubly(doublyFirst);

    return 0;
}