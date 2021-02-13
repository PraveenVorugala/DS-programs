#include <stdio.h>
int a[100],i=0;               //global array and i 
void push(int x)            // push by using i and into array 
{
    a[i]=x;
    i++;   
}
void pop()                   //pop by using same i and out of array 
{
 i=i-1;
   
}
void display()            // displaying array with k
{
    int k;
    for(k=i-1;k>=0;k--)
    printf("%d,",a[k]);
}
void main()
{
    clrscr();
    push(5);
    push(10);
    push(15);
    pop();
    push(20);
    push(25);
    pop();
    push(23);
    display();
    getch();
}
