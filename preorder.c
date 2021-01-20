#include<stdio.h>
int in[100],po[100],pr[100];
int r,t;
int k=0;
void convert(int a,int p)  // convert function with first and last element index 
{
    int i,c,x;
    x=po[r];  // last element is stored in x
    if(a>p)  
    return;
        for(i=0;i<=t;i++)
        {
            if(in[i]==x)  // finding root element 
            c=i; // root element index stored 
        }
        r--;  // post order index decreement 
        convert(c+1,p); // recursive call for left sub tree 
        convert(a,c-1);  // recursive call for right sub tree  
        pr[k++]=x;   // root element at last of post order 
}
int main()
{
    int i,n;
    scanf("%d",&n);
    printf("inorder\n");
    for(i=0;i<n;i++)
    scanf("%d",&in[i]); // inorder elements which is input 
    printf("postorder\n");
    for(i=0;i<n;i++)
    scanf("%d",&po[i]);  // postorder elements as input 
    t=n-1;  // inorder last index 
    r=n-1;  // postorder last index 
    convert(0,t);  // convert function 
    for(i=t;i>=0;i--)
    printf("%d ",pr[i]);
}