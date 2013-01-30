#include "queue.h"
#define MAX 5
#define NULL 0
int visited[MAX];

void CreateArrayG(int G[MAX][MAX])
{
	int i,j,e,x,y;
	for(i=0; i<MAX; i++)
		for(j=0; j<MAX; j++)
			G[i][j]=0;

	printf("\n\t qing shu ru bian shu:");
	scanf("%d",&e);
	printf("\n\t qing shu ru zhe xie bian de liang ge ding dian:");

	for(i=0; i<e; i++)
	{
		scanf("%d,%d", &x, &y);
		G[x][y] =1;
		G[y][x]=1;
	}

}
