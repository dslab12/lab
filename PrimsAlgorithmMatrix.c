#include<stdio.h>
#include<string.h>
int *MST,totalNodes,matrix[10][10];
//int *key,*parent

int checkMST(int node)
{
//	printf("\nCheck\n");
	int i=0;
	for(i=0;i<totalNodes;i++)
	{
		if(MST[i]==node)
			return 1;
	}
	return 0;
}

void primsAlgorithm(int start)
{
	int count=1,pindex=1,min,selectNode,currNode,i,j,cost=0;
	
	//for start node
	MST[0]=start;
//	key[start]=start;
//	parent[start]=start;
	
	while(count<totalNodes)
	{
		min=999;
		for(i=0;i<totalNodes;i++)
		{
			if(MST[i]!=-1)
			{
				currNode=MST[i];
//				printf("%d ",currNode);
				for(j=0;j<totalNodes;j++)
				{
					if((matrix[currNode][j]!=0)&&(matrix[currNode][j]<min)&&(!(checkMST(j))))
					{
						min=matrix[currNode][j];
						selectNode=j;
						start=currNode;
					}
				}
			}
		}
//		printf("\n");
		MST[pindex]=selectNode;
//		printf("%d -> %d : %d\n",start,selectNode,min);
		printf("%c -> %c : %d\n",65+start,65+selectNode,min);
//		key[selectNode]=min;
//		parent[selectNode]=start;
		count++;
		pindex++;
		cost=cost+min;
	}
	
	printf("\n\nMinimum Cost : %d",cost);
}

void main()
{
	int i,j;
	printf("Enter the number of nodes in the graph : ");
	scanf("%d",&totalNodes);
	MST=(int*)malloc(sizeof(int)*totalNodes);
//	key=(int*)malloc(sizeof(int)*totalNodes);
//	parent=(int*)malloc(sizeof(int)*totalNodes);
	memset(MST, -1, sizeof (int) * totalNodes);
	
//	int matrix[8][8]={
//				{0,4,0,0,8,0,0,0}, //A
//				{4,0,2,0,0,3,0,0}, //B
//				{0,2,0,3,0,5,0,0}, //C
//				{0,0,3,0,0,0,0,2}, //D
//				{8,0,0,0,0,6,1,0}, //E
//				{0,3,5,0,6,0,3,4}, //F
//				{0,0,0,0,1,3,0,5}, //G
//				{0,0,0,2,0,4,5,0}  //H
//			};
	
	printf("\nEnter the Adjacency Matrix : \n");
	for(i=0;i<totalNodes;i++)
	{
		for(j=0;j<totalNodes;j++)
		{
			printf("%c%c : ",(65+i),(65+j));
			scanf("%d",&matrix[i][j]);
		}
	}
//	for(i=0;i<totalNodes;i++)
//		printf("%d ",MST[i]);
//		
//	printf("\n\n");
		
	printf("\n\n\n");
	primsAlgorithm(0);
	
//	printf("MST    : ");
//	for(i=0;i<totalNodes;i++)
//		printf("%c ",65+MST[i]);
//		
//	printf("\n\n         ");
//	for(i=0;i<totalNodes;i++)
//		printf("%c ",65+i);
//	
//	printf("\n         ");
//	for(i=0;i<totalNodes;i++)
//		printf("__");
//		
//	printf("\nParent : ");
//	for(i=0;i<totalNodes;i++)
//		printf("%c ",65+parent[i]);
//		
//	printf("\nKey    : ");
//	for(i=0;i<totalNodes;i++)
//		printf("%d ",key[i]);
}

