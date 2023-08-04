#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void ins(int data)
{
    struct node *temp = head;
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;
    if (head == NULL)
        head = nn;
    else
    {
        for (; temp->next != NULL; temp = temp->next)
            ;
        temp->next = nn;
    }
}

void dlt()
{
    struct node *temp = head;
    struct node *t;
    while(temp->next!=NULL)
    {
        t=temp;
        temp=temp->next;
    }
    free(temp);
    t->next = NULL;
}

void show()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main()
{
    ins(3);
    ins(4);
    ins(1);
    show();
    printf("\nAfter deletion of the last element.\n");
    dlt();
    ins(5);
    show();
}