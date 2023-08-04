#include <stdio.h>
#include <stdlib.h>

int i,j;

void search(int i,int a[],int x)
{
    if(i>=0)
    {
        if(a[i]==x)
        {
            printf("Search Successful!!");
            exit(0);
        }
        search(--i,a,x);
    }
    printf("Search Unsuccessful!!");
}

int main()
{
    int a[5];
    printf("Enter array elements:");
    for(i=0;i<5;i++)
        scanf("%d",&a[i]);
    printf("\nOriginal Array: ");
    for(i=0;i<5;i++)
        printf("%d\t",a[i]);
    printf("\nEnter element to be searched: ");
    int x;
    scanf("%d",&x);
    search(4,a,x);
}