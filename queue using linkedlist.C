
#include <stdio.h>
#include<stdlib.h>
struct node{
    int p;                          //p is for data that has to be stored in list 
    struct node *next;                       //n is  for pointing to next element 
};
struct node * neck =NULL;       //neck is my pointer for deleting                                                                       
struct node * back=NULL;       //back is my pointer  for adding  
void enequeue(int x)       
{                       
   struct node *u;
   u=(struct node *)malloc(sizeof(struct node));
    u->p=x;                     // adding element to node 
    u->next=NULL;              // next pointer pointing to null
    if(neck==NULL&&back==NULL)  // first , last node to neck
    neck=back=u;              // all pointing to neck 
    back->next=u;             // data added inorder of queue 
    back=u;                  // back is pointing to latest added element 
}
void dequeue()     
{                                  
    neck=neck->next;        // deleting element from neck 
}
void main()
{
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
    neck=neck->next;
    }
}
