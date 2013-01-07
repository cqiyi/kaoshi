//有向图的深度优先遍历

#include<stdio.h>
#define MaxSize 100
int visited[MaxSize] = {0};
typedef struct {
	int edges[MaxSize][MaxSize];
	int vexs[MaxSize];
	int n;
} MGraph;
void DFS(MGraph * L,int i)
{
	int j;
	printf("%d ",L -> vexs[i]);
	visited[i] = 1;
	for(j = 0; j < L -> n; j++)
		if(L -> edges[i][j] == 1 && !visited[j])
			DFS(L,j);
}
void DFSTraver(MGraph * L)
{
	int i;
	for(i = 0; i < L -> n; i++)
		visited[i] = 0;
	for(i = 0; i < L -> n; i++)
		if(!visited[i])
			DFS(L,i);
}
void MakeAdjM(MGraph * L)
{
	int i,j,n;
	printf("Input the data:\n");
	scanf("%d",&n);
	L -> n = n;
	for(i = 0; i < n; i++)
		L -> vexs[i] = i;
	do {
		scanf("%d%d",&i,&j);
		if(i == -1 && j == -1)
			break;
		L -> edges[i][j] = 1;
	} while(1);
}
void main()
{
	MGraph g;
	MakeAdjM(&g);
	printf("visit the vertex:\n");
	DFSTraver(&g);
}