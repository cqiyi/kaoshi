/*
４、数据结构 上机  图 邻接表 DFS BFS
*/
#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 10 /*设最大顶点数为10*/
typedef struct node { /*边表结点*/
	int adjvex;
	struct node *next;
} EdgeNode;
typedef char Vertextype;
typedef struct vnode { /*顶点表结点*/
	char vertex;
	EdgeNode *firstedge;
} VertexNode;
typedef VertexNode AdjList[10];
typedef struct {
	AdjList adjlist;
	int n,e;
} ALGraph;
#define FALSE 0
#define TRUE 1
#define NULL 0
#define Error printf
int visited[10];
void CreateALGraph(ALGraph *G);
void DFSTraverseAL(ALGraph *G);
void BFSTraverseAL(ALGraph *G);
void DFSAL(ALGraph *G,int i);
void BFSAL(ALGraph *G,int i);
#define QueueSize 30 /*假定预分配的队列空间最多为30*/
typedef int DataType; /*队列中的元素类型为字符型*/
typedef struct {
	int front; /*队头指针，队非空时指向队头元素*/
	int rear; /*队尾指针，队非空时指向队尾元素的下一位置*/
	int count; /*计数器，记录队中元素总数*/
	DataType data[QueueSize];
} CirQueue;
void InitQueue(CirQueue *Q) { /*初始队列*/
	Q->front=Q->rear=0;
	Q->count=0;
}
int QueueEmpty(CirQueue *Q) { /*判队空*/
	return Q->count==0;
}
int QueueFull(CirQueue *Q) { /*判队满*/
	return Q->count==QueueSize;
}
void EnQueue(CirQueue *Q,DataType x) { /*入队*/
	if (QueueFull(Q))
		Error("Queue overflow"); /*队满上溢*/
	else {
		Q->count++; /*队列元素个数加1*/
		Q->data[Q->rear]=x; /*新元素插入队列*/
		Q->rear=(Q->rear+1)%QueueSize; /*循环队列的尾指针加1*/
	}
}
DataType DeQueue(CirQueue *Q) { /*出队*/
	DataType temp;
	if (QueueEmpty(Q))
		Error("Queue underflow"); /*队空下溢*/
	else {
		temp=Q->data[Q->front];
		Q->count--; /*队列元素个数减1*/
		Q->front=(Q->front+1)%QueueSize; /*循环队列的头指针加1*/
		return temp;
	}
}
main() {
	ALGraph *G;
	char ch1,ch2;
	printf("建立一个有向图的邻接表表示\n");
	CreateALGraph(G);
	printf("已创建了一个邻接表存储的图\n");
	ch1='y';
	while(ch1=='y' || ch1=='Y') {
		printf("\n请选择下列*作：");
		printf("\nA------------------更新邻接表存储的图");
		printf("\nB------------------深度优先遍历");
		printf("\nC------------------广度优先遍历");
		printf("\nD------------------退出\n");
		scanf("\n%c",&ch2);
		switch (ch2) {
		case 'A':
		case 'a':
			CreateALGraph(G);
			printf("创建一个图的邻接表的*作完成。\n");
			break;
		case 'B':
		case 'b':
			DFSTraverseAL(G);
			break;
		case 'C':
		case 'c':
			BFSTraverseAL(G);
			break;
		case 'D':
		case 'd':
			ch1='n';
			break;
		default:
			ch1='n';
		}
	}
}

void CreateALGraph(ALGraph *G) {
	/*建立有向图的邻接表存储*/
	int i,j,k;
	EdgeNode * s;
	printf("请输入顶点数和边数(输入格式为:顶点数,边数)：\n");
	scanf("%d,%d",&(G->n),&(G->e)); /*读入顶点数和边数*/
	printf("请输入顶点信息(输入格式为:顶点号<CR>)：\n");
	for (i=0; i<G->n; i++) { /*建立有n个顶点的顶点表*/
		scanf("\n%c",&(G->adjlist[i].vertex)); /*读入顶点信息*/
		G->adjlist[i].firstedge=NULL; /*顶点的边表头指针设为空*/
	}
	printf("请输入边的信息(输入格式为:i,j)：\n");
	for (k=0; k<G->e; k++) { /*建立边表*/
		scanf("\n%d,%d",&i,&j); /*读入边<Vi,Vj>的顶点对应序号*/
		s=(EdgeNode*)malloc(sizeof(EdgeNode)); /*生成新边表结点s*/
		s->adjvex=j; /*邻接点序号为j*/
		s->next=G->adjlist[i].firstedge;
		/*将新边表结点s插入到顶点Vi的边表头部*/
		G->adjlist[i].firstedge=s;
	}
}/*CreateALGraph*/

void DFSTraverseAL(ALGraph *G) {
	/*深度优先遍历以邻接表存储的图G*/
	int i;
	for (i=0; i<G->n; i++)
		visited[i]=FALSE; /*标志向量初始化*/
	for (i=0; i<G->n; i++)
		if (!visited[i]) DFSAL(G,i); /*Vi未访问过，从Vi开始DFS搜索*/
}/*DFSTraveseAL*/
void BFSTraverseAL(ALGraph *G) {
	/*广度优先遍历以邻接表存储的图G*/
	int i;
	for (i=0; i<G->n; i++)
		visited[i]=FALSE; /*标志向量初始化*/
	for (i=0; i<G->n; i++)
		if (!visited[i]) BFSAL(G,i); /* Vi未访问过，从Vi开始BFS搜索*/
}/*BFSTraverseAL*/

void DFSAL(ALGraph *G,int i) {
	/*以Vi为出发点对邻接表存储的图G进行DFS搜索*/
	EdgeNode *p;
	printf("visit vertex:V%c\n",G->adjlist[i].vertex); /*访问顶点Vi*/
	visited[i]=TRUE; /*标记Vi已访问*/
	p=G->adjlist[i].firstedge; /*取Vi边表的头指针*/
	while(p) { /*依次搜索Vi的邻接点Vj，j=p->adjva*/
		if (!visited[p->adjvex])
			/*若Vj尚未访问，则以Vj为出发点向纵深搜索*/
			DFSAL(G,p->adjvex);
		p=p->next; /*找Vi的下一个邻接点*/
	}
}/*DFSAL*/

void BFSAL(ALGraph *G,int k) {
	/*以Vk为出发点对邻接表存储的图G进行BFS搜索*/
	int i;
	CirQueue Q;
	EdgeNode *p;
	InitQueue(&Q); /*初始化队列*/
	printf("visit vertex:V%c\n",G->adjlist[k].vertex); /*访问原点Vk*/
	visited[k]=TRUE;
	EnQueue(&Q,k); /*访问Vk后将其序号入队列*/
	while(!QueueEmpty(&Q)) { /*队非空则执行*/
		i=DeQueue(&Q); /*相当于Vi出队*/
		p=G->adjlist[i].firstedge; /*取Vi的边表指针*/
		while(p) { /*依次搜索Vi的邻接点Vj*/
			if (!visited[p->adjvex]) { /*若Vj未访问过访问Vj*/
				printf("visit vertex:V%c\n",G->adjlist[p->adjvex].vertex);
				visited[p->adjvex]=TRUE; /*置访问过标志*/
				EnQueue(&Q,p->adjvex); /*将访问过的Vj入队列*/
			}
			p=p->next; /*找Vi的下一个邻接点*/
		}
	}
}/*BFSAL*/
