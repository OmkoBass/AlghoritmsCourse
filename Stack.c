#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int Stack[SIZE];
int top = -1;

int isEmpty()
{
    (top == -1) ? 1 : 0;
}

int isFull()
{
    (top == SIZE-1) ? 1 : 0;
}

void Push(int vrednost)
{
    top++;
    Stack[top] = vrednost;
}

void Pop()
{
    top--;
}

void display()
{
    int i = top;
    while(i != -1)
    {
    printf("|%d|^\n", Stack[i]);
    i--;
    }
}

void izmeniZeljeni(int vrednost, int drugaVrednost)
{
    int i = top;
    while(i != -1)
    {
        (Stack[i] == vrednost) ? Stack[i] = drugaVrednost : i--;
    }
}

int main()
{
    Push(3);
    Push(6);
    Push(9);
    display();

    return 0;
}