#include <stdio.h>
void fun(int a[])
{
    int i,j;
    int t;
    for(i=0;i<10;i++)   //loop for comparing elements
    {
        for(j=i+1;j<10;j++)
        {
            if(a[i]>a[j])   
            {
              t=a[i];   // swapping elements 
              a[i]=a[j];
              a[j]=t;
            }
        }
    }
}
void main()
{
    int a[100]={25,10,6,30,5,10,95,48,10,13};  // taking input
    int i,value=10,e,b=0,s;
    fun(a);  // calling function 
    for(i=0;i<10;i++)
    {
        if(a[i]==value)  // finding out poistion of 10 
        {
        if(b==1)
        s=i;  // starting occurence of 10
        e=i+1;  // ending occurence of 10
        b++;  // counts how many occurences of 10
        }
    }
    for(i=0;i<10;i++)
    printf("%d,",a[i]);
    printf("\n");
    printf("starting occurence is %d\n",s);
    printf("ending occurence is %d",e);
}
