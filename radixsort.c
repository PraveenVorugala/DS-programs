#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;  
};
struct node *temp=NULL;  
struct node *h=NULL;  
struct node *end=NULL;  
int g=0;
int maxdigits(int a[],int y)
{
    int i,s=a[0],c=0;
    for(i=0;i<y;i++)
    {
        if(s<a[i+1])   
        s=a[i+1];
    }
    while(s!=0)
    {
        c++; 
        s=s/10;
    }
    return c;
}
void insert(int n)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    if(g==0)
    {
    p->data=n;  
    p->prev=temp;   
    p->next =NULL; 
    temp=h=p;  
    g++;
    }
    else
    {
     p->data=n;  
     p->prev=temp;  
     temp->next=p;  
     temp=p; 
     end=p;
    }
}
void radixsort(struct node *p,int d)
{
      for(int i=1,j=1;j<=d;i=i*10,j++)
     {
     struct node *r;  
     struct node *v;
     v=p->next;   
     while(v!=NULL)
     {
     int k=v->data;  
     int f=v->data/i;  
     f=f%10; 
     r=v->prev;  
     int u=r->data/i;  
     u=u%10;
     while(r!=NULL && u>f)  
     {
     (r->next)->data=r->data;
     r=r->prev;
     if(r!=NULL)
      {
      u=r->data/i;
      u=u%10;
      }
      }
      if(r!=NULL) 
      (r->next)->data=k;
      else 
      p->data=k;
      v=v->next;
      }
      }
}
int main()
{
    int n,a[100],i,r;
    scanf("%d",&n);
    if(n<=0)  
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
        if(a[i]<0)  
        {
        printf("INVALID INPUT");
        return 0;
        }    
    }
    for(i=0;i<n;i++)
    insert(a[i]);   
    r=maxdigits(a,n);  
    radixsort(h,r);  
    while(h!=NULL)
    {
        printf("%d,",h->data);   
        h=h->next;
    }
    }
    return 0;
}