#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
node *last = NULL;

void ins_strt(int x)
{
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = head;
    if (head == NULL)
        head = last = nn;
    else
    {
        nn->next = head;
        head = nn;
        last->next = head;
    }
}

void ins_end(int x)
{
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = head;
    if (head == NULL)
        head = last = nn;
    else
    {
        last->next = nn;
        last = nn;
    }
}

void show()
{
    node *temp = head;
    printf("%d\t", temp->data);
    temp = temp->next;
    while (temp != head)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void del_strt()
{
    node *temp = head;
    if (head == NULL)
    {
        printf("\nOut of bound!!");
        return;
    }
    if (head == last)
    {
        printf("\nDeleted element: %d", temp->data);
        free(temp);
        head = NULL;
    }
    else
    {
        head = head->next;
        last->next = head;
        printf("\nDeleted element: %d", temp->data);
        free(temp);
    }
}

void del_end()
{
    node *temp = head;
    if (head == NULL)
    {
        printf("\nOut of bound!!");
        return;
    }
    if (head == last)
    {
        printf("\nDeleted element: %d", temp->data);
        free(temp);
        head = NULL;
    }
    else
    {
        for (; temp->next->next != head; temp = temp->next)
            ;
        temp->next = head;
        printf("\nDeleted Element is: %d", last->data);
        free(last);
        last = temp;
    }
}

int main()
{
    ins_strt(3);
    ins_strt(9);
    show();
    del_strt();
    del_end();
    del_strt();
    ins_end(1);
    ins_end(0);
    ins_end(2);
    ins_end(4);
    printf("\n\nAfter deletion from strt: ");
    show();
    del_end();
    del_end();
    printf("\n\nAfter deletion from end: ");
    show();
}