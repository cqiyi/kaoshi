/**************
2������һ���ն���������������һ�����ݣ���-9999��β�������ǰ���������������У��������ݾ�Ϊ����������ʱ�Կո�ֿ���
**********/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node *lchild, *rchild;
} BSTNode;

typedef BSTNode *BSTree;

main()
{
	BSTree T;
	cout<<"����һ�ö���������:"<<endl;

}

void InsertBST(BSTree *T, int Key)
{
	BSTNode *f, *p;
	p = *T;
	while(p)
	{
		if(p->key==key)
		{
			cout<<key<<"�Ѿ����ڣ������ظ�����"endl;
			return;
		}
		f=p;
		p=key<p->key ? p->lchild : p->rchild;
	}
	p = (BSTNode*) malloc(sizeof(BSTNode));
	p->key = Key;
	p->lchild = p->rchild = NULL;
	if(*T==NULL) *T=p;
	else if (Key<f->key) f->lchild = p;
	else f->rchild =p;
}

BSTree CreateBST()
{
	BSTree T = NULL;
	int key;
	cout<<"������һ���ؼ���(����0����):"<<endl;
	cin>>key;
	while(key)
	{

	}
}