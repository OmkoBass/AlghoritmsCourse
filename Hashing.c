#include <stdio.h>
#include <stdlib.h>

typedef struct hash
{
    int x;
    int adress;
    unsigned short full;
}HASH;

int main()
{
    int arr[15] = {3, 1, 17, 23, 41, 6, 10, 51, 71, 101, 2, 31, 98, 71, 23};
    HASH hash[17];
    int i, temp;
    for(i = 0; i < 17; i++) 
    { 
        hash[i].full = 0; 
        hash[i].x = 0; 
        hash[i].adress = i; 
    }
    
    for(i = 0; i < 15; i++)
    {
        temp = arr[i] % 17;
        if(hash[temp].full == 0) 
        { 
            hash[temp].x = arr[i]; 
            hash[temp].full = 1; 
        }
        else
        {
            while(1)
            {
                temp = (temp + 4 + hash[i].x % 2) % 17;
                if(hash[temp].full == 0) 
                { 
                    hash[temp].x = arr[i]; 
                    hash[temp].full = 1; 
                    break; 
                }
            }
        }
    }
    printf("\n");
    for(i = 0; i < 17; i++)
    {
        printf("%d\t%d\t%d\n", hash[i].full, hash[i].adress, hash[i].x);
    }

    return 0;
}