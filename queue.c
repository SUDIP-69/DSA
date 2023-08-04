#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
node *last = NULL;

void enqueue(int x)
{
    node *temp = last;
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = NULL;
    if (head == NULL && last == NULL)
        head = last = nn;
    else
    {
        temp->next = nn;
        last = nn;
    }
}

void dequeue()
{
    node *temp = head;
    if (head != NULL)
    {
        if (head != last)
        {
            printf("\nExpelled element: %d", head->data);
            head = head->next;
        }
        else
        {
            printf("\nExpelled element: %d", head->data);
            head = NULL;
            last = NULL;
        }
    }
    else
        printf("\nUnderflow!!");
}

void show()
{
    node *temp = head;
    printf("\n\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void peek()
{
    if(head!=NULL)
    printf("\nPeeked element: %d",head->data);
    else
    printf("\nUnderflow");
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    show();
    peek();
    dequeue();
    show();
    peek();
}