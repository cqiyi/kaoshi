/*
编一C程序，它能根据读入的数据构造有向图G，并输出G的DFS遍历序列（从V0开始），图的输入形式为n V0 Vi0 V1 Vi1 V2 Vi2...Vi Vin -1 -1（-1，-1为输入结束标记，其余的值都>=0且<n），它们都是整数，且100>n>0。
（注：程序的可执行文件名必须是 e3.exe）
*/

#include <stdio.h>
typedef enum {False,True} Boolean;

int G[100][100];
int n;

void CreatG() /*建立图的邻接矩阵G[][]*/
{
	int i,j;
	printf("Input the number of the node:");
	scanf("%d",&n);
	printf("\n");
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			G[i][j]=0;
	do
	{
		scanf("%d %d",&i,&j);
		G[i][j]=1;
	}
	while ((i!=-1)&&(j!=-1));
}

void TopSort() /*拓扑排序,输出拓扑序列*/
{
	int i,j;
	int degree[100]; /*按照无前驱顶点优先思想,degree[]存放个节点的入度.*/
	Boolean visited[100],flag=True;
	printf("The Topolgical Order as follow:");
	for (i=0; i<n; i++)
	{
		degree[i]=0;
		visited[i]=False;
	}
	printf("\n");
	while(flag==True)
	{
		for (i=0; i<n; i++)
			for (j=0; j<n; j++)
				degree[i]=G[j][i]+degree[i];
		i=0;
		while ((i<n)&&(degree[i]!=0)||visited[i]==True) i++; /*最先输出入度为0的顶点.*/
		if (i<n) /*所有节点均已输出结束,否则说明存在环,无拓扑序列*/
		{
			printf(" %d",i);
			visited[i]=True;
			for(j=0; j<n; j++)
			{
				G[i][j]=0;
				degree[j]=0;
			}
		}
		else flag=False;
	}
}

main()
{
	CreatG();
	TopSort();
}