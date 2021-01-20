#include<stdio.h>
#include<math.h>
int c=0;
int digits(int n)
{
    int r,c=0;
    while(n!=0)  
    {
    n=n/10;
    c++;
    }
    return c;  // returns the digits of the number 
}
void prime(int r)
{
    int l=r-1,g=0;
    while(l>=2)  // loop for prime condition 
    {
        if(r%l==0)  // check condition for prime 
        g=1;
        l--;
    }
    if(g!=0) 
    c++;
}
int main()
{
    int t,m,k,n,r;
    scanf("%d",&n);
    r=digits(n);  // function to determine how many digits given number has
    r--;
    if(n<=0)  // invalid condition 
    printf("-1");
    else if(n==1) // if input is one
    printf("0");  
    else
    {
    k=n;
    do
    {
    t=n%10;
    m=n/10;
    n=pow(10,r)*t+m;  
    prime(n);
    }while(n!=k);
    if(c==0)
    printf("1");
    else
    printf("0");
    }
    return 0;
}