//Kruskal's Algorithm using adjacency matrix
#include<stdio.h>
#include <stdlib.h>

int n,matrix[10][10];
//			={
//				{0,4,0,0,8,0,0,0}, //A
//				{4,0,2,0,0,3,0,0}, //B
//				{0,2,0,3,0,5,0,0}, //C
//				{0,0,3,0,0,0,0,2}, //D
//				{8,0,0,0,0,6,1,0}, //E
//				{0,3,5,0,6,0,3,4}, //F
//				{0,0,0,0,1,3,0,5}, //G
//				{0,0,0,2,0,4,5,0}  //H
//			};

int comparator(const void *p1,const void *p2)//used by qsort()
{
    const int (*x)[3]=p1;
    const int (*y)[3]=p2;
 
    return (*x)[2]-(*y)[2];
}

void initialize(int parent[]){
	int i;
	for(i=0;i<n;i++)
	{
		parent[i]=i;
	}
	
}

int find(int parent[],int x)
{
	if(parent[x]==x)
	{
//		printf("#%d %d",x,P[x]);
		return x;		
	}
	
//	printf("#$%d %d",x,P[x]);	
	return find(parent,parent[x]);
}

void unionFun(int parent[],int a,int b)
{
	int x,y;
	x=find(parent,a);
	y=find(parent,b);
	if(x==y)
		return;
	
	parent[y]=x;
}

void kruskalAlgo()
{
	int i,j,size=n*n/2;
	int k=0,listSize=0,parent[n];
	int countEdge=0,countMinCost=0;
	int edgeList[size][3];
	
	//initialise parent[]
	initialize(parent);
	
	//creating edgelists
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(matrix[i][j]!=0)
			{
				edgeList[k][0]=i;
				edgeList[k][1]=j;
				edgeList[k][2]=matrix[i][j];
				k++;
			}
		}
	}
	
	listSize=k;
	
	qsort(edgeList, listSize, sizeof(edgeList[0]), comparator);
	
	for(i=0;i<listSize;i++)
	{
		if(find(parent,edgeList[i][0])!=find(parent,edgeList[i][1]))
		{
			unionFun(parent,edgeList[i][0],edgeList[i][1]);
			countMinCost+=edgeList[i][2];
			countEdge++;
			printf("\n%c -> %c : %d",edgeList[i][0]+65,edgeList[i][1]+65,edgeList[i][2]);
		}
		
		if(countEdge>=n-1)
		{
			printf("\n\nMincost : %d",countMinCost);
			return;
		}
	}
}

void main()
{
	int i,j;
	printf("Enter the number of nodes in the graph : ");
	scanf("%d",&n);
	
	printf("\nEnter the Adjacency Matrix : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%c%c : ",(65+i),(65+j));
			scanf("%d",&matrix[i][j]);
		}
	}

	kruskalAlgo();
}
