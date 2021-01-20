#include<stdio.h>
int a[100],i=0,j=0;             //i,j for front and back end of queue 
void enequeue(int x)            //adding elements with i.
{
    a[i]=x;
    i++;
}
void dequeue()                //deleting elements with j.
{
    j++;
}
void main()
{
    int k;
    clrscr();
    enequeue(25);
    enequeue(20);
    enequeue(30);
    enequeue(95);
    dequeue();
    enequeue(80);
    dequeue();
    for(k=j;k<i;k++)              //displaying elements with k.
    {
     printf("%d,",a[k]);
    }
    getch();
}


output
30,95,80
