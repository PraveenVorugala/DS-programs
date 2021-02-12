#include<stdio.h>
int flag[9];  // flag array for checking 
int parent(int i)  // parent function to check for any cycle
{
    
	while(flag[i])  // loop that determines parent 
	i=flag[i];
	return i;
}
int notcycle(int i,int j)  // function to check if cycle is present 
{
	if(i!=j)  // check both parents
	{
		flag[j]=i;  // making flag for future refrence 
		return 1;
	}
	return 0;
}
void main()
{
    int minedge,cost=0,adj[9][9];
    int a,b,u,v,n,e=1;
    int i,j;
    printf("no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&adj[i][j]);  // matrix form of graph
			if(adj[i][j]==0)
				adj[i][j]=5000;  // edges which are not present have infinite distance
		}
	}
	while(e < n) // spanning tree will have edges one less than vertices
	{
		for(i=1,minedge=5000;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(adj[i][j] < minedge)  // shortest edge is found in this loops
				{
					minedge=adj[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=parent(u);  // finding parent 
		v=parent(v);  // finding parent for both vertices 
 		if(notcycle(u,v))
		{
			printf("\n%d edge (%d,%d) =%d\n",e,a,b,minedge);  // added edge in spanning tree
			cost +=minedge;  
			e++;
		}
		adj[a][b]=adj[b][a]=5000;  // making the added edge is invalid for future refrence
	}
	printf("\n\tMinimum cost = %d\n",cost);

}