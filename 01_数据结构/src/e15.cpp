/*
�������ݽṹ �ϻ�  ͼ �ڽӱ� DFS BFS
*/
#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 10 /*����󶥵���Ϊ10*/
typedef struct node { /*�߱���*/
	int adjvex;
	struct node *next;
} EdgeNode;
typedef char Vertextype;
typedef struct vnode { /*�������*/
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
#define QueueSize 30 /*�ٶ�Ԥ����Ķ��пռ����Ϊ30*/
typedef int DataType; /*�����е�Ԫ������Ϊ�ַ���*/
typedef struct {
	int front; /*��ͷָ�룬�ӷǿ�ʱָ���ͷԪ��*/
	int rear; /*��βָ�룬�ӷǿ�ʱָ���βԪ�ص���һλ��*/
	int count; /*����������¼����Ԫ������*/
	DataType data[QueueSize];
} CirQueue;
void InitQueue(CirQueue *Q) { /*��ʼ����*/
	Q->front=Q->rear=0;
	Q->count=0;
}
int QueueEmpty(CirQueue *Q) { /*�жӿ�*/
	return Q->count==0;
}
int QueueFull(CirQueue *Q) { /*�ж���*/
	return Q->count==QueueSize;
}
void EnQueue(CirQueue *Q,DataType x) { /*���*/
	if (QueueFull(Q))
		Error("Queue overflow"); /*��������*/
	else {
		Q->count++; /*����Ԫ�ظ�����1*/
		Q->data[Q->rear]=x; /*��Ԫ�ز������*/
		Q->rear=(Q->rear+1)%QueueSize; /*ѭ�����е�βָ���1*/
	}
}
DataType DeQueue(CirQueue *Q) { /*����*/
	DataType temp;
	if (QueueEmpty(Q))
		Error("Queue underflow"); /*�ӿ�����*/
	else {
		temp=Q->data[Q->front];
		Q->count--; /*����Ԫ�ظ�����1*/
		Q->front=(Q->front+1)%QueueSize; /*ѭ�����е�ͷָ���1*/
		return temp;
	}
}
void main() {
	ALGraph *G;
	char ch1,ch2;
	printf("����һ������ͼ���ڽӱ��ʾ\n");

	G = (ALGraph*)malloc(sizeof(ALGraph));

	CreateALGraph(G);
	printf("�Ѵ�����һ���ڽӱ�洢��ͼ\n");
	ch1='y';
	while(ch1=='y' || ch1=='Y') {
		printf("\n��ѡ������*����");
		printf("\nA------------------�����ڽӱ�洢��ͼ");
		printf("\nB------------------������ȱ���");
		printf("\nC------------------������ȱ���");
		printf("\nD------------------�˳�\n");
		scanf("\n%c",&ch2);
		switch (ch2) {
		case 'A':
		case 'a':
			CreateALGraph(G);
			printf("����һ��ͼ���ڽӱ��*����ɡ�\n");
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
	/*��������ͼ���ڽӱ�洢*/
	int i,j,k;
	EdgeNode * s;
	printf("�����붥�����ͱ���(�����ʽΪ:������,����)��\n");
	scanf("%d,%d",&(G->n),&(G->e)); /*���붥�����ͱ���*/
	printf("�����붥����Ϣ(�����ʽΪ:�����<CR>)��\n");
	for (i=0; i<G->n; i++) { /*������n������Ķ����*/
		scanf("\n%c",&(G->adjlist[i].vertex)); /*���붥����Ϣ*/
		G->adjlist[i].firstedge=NULL; /*����ı߱�ͷָ����Ϊ��*/
	}
	printf("������ߵ���Ϣ(�����ʽΪ:i,j)��\n");
	for (k=0; k<G->e; k++) { /*�����߱�*/
		scanf("\n%d,%d",&i,&j); /*�����<Vi,Vj>�Ķ����Ӧ���*/
		s=(EdgeNode*)malloc(sizeof(EdgeNode)); /*�����±߱���s*/
		s->adjvex=j; /*�ڽӵ����Ϊj*/
		s->next=G->adjlist[i].firstedge;
		/*���±߱���s���뵽����Vi�ı߱�ͷ��*/
		G->adjlist[i].firstedge=s;
	}
}/*CreateALGraph*/

void DFSTraverseAL(ALGraph *G) {
	/*������ȱ������ڽӱ�洢��ͼG*/
	int i;
	for (i=0; i<G->n; i++)
		visited[i]=FALSE; /*��־������ʼ��*/
	for (i=0; i<G->n; i++)
		if (!visited[i]) DFSAL(G,i); /*Viδ���ʹ�����Vi��ʼDFS����*/
}/*DFSTraveseAL*/
void BFSTraverseAL(ALGraph *G) {
	/*������ȱ������ڽӱ�洢��ͼG*/
	int i;
	for (i=0; i<G->n; i++)
		visited[i]=FALSE; /*��־������ʼ��*/
	for (i=0; i<G->n; i++)
		if (!visited[i]) BFSAL(G,i); /* Viδ���ʹ�����Vi��ʼBFS����*/
}/*BFSTraverseAL*/

void DFSAL(ALGraph *G,int i) {
	/*��ViΪ��������ڽӱ�洢��ͼG����DFS����*/
	EdgeNode *p;
	printf("visit vertex:V%c\n",G->adjlist[i].vertex); /*���ʶ���Vi*/
	visited[i]=TRUE; /*���Vi�ѷ���*/
	p=G->adjlist[i].firstedge; /*ȡVi�߱��ͷָ��*/
	while(p) { /*��������Vi���ڽӵ�Vj��j=p->adjva*/
		if (!visited[p->adjvex])
			/*��Vj��δ���ʣ�����VjΪ����������������*/
			DFSAL(G,p->adjvex);
		p=p->next; /*��Vi����һ���ڽӵ�*/
	}
}/*DFSAL*/

void BFSAL(ALGraph *G,int k) {
	/*��VkΪ��������ڽӱ�洢��ͼG����BFS����*/
	int i;
	CirQueue Q;
	EdgeNode *p;
	InitQueue(&Q); /*��ʼ������*/
	printf("visit vertex:V%c\n",G->adjlist[k].vertex); /*����ԭ��Vk*/
	visited[k]=TRUE;
	EnQueue(&Q,k); /*����Vk������������*/
	while(!QueueEmpty(&Q)) { /*�ӷǿ���ִ��*/
		i=DeQueue(&Q); /*�൱��Vi����*/
		p=G->adjlist[i].firstedge; /*ȡVi�ı߱�ָ��*/
		while(p) { /*��������Vi���ڽӵ�Vj*/
			if (!visited[p->adjvex]) { /*��Vjδ���ʹ�����Vj*/
				printf("visit vertex:V%c\n",G->adjlist[p->adjvex].vertex);
				visited[p->adjvex]=TRUE; /*�÷��ʹ���־*/
				EnQueue(&Q,p->adjvex); /*�����ʹ���Vj�����*/
			}
			p=p->next; /*��Vi����һ���ڽӵ�*/
		}
	}
}/*BFSAL*/
