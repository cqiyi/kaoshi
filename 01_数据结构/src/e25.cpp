/*
	实验5：建立一棵二叉树，以前序序列输入，以非空格字符表示结点的值，
	以空格字符表示空指针；实现该二叉树的前序遍历、中序遍历和后序遍历。
*/
#include<stdio.h>
#include<stdlib.h>

#define OK 1;

typedef char TElemType;
typedef int Status;
//二叉树的存储表示方式
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

//创建二叉树，使用前序序列输入数据,空格表示空树


Status CreateBiTree(BiTree &T)
{
	char ch ;
	scanf("%c",&ch);
	getchar();
	if(ch == ' ')
		T = NULL;
	else
	{
		if(!(T = (BiTNode *)malloc(sizeof(BiTNode))))
			exit(0);
		T->data = ch;					//生成根节点
		CreateBiTree(T->lchild);			//构造左子树
		CreateBiTree(T->rchild);		//构造右子树
	}
	return OK;
}

//前序遍历
Status PreOrderTraverse(BiTree T)
{
	if(T)
	{
		printf("%c",T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	return OK;
}
//中序遍历
Status InOrderTraverse(BiTree T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		printf("%c",T->data);
		InOrderTraverse(T->rchild);
	}
	return OK;
}
//后序遍历
Status PostOrderTraverse(BiTree T)
{
	if(T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c",T->data);
	}
	return OK;
}


//主函数
void main()
{
	BiTree T;
	printf("请按照先序序列输入你的二叉树，空格表示空树\n");
	CreateBiTree(T);
	printf("前序遍历如下：\n");
	PreOrderTraverse(T);
	printf("\n");
	printf("中序遍历如下：\n");
	InOrderTraverse(T);
	printf("\n");
	printf("后序遍历如下：\n");
	PostOrderTraverse(T);
	printf("\n");
}