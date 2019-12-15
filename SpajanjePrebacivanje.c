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

void create1(int vrednost)
{
    temp = (NODE*) malloc(sizeof(NODE));
    temp->x = vrednost;
    temp->next = NULL;
    if(first1 == NULL)
    {
        first1 = temp;
        last1 = temp;
    }
    else
    {
        last1->next = temp;
        last1 = temp;
    }
}

void create2(int vrednost)
{
    temp = (NODE*) malloc(sizeof(NODE));
    temp->x = vrednost;
    temp->next = NULL;
    if(first2 == NULL)
    {
        first2 = temp;
        last2 = temp;
    }
    else
    {
        last2->next = temp;
        last2 = temp;
    }
}

void deletePosle1(NODE *pom)
{
    temp = pom->next;
    pom->next = temp->next;
    temp->next = NULL;
    free(temp);
}

void deletePosle2(NODE *pom)
{
    temp = pom->next;
    pom->next = temp->next;
    temp->next = NULL;
    free(temp);
}

void brisiPoslePozicije1(int pozicija)
{
    int brojac = 1;
    NODE *p;
    p = first1;
    if(pozicija == 1)
    {
        deletePosle1(p);
    }
    else
    {
        while(pozicija != brojac)
        {
            p = p->next;
            brojac++;
        }
        deletePosle1(p);
    }
}

void brisiPoslePozicije2(int pozicija)
{
    int brojac = 1;
    NODE *p;
    p = first2;
    if(pozicija == 1)
    {
        deletePosle2(p);
    }
    else
    {
        while(pozicija != brojac)
        {
            p = p->next;
            brojac++;
        }
        deletePosle2(p);
    }
}

void display1()
{
    printf("Prva lista.\n");
    temp = first1;
    printf("Prvi -> ");
    while(temp != NULL)
    {
        printf("|%d| --> ", temp->x);
        temp = temp->next;
    }
        printf("NULL \n");
}

void display2()
{
    printf("Druga lista.\n");
    temp = first2;
    printf("Prvi -> ");
    while(temp != NULL)
    {
        printf("|%d| --> ", temp->x);
        temp = temp->next;
    }
        printf("NULL \n");
}

NODE *spoji(NODE *list1, NODE *list2)
{
    NODE *p;
	if (list1 == NULL)
	{
        return list2;
    }
	else if (list2 == NULL)
    {
        return list1;
    }
	p=list1;
	while(p->next != NULL)
    {
		p = p->next;
	}
	p->next=list2;
	return list1;
}

void prebacuj(NODE *first1, NODE *first2)
{
    NODE *prvi;
    NODE *drugi;
    prvi = first1;
    drugi = first2;
    NODE *pom;
    while(prvi != NULL)
    {
        pom = prvi;
        prvi->x = drugi->x;
        drugi->x = pom->x;
        prvi = prvi->next;
        drugi = drugi->next;
    }
}

NODE* invert1(NODE *first1)
{
    NODE *p,*q,*r;
    p = first1;
    q = NULL;
    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
        first1 = q;
        return first1;
}

NODE* invert2(NODE *first2)
{
    NODE *p,*q,*r;
    p = first2;
    q = NULL;
    while(p != NULL)
    {
        p = q;
        q = p;
        r = p->next;
        q->next = r;
    }
        first2 = q;
        return first2;
}

int main()
{
    create1(15);
    create1(35);
    create1(45);
    create1(5);
    create2(29);
    create2(38);
    create2(73);
    create2(63);
    brisiPoslePozicije1(3);
    spoji(first1,first2);
    display1();

    return 0;
}