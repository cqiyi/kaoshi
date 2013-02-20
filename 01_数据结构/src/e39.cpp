/*
���ݽṹ������������Ӧ��
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	unsigned int weight;		//Ȩֵ
	unsigned int parent , lchild , rchild;		//���ڵ㣬��������������
}HTNode, *HuffmanTree;			//��̬��������洢�շ�����

typedef char ** HuffmanCode;	//��̬��������洢�շ��������

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
	//w���n���ַ���Ȩֵ������շ�����HT�������n���ַ��ĺշ�������HC
	int m;//m��ʾ�շ������ܹ����
	int i;
	int s1=0;
	int s2=0;
	HuffmanTree p;
	char *cd;
	unsigned int start,c,f;
	if(n<=1)
		return;
	m = 2*n -1 ;	//�ڵ���
	HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));	//����洢�ռ䣬0�ŵ�Ԫδ��
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

	for(i=n+1;i<=m;++i){		//���շ�����
		//��HT[1...i-1]ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊ��s1��s2
		Select(HT,i-1,s1,s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	for(i=1;i<=m;i++)
		printf("%d,%d,%d,%d\n",HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
	//��Ҷ�ӵ���������ÿ���ַ��ĺշ�������
	HC = (HuffmanCode)malloc((n+1)*sizeof(char *));	//����n���ַ������ͷָ������
	cd = (char *)malloc(n*sizeof(char));			//���������Ĺ����ռ�
	cd[n-1] ='\0';									//���������
	for(i=1;i<=n;++i){
		start = n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)		//��Ҷ�ӵ������������
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
	printf("��������ĺշ�������Ҷ�ӽ�������\n\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("����� %d �����ֵ�Ȩ��",i);
		scanf("%d",&NT[i]);
	}
	HuffmanCoding(HT,HC,NT,n);
	printf("�շ�������������:\n\n");
	for(i=1;i<=n;i++)
	{
		printf("%d :%s\n",HT[i].weight,HC[i]);
	}
	printf("\n\n");
}