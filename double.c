#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void ins(int data)
{
    struct node *beg = head;
    struct node *end = tail;
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    nn->prev=NULL;
    if (head == NULL)
    {
        head = nn;
        tail=nn;
    }
    else
    {
        nn->next=beg;
        head->prev=nn;
        head=nn;
    }
}

void show_head()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
void show_tail()
{
    struct node *temp=tail;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->prev;
    }
}

int main()
{
    ins(3);
    ins(4);
    ins(1);
    show_head();
    printf("\n");
    show_tail();
}