//make a linked list of 3 nodes

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* mid=(struct node*)malloc(sizeof(struct node));
    struct node* end=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&head->data);
    printf("Enter data: ");
    scanf("%d",&mid->data);
    printf("Enter data: ");
    scanf("%d",&end->data);
    head->next=mid;
    mid->next=end;
    end->next=NULL;
    struct node *header=head;
    while(header!=NULL)
    {
        printf("%d\t",header->data);
        header=header->next;
    }
    return 0;
}