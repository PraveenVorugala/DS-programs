#include<stdio.h> 
void floydwarshall(int adjmat[9][9],int n) 
{ 
	int i,j,midoffset,y=1;  
	for(midoffset=0;midoffset<n;midoffset++)  // midoffset is a intermediate node for floydwarshall
	{ 
		for(i=0;i<n;i++) 
		{ 
			for(j=0;j<n;j++) 
			{ 
			    if(i!=j)
			    {
				if(adjmat[i][midoffset]+adjmat[midoffset][j]<adjmat[i][j]) // check condition for least distance 
					adjmat[i][j]=adjmat[i][midoffset]+adjmat[midoffset][j];  // least edge is added in the adjancey matrix 
			    }
			    } 
		}
		printf("after %d iteration\n",y);
for(int p=0;p<n;p++) 
	{ 
		for(int r=0;r<n;r++) 
		{ 
				printf("%d,",adjmat[p][r]);  // after every iteration adjancey matrix is printed 
		} 
		printf("\n"); 
	} 
	printf("\n");
	y++;
	} 
} 
void main() 
{ 
    int n;
    int graph[9][9];
    scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<n;j++)
	{
	scanf("%d",&graph[i][j]);
	if(i!=j)
	{
	if(graph[i][j]==0)
	graph[i][j]=5000;
	}
	}}
	floydwarshall(graph,n);  //calling floyd warshall function
} 
