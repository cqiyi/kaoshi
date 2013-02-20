/*
9．  编一C程序，它能根据输入的完全二*树层次序列来构造该完全二*树，并能输出该完全二*树的后序序列和叶结点的个数。（完全二*树层次序列是从1层到最高层、同层内从左到右的次序排列的结点序列）。

（注：程序的可执行文件名必须是 e1.exe，存于你的账号或其debug目录下。）
*/
#include<stdio.h>
#include<malloc.h>
#include<string.h>
void exit(int);
#define MAX 100
typedef struct node
{
	char d;
	struct node *lchild,*rchild;
} Tnode;

void MK(char in[],char is,char ie,char pre[],char pres,char pree,Tnode *r)
{
	int i;
	if(is>ie||pres>pree)
		*r=NULL;
	else
	{
		r=(Tnode*)malloc(sizeof(Tnode));
		r->d=pre[pres];
		for(i=is; i<=ie; i++)
		{
			if(in[i]==pre[pres])
			{
				MK(in,is,i-1,pre,pres+1,pres+i-is,r->lchild);
				MK(in,i+1,ie,pre,pres+i-is+1,pree,r->rchild);
				break;
			}
			if(i>ie)
			{
				printf("输入错误!\n");
				exit(1);
			}
		}
	}
}
void postorder(Tnode *r)
{
	if(r)
	{
		postorder(r->lchild);
		postorder(r->rchild);
		printf("%c",r->d);
	}
}
int leaf(Tnode *r)
{
	if(r==NULL)
		return 0;
	else if(r->lchild==NULL&&r->rchild==NULL)
		return 1;
	else
		return leaf(r->lchild)+leaf(r->rchild);
}
int height(Tnode *r)
{
	int h1,h2;
	if(r==NULL)
		return 0;
	else
	{
		h1=height(r->lchild);
		h2=height(r->rchild);
		return 1+(h1>h2?h1:h2);
	}
}
void main()
{
	Tnode *r=NULL;
	char in[MAX],pre[MAX];
	printf("请输入前序序列:\n");
	gets(pre);
	printf("请输入中序序列:\n");
	gets(in);
	MK(in,0,strlen(in)-1,pre,0,strlen(pre)-1,r);
	printf("\n后序遍历序列为:\n");
	postorder(r);
	printf("\n叶结点的个数为:%d\n",leaf(r));
	printf("\n高度为:%d\n",height(r));
}



