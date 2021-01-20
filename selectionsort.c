#include<stdio.h>
void main()
{
    int i,j,t;
    int n;
    int a[100];  //input array 
    printf("input:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
    for(j=i+1;j<n;j++)
    {
        if(a[i]>a[j])   // check condition for the elements 
        {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    }
}
for(i=0;i<n;i++)
printf("%d ",a[i]);   // printing final output 
}