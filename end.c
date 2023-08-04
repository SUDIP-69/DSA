#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void ins(int n)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        temp->data = n;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        temp = head;
        for (; temp->next != NULL; temp = temp->next)
            ;
        nn->data = n;
        nn->next = NULL;
        temp->next = nn;
    }
}

void show()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void re() // head is the variable pointing or to point to 1st node.
{
    struct node *ptr = head;
    int temp;
    if (head == NULL && head->next == NULL) // 0 or 1 node
    {
        return;
    }
    else
    {
        for (; ptr != NULL && ptr->next != NULL; ptr = ptr->next->next)
        {
            temp = ptr->data;
            ptr->data = ptr->next->data;
            ptr->next->data = temp;
        }
    }
}

void format()
{
    struct node *temp=head;
    int count=0;
    struct node *sub1=NULL, *sub2=NULL;
    while(temp!=NULL)
    {
        if(count%2==0)
        {
            sub1->next=temp;
        }
        else
        {}
    }
}

int main()
{
    ins(3);
    ins(4);
    ins(1);
    ins(2);
    ins(7);
    show();
    printf("\n\n");
    re();   //swaps 2 consecutive elements
    show();
    printf("\n\n");
    format();
    show();
}