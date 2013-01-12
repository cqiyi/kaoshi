/**************
2、建立一个空二叉排序树，输入一串数据（以-9999结尾），输出前序和中序遍历。其中：输入数据均为整数，输入时以空格分开。
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
	cout<<"创建一棵二叉排序树:"<<endl;

}

void InsertBST(BSTree *T, int Key)
{
	BSTNode *f, *p;
	p = *T;
	while(p)
	{
		if(p->key==key)
		{
			cout<<key<<"已经存在，不需重复插入"endl;
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
	cout<<"请输入一个关键字(输入0结束):"<<endl;
	cin>>key;
	while(key)
	{

	}
}