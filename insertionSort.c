#include<stdio.h>
#include <stdlib.h>

int main()
{
    int n,a[1000],i,j,key;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        key=a[i];
        for(j=i-1;j>=0&&a[j]>key;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=key;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    
}
