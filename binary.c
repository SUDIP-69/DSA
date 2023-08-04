#include <stdio.h>
#include <stdlib.h>

int i,j;

void search(int l,int u,int a[],int x)
{
    int mid=(u+l)/2;
    if(a[mid]==x)
    {
        printf("search successful!!");
        exit(0);
    }
    if(x<a[mid])
    search(l,mid-1,a,x);
    if(x>a[mid])
    search(mid+1,u,a,x);
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
    search(0,4,a,x);
}