/*
9��  ��һC�������ܸ����������ȫ��*������������������ȫ��*���������������ȫ��*���ĺ������к�Ҷ���ĸ���������ȫ��*����������Ǵ�1�㵽��߲㡢ͬ���ڴ����ҵĴ������еĽ�����У���

��ע������Ŀ�ִ���ļ��������� e1.exe����������˺Ż���debugĿ¼�¡���
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
				printf("�������!\n");
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
	printf("������ǰ������:\n");
	gets(pre);
	printf("��������������:\n");
	gets(in);
	MK(in,0,strlen(in)-1,pre,0,strlen(pre)-1,r);
	printf("\n�����������Ϊ:\n");
	postorder(r);
	printf("\nҶ���ĸ���Ϊ:%d\n",leaf(r));
	printf("\n�߶�Ϊ:%d\n",height(r));
}



