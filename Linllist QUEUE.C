
#include <stdio.h>
#include<stdlib.h>
struct node{
    int p;                                        //p is for data that has to be stored in list 
    struct node *n;                       //n is  for pointing to next element 
};
struct node * neck =NULL;       //neck is my pointer for deleting                                                                       
struct node * back=NULL;       //back is my pointer  for adding  
void enequeue(int x)       
{                                             // enequeue for adding elements at back end    
   struct node *u;
   u=(struct node *)malloc(sizeof(struct node));
    u->p=x;
    u->n=NULL;
    if(neck==NULL&&back==NULL)  // first , last node to neck
    neck=back=u;
    back->n=u;
    back=u;
}
void dequeue()     // deleting elemnts we  make neck move 
{                                  
    neck=neck->n;
}
void main()
{
  clrscr();
  enequeue(5);
  enequeue(3);
  enequeue(13);
  dequeue();
  enequeue(45);
  enequeue(2);
  enequeue(78);
  dequeue();
  while(neck!=NULL)               //here we display queue elements
    {
    printf("%d,",neck->p);
    neck=neck->n;
    }
    getch();
}
