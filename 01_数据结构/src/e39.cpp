/*
数据结构：哈夫曼树的应用
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	unsigned int weight;		//权值
	unsigned int parent , lchild , rchild;		//父节点，左子树，右子树
}HTNode, *HuffmanTree;			//动态分配数组存储赫夫曼树

typedef char ** HuffmanCode;	//动态分配数组存储赫夫曼编码表

unsigned int min1,min2;

void Select(HuffmanTree &HT,int i,int &s1,int &s2)
{
	min1=min2=32767;
	s1=s2=0;
	int j;
	for(j=1;j<=i;j++)
	{
		if(HT[j].weight<min1&&!HT[j].parent)
		{
			min2=min1;
			s2=s1;
			min1=HT[j].weight;
			s1=j;
		}
		else if(HT[j].weight<min2&&!HT[j].parent)
		{
			min2=HT[j].weight;
			s2=j;
		}
	}
}
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n){
	//w存放n个字符的权值，构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC
	int m;//m表示赫夫曼树总共结点
	int i;
	int s1=0;
	int s2=0;
	HuffmanTree p;
	char *cd;
	unsigned int start,c,f;
	if(n<=1)
		return;
	m = 2*n -1 ;	//节点数
	HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));	//分配存储空间，0号单元未用
	for(p = HT+1,i=1;i<=n;++i,++p){
		p->weight = w[i];
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	for(i=n+1;i<=m;++i,++p){
		p->weight = 0;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
		
	for(i=n+1;i<=m;++i){		//建赫夫曼树
		//在HT[1...i-1]选择parent为0且weight最小的两个结点，其序号分别为是s1和s2
		Select(HT,i-1,s1,s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	for(i=1;i<=m;i++)
		printf("%d,%d,%d,%d\n",HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
	//从叶子到根逆向求每个字符的赫夫曼编码
	HC = (HuffmanCode)malloc((n+1)*sizeof(char *));	//分配n个字符编码的头指针向量
	cd = (char *)malloc(n*sizeof(char));			//分配求编码的工作空间
	cd[n-1] ='\0';									//编码结束符
	for(i=1;i<=n;++i){
		start = n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)		//从叶子到根逆向求编码
			if(HT[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		HC[i] = (char *)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);		//
	}
	free(cd);
}
void main(){
	int n;
	int NT[100];
	int i;
	HuffmanTree HT;
	HuffmanCode HC;
	printf("请输入你的赫夫曼树的叶子结点个数：\n\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("输入第 %d 个数字的权重",i);
		scanf("%d",&NT[i]);
	}
	HuffmanCoding(HT,HC,NT,n);
	printf("赫夫曼树编码如下:\n\n");
	for(i=1;i<=n;i++)
	{
		printf("%d :%s\n",HT[i].weight,HC[i]);
	}
	printf("\n\n");
}