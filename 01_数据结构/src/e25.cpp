/*
	ʵ��5������һ�ö���������ǰ���������룬�Էǿո��ַ���ʾ����ֵ��
	�Կո��ַ���ʾ��ָ�룻ʵ�ָö�������ǰ���������������ͺ��������
*/
#include<stdio.h>
#include<stdlib.h>

#define OK 1;

typedef char TElemType;
typedef int Status;
//�������Ĵ洢��ʾ��ʽ
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild,*rchild;//���Һ���ָ��
} BiTNode,*BiTree;

//������������ʹ��ǰ��������������,�ո��ʾ����


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
		T->data = ch;					//���ɸ��ڵ�
		CreateBiTree(T->lchild);			//����������
		CreateBiTree(T->rchild);		//����������
	}
	return OK;
}

//ǰ�����
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
//�������
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
//�������
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


//������
void main()
{
	BiTree T;
	printf("�밴����������������Ķ��������ո��ʾ����\n");
	CreateBiTree(T);
	printf("ǰ��������£�\n");
	PreOrderTraverse(T);
	printf("\n");
	printf("����������£�\n");
	InOrderTraverse(T);
	printf("\n");
	printf("����������£�\n");
	PostOrderTraverse(T);
	printf("\n");
}