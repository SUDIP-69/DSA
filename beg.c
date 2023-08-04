#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

void ins(int n)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    nn->data=n;
    nn->next=NULL;
    if(head==NULL)
        head=nn;
    else
    {
        nn->next=head;
        head=nn;
    }
}

void sort()
{
    struct node *index1=head,*index2;
    int temp;
    for(;index1!=NULL;index1=index1->next)
    {
        for(index2=index1->next;index2!=NULL;index2=index2->next)
        {
            if(index1->data>index2->data)
            {
                temp=index1->data;
                index1->data=index2->data;
                index2->data=temp;
            }
        }
    }
}

void show()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void rev(struct node **x)
{
    struct node *q,*r,*s;

    q=*x; //first node
    r=NULL;

    //traverse the list
    while(q!=NULL)
    {
        s=r;
        r=q;
        q=q->next;
        r->next=s;
    }

    *x=r;
}

int main()
{
    ins(2);
    ins(3);
    show();
    rev(&head);
    show();
    sort();
    show();
}