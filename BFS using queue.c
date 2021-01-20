#include<stdio.h>
 void bfs(int a[6][6],int w,int v)
    {
    int q[10]={0,0,0,0,0,0,0,0,0,0};  // intialised to zero because to be used again 
    int s=0,t=1,e=1,m=7,h,u;
    int p[10];
    int f[10]={0,0,0,0,0,0,0,0,0.0};
    f[0]=1;  // first element added to queue flag 
    q[0]=p[0]=v;
   printf("%d\n",v);
   while(m!=0)   
   {
    for(int i=0;i<w;i++)
    {
        if(a[s][i]==1&& f[i]!=1)  // check if edge is present and if already present in queue 
       {
        q[t]=i;
        p[t]=q[t]+v;  //adding to final output 
       t++;
        for(u=0;u<t;u++)
        printf("%d",p[u]);
        printf("\n");
       f[i]=1;   // flag to check queue presence 
       }
       }
       s=q[e];
        m--;
        e++;
   } 
    }
void main()
{
    int s=5;
    int k=6;
    int a[6][6]={ {0,1,1,1,0},  // matrix form of the graph 
                  {1,0,1,0,0},
                  {1,1,0,0,1},
                  {1,0,0,0,0},
                  {0,0,1,0,0}};


    int b[6][6]={ {0,1,0,1,0,0},  // matrix form of graph 
                  {1,0,1,0,1,0},
                  {0,1,0,0,0,0},
                  {1,0,0,0,0,0},
                  {0,1,0,0,0,1},
                  {0,0,0,0,0,1}};
   printf("BFS for first graph\n");
   bfs(a,s,0);
   printf("BFS for second graph\n");
   bfs(b,k,1);
}