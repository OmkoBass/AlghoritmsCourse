#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int KRed[SIZE];
int f = -1;
int r = -1;

int RedFull()
{
    if((f == r+1) || (f == 0 && r == SIZE - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int RedEmpty()
{
    if(f == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Ubaci(int vrednost)
{
    if(f == -1)
    {
        f = 0;
    }
    r = (r+1) % SIZE;
    KRed[r] = vrednost;
}

void Izbaci()
{
    if(f == r)
    {
        f = -1;
        r = -1;
    }
    else
    {
        f = (f+1) % SIZE;
    }
}

void display()
{
    int i;
    for(i = f; i <= r; i++)
    {
        printf("|%d| ", KRed[i]);
    }
        printf("\n");
}

int main()
{
    Ubaci(3);
    Ubaci(25);
    Ubaci(300);
    Izbaci();
    display();

    return 0;
}