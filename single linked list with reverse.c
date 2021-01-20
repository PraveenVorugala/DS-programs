#include <stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *next;
};
struct node *h=NULL;   // head intialised to NULL
struct node *f=NULL;    // intialised to NULL
struct node *w=NULL;   //  intialised to NULL
void insert()
{
    struct node *q;
  int i;
  scanf("%d",&i);
 q=(struct node*)malloc(sizeof(struct node *));
 q->d=i;  // add elements to node
 q->next=NULL;  // pointer of next element to null 
 if(h==NULL)  // if head is NULL then first element in list 
 h=f=q;
 f->next=q;  // if other elements also in list 
 f=q;
}
void display()
{
 struct node *q;
 q=h;
 while(q!=NULL)  // diplay untill last node 
 {
     printf("%d,",q->d);
     q=q->next;
 }
 printf("\n");
}
void delete()
{
struct node *q;
q=h;  // delete first element 
h=h->next;
}
void search(int a)  // for searching the node which has input element 
{
    int t=0;
    struct node *q;
    q=h;
    while(q!=NULL)
    {
    if(a==q->d)
    printf("pos=%d\n",t+1);  // print position
    q=q->next;
    t++;
    }
}
void re() 
{ 
struct node *q;  
struct node *n; 
q=h; // intialised to head 
while(q!=NULL)  // untill last node 
{ 
    n=q->next;   
    q->next=w;   
    w=q;  // reversing the list 
    q=n; 
    } 
    h=w;  // last node will become head 
}
void insertlast()
{
    
    struct node *q;
    int x;
    scanf("%d",&x);
    q=(struct node*)malloc(sizeof(struct node *));
    q->d=x;
    v=h;
    while(v->next!=NULL)   // traversing nodes until last
    v=v->next;
    v->next=q;   // allocating last node
    q->next=NULL;
    f=q;
}
void insertpos(int z)
{
    struct node *q;
    struct node *v;
    struct node *t;
    q=(struct node*)malloc(sizeof(struct node *));
    int x,k,d=1;
    scanf("%d",&x);
    q->d=x;
    v=h;
    while(d!=z)  // tracing upto given position 
    {
    d++;    
    v=v->next;
    }
    t=(v->next);
    v->next=q;
    q->next=t;
}
void main()
{
    int m,v,z;
    printf("1.insert at first\n");
    printf("2.delete first\n");
    printf("3.search element\n");
    printf("4.display\n");
    printf("5.insert at given position\n");
    printf("6.insert at last\n");
    printf("7.reverse\n");
    printf("8.exit\n");
    while(m!=8)
    {
    printf("enter choice = ");
    scanf("%d",&m);
    switch(m)
    {
    case 1:
    printf("insert value\n");
    insert();
    break;
    case 2:
    printf("deleting first element\n");
    delete();
    break;
    case 3:
    printf("enter value\n");
    scanf("%d",&v);
    search(v);
    break;
    case 4:
    printf("linked list elements\n");
    display();
    break;
    case 5:
    printf("enter postion to insert: ");
    scanf("%d",&z);
    insertpos(z-1);
    break;
    case 6:
    insertlast();
    break;
    case 7:
     printf("linked list reversed\n");
     re();
     break;
    case 8:
    exit(0);
    break;
}
}    
}