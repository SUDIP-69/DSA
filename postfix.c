#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *stack;
stack head = NULL;

void peek()
{
    stack temp = head;
    if (temp == NULL)
        printf("Empty stack!!");
    else
    {
        printf("\nStack elements: ");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int isempty(stack s)
{
    if (s == NULL)
        return 1;
    else
        return 0;
}

stack push(stack s, int x)
{
    stack nn = (stack)malloc(sizeof(struct node));
    nn->data = x;
    nn->next = NULL;
    if (s == NULL)
        s = nn;

    else
    {
        nn->next = s;
        s = nn;
    }

    return s;
}

stack pop(stack s)
{
    stack temp = s;
    if (isempty(s))
        printf("\nUnderflow.\n");

    else
    {
        printf("\nPopped Element: %d", s->data);
        s = s->next;
        free(temp);
    }
    return s;
}

void main()
{
    int x, ch;
    do
    {
        printf("\n\nMENU\n----------------\n");
        printf("1.push\n2.pop\n3.peek\n4.exit\nENTER your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be pushed: ");
            scanf("%d", &x);
            head = push(head, x);
            break;

        case 2:
            head = pop(head);
            break;

        case 3:
            peek();
            break;

        case 4:
            return;
            break;

        default:
            printf("\nInvalid Input!!\n");
            peek();
            return;
            break;
        }
    }while(1>0);
}