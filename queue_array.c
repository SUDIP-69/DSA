#include <stdio.h>

int a[10];
int strt=-1,last=-1,n=10;

void enqueue(int x)
{
    if(strt==-1 && last==-1)
        strt=last=0;
    else if (last==n)
        printf("\noverflow");
    else
        last++;
    a[last]=x;
}

void dequeue()
{
    if(strt!=-1 && strt!=last+1)
    {
        printf("\nExpelled element: %d",a[strt++]);
    }
    else
    printf("\nunderflow");
}

void peek()
{
    if(strt!=-1)
    {
        printf("\nPeeked element: %d",a[strt]);
    }
    else
    printf("\nunderflow");
}

void display()
{
    printf("\n\n");
    for(int i=strt;i<=last;i++)
    printf("%d ",a[i]);
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    peek();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
}