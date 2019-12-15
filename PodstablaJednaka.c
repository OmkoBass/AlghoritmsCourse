#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *left;
    struct node *right;
}NODE;

NODE* create(int vrednost)
{
    NODE *temp = (NODE*) malloc(sizeof(NODE));
    temp->x = vrednost;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int brojCvorovaStabla(NODE *root)
{
    int br = 0;
    if(root != NULL)
    {
        br++;
        br = br + brojCvorovaStabla(root->left);
        br = br + brojCvorovaStabla(root->right);
    }
    return br;
}

int main()
{
    NODE *koren = create(32);
    koren->left = create(16);
    koren->right = create(566);
    koren->left->right = create(17);
    koren->left->left = create(1);
    koren->left->left->left = create(192);

    int levo = brojCvorovaStabla(koren->left);
    int desno = brojCvorovaStabla(koren->right);

    if(levo == desno)
    {
        printf("Jednaki broj cvorova\n");
    }

    else 
    {
        printf("Nisu jednaki\n");
    }

    return 0;
}