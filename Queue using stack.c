#include <stdio.h>    
int a[100],b[100];     // 2 stacks are taken for creating queue.
int i,j,k,c=0;
void push(int w)   //easy adding function of push
{
  a[i]=w;
  i++;
  c++;
}


void pop()     // deletion costly function of pop.
{ 
    int m,u;
    u=i;
    for(m=0;m<i;m++)  //loop for copying into another stack. 
    {
    b[m]=a[u];
    u--;
    }
    m--;
    j=m;
}


void eneque(int x)   
{
    int y=x;
    push(y);          //push operation of stack used in eneque
}
void dequee()     
{ 
    pop();            //pop operation of stack used in dequee.
    for(k=0;k<i-1;k++)  
    {
        a[k]=b[j];  
        j--;
    }
    i--;
}




void main()
{
int t;
eneque(30);    // we call eneque function for queue adding 
eneque(50);
eneque(70);
dequee();   // we call dequee function for queue deletion.
eneque(45);
eneque(87);
dequee();
for(t=0;t<i;t++)
printf("%d,",a[t]);   // display of queue.
}

