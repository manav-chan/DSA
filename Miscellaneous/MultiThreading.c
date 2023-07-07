#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int pn;
    int info;
    struct node *next;
}nodetype;

void insert(nodetype**, nodetype**, int);
void multiprog(nodetype*, nodetype*, int);
void delNode(nodetype**, nodetype**, nodetype*);

int main()
{
    nodetype *front = NULL, *rear = NULL;
    int n,t,i;

    printf("Enter number of processes\n");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    insert(&front, &rear,i+1);

    printf("Enter time slot\n");
    scanf("%d",&t);

    multiprog(front, rear, t);
    return 0;
}

void insert(nodetype **f, nodetype **r, int n)
{
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    if(p == NULL)
    {
        printf("No memory");
        return;
    }

    p->pn = n;
    printf("Enter time required for process %d:\n",n);
    scanf("%d",&(p->info));

    if(*f==NULL && *r==NULL)
    *f = *r = p;
    else
    {
        (*r)->next = p;
        *r = p;
    }
    (*r)->next = *f;
}

void multiprog(nodetype *f, nodetype *r, int t)
{
    nodetype *temp = f;
    int count = 0;

    while(f != NULL && r != NULL)
    {
        count += t;
        temp->info = temp->info - t;
        if(temp->info <= 0)
        {
            nodetype *del = temp;
            printf("Process %d over after %d ns\n",temp->pn, count);
            temp = temp->next;

            delNode(&f, &r, del);
        }
        else
        temp = temp->next;
    }
}

void delNode(nodetype **f, nodetype **r, nodetype* del)
{
    if(*f == *r)
    {
        *f = *r = NULL;
        free(del);
    }
    if(del == *f)
    {
        (*r)->next = (*f)->next;
        *f = (*f)->next;
        free(del);
    }
    else if(del == *r)
    {
        nodetype *temp = *f;
        while(temp->next != *r)
        temp = temp->next;

        temp->next = (*r)->next;
        (*r) = temp;
        free(del);
    }
    else
    {
        nodetype *temp = *f;
        while(temp->next != del)
        temp = temp->next;

        temp->next = temp->next->next;
        free(del);
    }
}