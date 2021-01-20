#include<stdio.h>
int a[100],i=0,j=0,k=0;             //i,j for front and back end of queue 
int b[100];                     // a array and b array are queue’s
void enequeue(int x)            //adding elements with i.
{
    a[i]=x;
    i++;
}


void dequeue()                //deleting elements with j.
{
    i--;
}
void push(int x)   // easy adding function
{
    int y=x;
    enequeue(y);     // using enequeue operation in push.
}
void pop()         // costly deleting function.
{
    int p,m,y,t;
    y=0;
    t=0;
    for(m=j;m<i-1;m++)  
    {
        b[m]=a[y];
        y++;
        t++;
    }
    j=m;
    p=j-1;
    dequeue();  // using dequeue operation of queue in pop.
    while(t!=0)
    {
        a[i]=b[k];
        t--;
        i++;
        k++;
    }
}
void main()
{
    int k;
    push(40);
    push(60);
    push(80);
    push(90);
    pop();
    push(100);
    pop();
    for(k=j;k<i;k++)              //displaying elements with k.
    {
     printf("%d,",a[k]);
    }
}
