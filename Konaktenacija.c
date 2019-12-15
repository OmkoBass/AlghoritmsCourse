#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *next;
}NODE;

NODE *first1 = NULL;
NODE *last1 = NULL;
NODE *first2 = NULL;
NODE *last2 = NULL;
NODE *temp = NULL;

void create(int vrednost, int brListe)
{
    temp = (NODE*) malloc(sizeof(NODE));
    temp->x = vrednost;
    temp->next = NULL;
    if(brListe == 1)
    {
        if(first1 == NULL) { first1 = temp; last1 = temp;}
        else{ last1->next = temp; last1 = temp;}
    }
    else if(brListe == 2)
    {
        if(first2 == NULL) { first2 = temp; last2 = temp;}
        else{ last2->next = temp; last2 = temp;}
    }
    else
    {
        printf("Ne postoji ta lista.\n");
    }
}

void ubaciPosle(NODE *pom, int vrednost)
{
    temp = (NODE*) malloc(sizeof(NODE));
    temp->x = vrednost;
    temp->next = pom->next;
    pom->next = temp;
    if(pom == last1) { last1 = temp; }
    if(pom == last2) { last2 = temp; }
}

void brisiPosle(NODE *pom)
{
    temp = pom->next;
    pom->next = temp->next;
    free(temp);
}

void ubaciNaPoziciji(int pozicija, int brListe)
{
    int brojac = 1;
    if(brListe == 1)
    {
        temp = first1;
        if(pozicija == 1)
        {
            ubaciPosle(temp, 30);
        }
        else
        {
            while(brojac != pozicija)
            {
                temp = temp->next;
                brojac++;
            }
            ubaciPosle(temp, 2);
        }
    }
    else if(brListe == 2)
    {
        temp = first2;
        if(pozicija == 1)
        {
            ubaciPosle(temp, 30);
        }
        else
        {
            while(brojac != pozicija)
            {
                temp = temp->next;
                brojac++;
            }
            ubaciPosle(temp, 2);
        }
    }
    else
    {
        printf("Ne postoji ta lista.\n");
    }
}

void konkatenacija(NODE *lista1, NODE *lista2)
{
    
    if(first2 == NULL) { printf("Druga lista je prazna.\n"); }
    else if(first1 == NULL) { printf("Prva lista je prazna.\n"); }
    else
    {
        temp = first1;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = first2;
    }
}

void display(int brListe)
{
    if(brListe == 1)
    {
        printf("Prva lista\n");
        temp = first1;
        while(temp != NULL)
        {
            printf(" %d -> ", temp->x);
            temp = temp->next;
        }
        printf("\n");
    }
    else if(brListe == 2)
    {
        printf("Druga lista\n");
        temp = first2;
        while(temp != NULL)
        {
            printf(" %d -> ", temp->x);
            temp = temp->next;
        }
        printf("\n");
    }
    else
    {
        printf("Ne postoji ta lista.\n");
    }
}

int main()
{
    create(3,1);
    create(9,1);
    create(5,1);
    create(12,1);
    create(69,2);
    create(31,2);
    create(91,2);
    konkatenacija(first1,first2);
    display(1);

    return 0;
}