#include <stdio.h>
#include<stdlib.h>
struct node{
    int p;                                //p is for data that has to be stored in list
    struct node *next;                      //n is  pointer, pointing to next element
};
struct node *surf =NULL;               //surf is pointer for travesing,push,pop
void display(struct node *o)
{                                      //display is for displaying elements
    while(o!=NULL)
    {
    printf("%d,",o->p);
    o=o->next;
    }
}
void push(int x)                           //node u is used to add elements.
{
   struct node* u;
   u=(struct node *)malloc(sizeof(struct node));
    u->p=x;                       // adding elements to node 
    u->next=surf;                 // next pointer pointing to last node 
    surf=u;                      // surf pointing to latest node  
}
void pop()                               // for pop we make the surf  to  point to next element
{
    surf=surf->next;   // element is deleted from stack by using surf 
}
void main()
{
  push(5);
  push(3);
  push(13);
  pop();
  push(45);
  push(2);
  pop();
  display(surf);
}
