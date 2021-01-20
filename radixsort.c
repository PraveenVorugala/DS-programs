#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;  // next and previous pointers 
};
struct node *temp=NULL;  // intialised to null 
struct node *h=NULL;     // head intialised to null
struct node *end=NULL;  // intialised to null 
int g=0;
int maxdigits(int a[],int y)
{
    int i,s=a[0],c=0;
    for(i=0;i<y;i++)
    {
        if(s<a[i+1])   // finding largerst element in array
        s=a[i+1];
    }
    while(s!=0)
    {
        c++;  // finding how many digits it contains
        s=s/10;
    }
    return c;
}
void insert(int n)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    if(g==0)
    {
    p->data=n;  // adding element to node 
    p->prev=temp;   // previous pointer to node when first element then null 
    p->next =NULL;  // next pointer pointing to null
    temp=h=p;  // all are pointing to head element 
    g++;  // first element is inserted 
    }
    else
    {
     p->data=n;  // adding element to node
     p->prev=temp; // previous element pointer  
     temp->next=p;  // next element pointer 
     temp=p; 
     end=p;  
    }
}
void radixsort(struct node *p,int d)
{
      for(int i=1,j=1;j<=d;i=i*10,j++)  // loop for sorting 
     {
     struct node *r;  
     struct node *v;
     v=p->next;   // head next element 
     while(v!=NULL)  // untill last node
     {
     int k=v->data;  //data of node 
     int f=v->data/i;  
     f=f%10; // radix sort by these numbers 
     r=v->prev;  // previous node for comparision 
     int u=r->data/i;  
     u=u%10;   //radix sort by these numbers 
     while(r!=NULL && u>f) // condition to check if previous numbers and present numbers  
     {
     (r->next)->data=r->data;  // replacing place of elements 
     r=r->prev;  
     if(r!=NULL)
      {
      u=r->data/i;
      u=u%10;  // number to check correct place 
      }
      }
      if(r!=NULL) 
      (r->next)->data=k;  
      else 
      p->data=k;  
      v=v->next;  // again process with next element 
      }
      }
}
int main()
{
    int n,a[100],i,r;
    scanf("%d",&n);
    if(n<=0)  // invalid condition
    {
    printf("INVALID INPUT");
    return 0;
    }
    else
    {
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]<0)  // invalid condition
        {
        printf("INVALID INPUT");
        return 0;
        }    
    }
    for(i=0;i<n;i++)
    insert(a[i]);   // insert function 
    r=maxdigits(a,n);  // finding largest element digits 
    radixsort(h,r);  // sort function 
    while(h!=NULL)
    {
        printf("%d,",h->data);   // print data of sorted array 
        h=h->next;
    }
    }
    return 0;
}
