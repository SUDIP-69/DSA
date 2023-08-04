#include <stdio.h>
#include <stdlib.h>

int i, j;

int hash(int x)
{
    return(x%5)+3;
}

int main()
{
    int a[]={20,-5,76,101,49};
    int b[]={0,0,0,0,0};
    int x;
    // printf("Enter array elements:");
    // for (i = 0; i < 5; i++)
    //     scanf("%d", &a[i]);
    printf("\nOriginal Array: ");
    for (i = 0; i < 5; i++)
        printf("%d\t", a[i]);
    for (i = 0; i < 5; i++)
    {
        x = hash(a[i]);
        while(b[x]!=0)
        {
            x=(x+ i*i)%5;
            if(x>4)
            x=0;
            if(b[x]==0)
            break;
        }
        b[x]=a[i];
    }
    printf("\nHashed Array: ");
    for (i = 0; i < 5; i++)
        printf("\t%d", b[i]);
}