/**************
2、建立一个空二叉排序树，输入一串数据（以-9999结尾），输出前序和中序遍历。其中：输入数据均为整数，输入时以空格分开。
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
	printf("建立一棵二叉排序树的二叉链表存储\n");
	T=CreateBST();
	ch1='y';
	while (ch1=='y' || ch1=='Y')
	{
		printf("请选择下列*作：\n");
		printf("1------------------更新二叉排序树存储\n");
		printf("2------------------二叉排序树上的查找\n");
		printf("3------------------二叉排序树上的插入\n");
		printf("4------------------二叉排序树上的删除\n");
		printf("5------------------二叉排序树中序输出\n");
		printf("6------------------退出\n");
		scanf("\n%c",&ch2);
		switch (ch2)
		{
		case '1':
			T=CreateBST();
			break;
		case '2':
			printf("\n请输入要查找的数据：");
			scanf("\n%d",&Key);
			SearchBST(T,Key);
			printf("查找*作完毕。\n");
			break;
		case '3':
			printf("\n请输入要插入的数据：");
			scanf("\n%d",&Key);
			InsertBST(&T,Key);
			printf("插入*作完毕。\n");
			break;
		case '4':
			printf("\n请输入要删除的数据：");
			scanf("\n%d",&Key);
			DelBSTNode(&T,Key);
			printf("删除*作完毕。\n");
			break;
		case '5':
			InorderBST(T);
			printf("\n二叉排序树输出完毕。\n");
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
	printf("请输入一个关键字(输入0时结束输入)：\n");
	scanf("%d",&Key);
	while (Key)
	{
		InsertBST(&T,Key);
		printf("请输入下一个关键字(输入0时结束输入)：\n");
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
			printf("已找到\n");
			return;
		}
		p=(Key<p->key) ? p->lchild:p->rchild;
	}
	printf("没有找到\n");
}

void InsertBST(BSTree *T,KeyType Key)
{
	BSTNode *f,*p;
	p=(*T);
	while(p)
	{
		if(p->key==Key)
		{
			printf("树中已有Key不需插入\n");
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
		printf("没有找到要删除的结点\n");
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