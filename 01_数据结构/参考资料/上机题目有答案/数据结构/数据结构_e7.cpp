/*****************************************************\
7��  ��һC�������ܸ����������ȫ����������������������ȫ�������������������ȫ�������ĺ������к�Ҷ���ĸ���������ȫ��������������Ǵ�1�㵽��߲㡢ͬ���ڴ����ҵĴ������еĽ�����У���
\*****************************************************/
#include "iostream.h"
#include "string.h"
#define MAX 1000
char CNodeList[MAX]={0} ;
int length = 0;		//�ڵ����
int count = 0;		//Ҷ����Ŀ��2��
struct STreeNode{
	STreeNode(){node = 0;lChild = NULL;rChild = NULL; }
	char node;
	STreeNode *lChild;	// ������ 
	STreeNode *rChild;	// ������
};
void MakeTree(STreeNode &p,int i)
{
	if( i< length)
	{
		p.node =  CNodeList[i];
		p.lChild = NULL;
		p.rChild = NULL;
		if(i*2+1<length)
		{
			STreeNode *r = new STreeNode();
			p.rChild = r;			
			MakeTree(*(p.rChild),i*2+1);
		}
		if(i*2+2 < length)
		{
			STreeNode *l = new STreeNode();
			p.lChild = l;
			MakeTree(*(p.lChild),i*2+2);
		}
	}
}
void ShowTree(STreeNode *p)
{
	if(p)
	{
		ShowTree(p->rChild);
		ShowTree(p->lChild);
		cout<<p->node;
	}
	else
	{
		count++;
	}
}
void main()
{
	cout<<"Please enter the tree node list"<<endl;
	cin>> CNodeList;
	STreeNode Head ;
	STreeNode *p = NULL;
	length = strlen(CNodeList);
	MakeTree(Head,0);
	ShowTree(&Head);
	cout<<endl;
	cout<<"Ҷ�ڵ����Ϊ "<<count/2<<endl;
}
