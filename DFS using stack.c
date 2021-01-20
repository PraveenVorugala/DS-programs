#include<stdio.h>
int t=1;  
int f[10],st[10];  // stack array  
void dfs(int a[6][6],int s,int g)
{
    st[0]=g; // stack first element intialised to starting vertex 
    int i;      
    for(i=0;i<6;i++)
    {
        if(a[s][i]==1 && f[i]!=1)    // checking if edge is present and if already present in stack 
        {
        st[t]=i+g;   
        t++;
        f[i]=1;   // flag to check stack presence 
    for(int m=0;m<t;m++)
    printf("%d",st[m]);
    printf("\n");
        dfs(a,i,g);    // recursive call
        if(f[i]!=1)
        {
        st[t]=i+1;
        t++;
        }
        }
    }
}
void main()
{
    int a[6][6]={ {0,1,1,1,0},   // graph in terms of matrix
                  {1,0,1,0,0},
                  {1,1,0,0,1},
                  {1,0,0,0,0},
                  {0,0,1,0,0}};
    int b[6][6]={ {0,1,0,1,0,0},  // graph in terms of matrix
                  {1,0,1,0,1,0},
                  {0,1,0,0,0,0},
                  {1,0,0,0,0,0},
                  {0,1,0,0,0,1},
                  {0,0,0,0,0,1}};
    
    int s=0,v=0,h=1;
    f[0]=1;  
    printf("DFS for first graph\n");
   printf("%d\n",s);  // starting vertex
    dfs(a,s,v);   // calling dfs with matrix starting vertex and a temporary variable
    for(int i=0;i<=10;i++)    // making global variables as before so to use again 
    {
        f[i]=0;
        st[i]=0;
    }
    f[0]=1;
    t=1;
    printf("DFS for second graph\n");
    printf("%d\n",h);
    dfs(b,s,h);
}