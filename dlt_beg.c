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
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;
    if (head == NULL)
        head = nn;
    else
    {
        nn->next = head;
        head = nn;
    }
}

void dlt()
{
    struct node *temp = head;
    head = temp->next;
    free(temp);
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
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main()
{
    ins(11);
    ins(15);
    ins(1);
    show();
    printf("\nAfter deletion of the first element.\n");
    dlt();
    ins(10);
    show();
    printf("\nAfter sorting the list.\n");
    sort();
    show();
}