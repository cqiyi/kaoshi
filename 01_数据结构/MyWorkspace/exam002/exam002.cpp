/**************
2������һ���ն���������������һ�����ݣ���-9999��β�������ǰ���������������У��������ݾ�Ϊ����������ʱ�Կո�ֿ���
**********/

#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;

typedef struct node
{
	KeyType key;
	struct node *lchild,*rchild;
} BSTNode;

typedef BSTNode *BSTree;

BSTree CreateBST(void);
void SearchBST(BSTree T,KeyType Key);
void InsertBST(BSTree *Tptr,KeyType Key);
void DelBSTNode(BSTree *Tptr,KeyType Key);
void InorderBST(BSTree T);

void main()
{
	BSTree T;
	char ch1,ch2;
	KeyType Key;
	printf("����һ�ö����������Ķ�������洢\n");
	T=CreateBST();
	ch1='y';
	while (ch1=='y' || ch1=='Y')
	{
		printf("��ѡ������*����\n");
		printf("1------------------���¶����������洢\n");
		printf("2------------------�����������ϵĲ���\n");
		printf("3------------------�����������ϵĲ���\n");
		printf("4------------------�����������ϵ�ɾ��\n");
		printf("5------------------�����������������\n");
		printf("6------------------�˳�\n");
		scanf("\n%c",&ch2);
		switch (ch2)
		{
		case '1':
			T=CreateBST();
			break;
		case '2':
			printf("\n������Ҫ���ҵ����ݣ�");
			scanf("\n%d",&Key);
			SearchBST(T,Key);
			printf("����*����ϡ�\n");
			break;
		case '3':
			printf("\n������Ҫ��������ݣ�");
			scanf("\n%d",&Key);
			InsertBST(&T,Key);
			printf("����*����ϡ�\n");
			break;
		case '4':
			printf("\n������Ҫɾ�������ݣ�");
			scanf("\n%d",&Key);
			DelBSTNode(&T,Key);
			printf("ɾ��*����ϡ�\n");
			break;
		case '5':
			InorderBST(T);
			printf("\n���������������ϡ�\n");
			break;
		case '6':
			ch1='n';
			break;
		default:
			ch1='n';
		}
	}
}

BSTree CreateBST(void)
{
	BSTree T;
	KeyType Key;
	T=NULL;
	printf("������һ���ؼ���(����0ʱ��������)��\n");
	scanf("%d",&Key);
	while (Key)
	{
		InsertBST(&T,Key);
		printf("��������һ���ؼ���(����0ʱ��������)��\n");
		scanf("\n%d",&Key);
	}
	return T;
}
void SearchBST(BSTree T, KeyType Key)
{
	BSTNode *p=T;
	while(p)
	{
		if(p->key==Key)
		{
			printf("���ҵ�\n");
			return;
		}
		p=(Key<p->key) ? p->lchild:p->rchild;
	}
	printf("û���ҵ�\n");
}

void InsertBST(BSTree *T,KeyType Key)
{
	BSTNode *f,*p;
	p=(*T);
	while(p)
	{
		if(p->key==Key)
		{
			printf("��������Key�������\n");
			return;
		}
		f=p;
		p=(Key<p->key)?p->lchild:p->rchild;
	}
	p=(BSTNode*)malloc(sizeof(BSTNode));
	p->key=Key;
	p->lchild=p->rchild=NULL;
	if ((*T)==NULL) (*T)=p;
	else if (Key<f->key) f->lchild=p;
	else f->rchild=p;
}/*InsertBST*/

void DelBSTNode(BSTree *T,KeyType Key)
{
	BSTNode *parent=NULL, *p, *q,*child;
	p=*T;
	while(p)
	{
		if(p->key==Key) break;
		parent=p;
		p=(Key<p->key)?p->lchild:p->rchild;
	}
	if (!p)
	{
		printf("û���ҵ�Ҫɾ���Ľ��\n");
		return;
	}
	q=p;
	if (q->lchild && q->rchild)
		for (parent=q,p=q->rchild; p->lchild; parent=p,p=p->lchild);
	child=(p->lchild)?p->lchild:p->rchild;
	if (!parent) *T=child;
	else
	{
		if (p==parent->lchild)
			parent->lchild=child;
		else parent->rchild=child;
		if (p!=q)
			q->key=p->key;
	}
	free(p);
}
void InorderBST(BSTree T)
{
	if(T!=NULL)
	{
		InorderBST(T->lchild);
		printf("%5d",T->key);
		InorderBST(T->rchild);
	}
}