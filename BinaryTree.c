#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *left;
    struct node *right;
}NODE;

NODE *root = NULL;
NODE *temp = NULL;

NODE* create(int vrednost)
{
    temp = (NODE*)malloc(sizeof(NODE));
    temp->x = vrednost;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void preOrder(NODE *koren)
{
    if(koren != NULL)
    {
    printf("%d ", koren->x);
    preOrder(koren->left);
    preOrder(koren->right);
    }
}

void inOrder(NODE *koren)
{
    if(koren != NULL)
    {
        inOrder(koren->left);
        printf("%d ", koren->x);
        inOrder(koren->right);
    }
}

void postOrder(NODE *koren)
{
    if(koren != NULL)
    {
        postOrder(koren->left);
        postOrder(koren->right);
        printf("%d ", koren->x);
    }
}

void delete(NODE* koren)
{
    if (koren)
    {
        delete(koren->left);
        delete(koren->right);
        free(koren);
    }
}

void printLeaf(NODE *root)
{
    if(root != NULL)
    {
    if((root->left == NULL) && (root->right == NULL))
    {
        printf("%d ", root->x);
    }
    printLeaf(root->left);
    printLeaf(root->right);
    }
}

int sumTree(NODE *root)
{
    int s = 0;
    if(root != NULL)
    {
        s += root->x + sumTree(root->left) + sumTree(root->right);
    }
    return s;
}

int brEl(NODE *root)
{
    int br = 0;
    if(root != NULL)
    {
        br += 1 + brEl(root->left) + brEl(root->right);
    }
    return br;
}

int nalazi(NODE *root, int element)
{
    if(root != NULL)
    {
        if(root->x == element)
        {
            return 0;
        }
        else if(nalazi(root->left, element) == 0 || (nalazi(root->right, element) == 0))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}

int duzina(NODE *root)
{
    int l = 0;
    int d = 0;
    if(root != NULL)
    {
        l = 1 + duzina(root->left);
        d = 1 + duzina(root->right);
    }
    if(l > d) { return l; }
    else if(d > l) { return d;}
    else {return l; }
}

void brNivo(NODE* root, int nivo)
{
    if(root != NULL)
    {
        if(nivo == 0) { printf("%d\n", root->x); }
        else
        {
            brNivo(root->left, nivo-1);
            brNivo(root->right, nivo-1);
        }
    }
}

void ispisNaNivo(NODE *root, int nivo)
{
    if(root != NULL)
    {
        if(nivo == 0) { printf("%d ", root->x); }
        else
        {
            ispisNaNivo(root->left, nivo-1);
            ispisNaNivo(root->right, nivo-1);
        }
    }
    printf("\n");
}

int zbirNaNivo(NODE *root, int nivo)
{
    int s = 0;
    if(root != NULL)
    {
        if(nivo == 0) { s = s + root->x; }
        else
        {
            s = s + zbirNaNivo(root->left, nivo-1);
            s = s + zbirNaNivo(root->right, nivo-1);
        }
    }
    else
    {
        return 0;
    }
    return s;
}

int zbirListova(NODE *root)
{
    int s = 0;
    if(root != NULL)
    {
        if((root->left == NULL) && (root->right == NULL))
        {
            s += root->x;
        }
        else
        {
            s += zbirListova(root->left);
            s += zbirListova(root->right);
        }
    }
    return s;
}

int main()
{
    root = create(1);
    root->left = create(3);
    root->left->right = create(6);
    root->left->right->right = create(10);
    root->left->left = create(4);
    root->left->left->left = create(5);
    root->left->left->right = create(11);
    root->right = create(7);
    root->right->left = create(8);
    root->right->right = create(9);
    int x = zbirNaNivo(root, 1);
    printf("%d\n", x);

    return 0;
}
