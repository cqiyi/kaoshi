/*
11、数据结构 上机 内排序 程序 全部实现
*/
/*sy6.c*/
#define NULL 0
#define n 10
#define Error printf
#define FALSE 0
#define TRUE 1
/*#include "stdio.h"*/
/*#include <stdlib.h>*/
#include <math.h>
typedef int KeyType;
typedef char InfoType;
typedef struct {
	KeyType key;
	InfoType otherinfo;
} RecType;
typedef RecType Seqlist[n+1];
int m,num; /*全局变量m和num存储输出的第趟结果及递归调用的次数*/
Seqlist R;/*记录待排序的10个数*/
void Insertsort();
int Bubblesort();
void Quicksort(int low,int high);
void Selectsort();
void Heapsort();
void Mergesort();
void Radixsort();
int Partition(int i,int j);
void main() {
	Seqlist S;
	int i;
	char ch1,ch2;
	printf("请输入10个待排序数据:(每个数据间用空格隔开)\n");
	for(i=1; i<=n; i++)
		scanf("%d",&S[i].key);
	ch1='y';
	while (ch1=='y' || ch1=='Y') {
		printf("*****************菜单***********************\n");
		printf("请选择下列*作：\n");
		printf("1------------------更新待排序数据-----------\n");
		printf("2------------------直接插入排序-------------\n");
		printf("3------------------冒泡排序-----------------\n");
		printf("4------------------快速排序-----------------\n");
		printf("5------------------直接选择排序-------------\n");
		printf("6------------------堆排序-------------------\n");
		printf("7------------------归并排序-----------------\n");
		printf("8------------------基数排序-----------------\n");
		printf("9------------------退出---------------------\n");
		printf("请选择*作类别(1-9)：");
		scanf("\n%c",&ch2);
		switch (ch2) {
		case '1':
			printf("请输入更新待排序数据：\n");
			for (i=1; i<=n; i++)
				scanf ("%d",&S[i].key);
			break;
		case '2':
			printf("请输入要输出第几趟结果:");
			scanf("\n%d",&m);
			for (i=1; i<=n; i++)
				R[i].key=S[i].key;
			Insertsort();
			break;
		case '3':
			printf("请输入要输出第几趟结果:");
			scanf("\n%d",&m);
			for (i=1; i<n+1; i++)
				R[i].key=S[i].key;
			Bubblesort();
			break;
		case '4':
			printf("请输入要输出第几趟结果：");
			scanf("\n%d",&m);
			for (i=1; i<n+1; i++)
				R[i].key=S[i].key;
			num=0;
			Quicksort(1,n);
			break;
		case '5':
			printf("请输入要输出第几趟结果：");
			scanf("\n%d",&m);
			for (i=1; i<n+1; i++)
				R[i].key=S[i].key;
			Selectsort();
			break;
		case '6':
			printf("请输入要输出第几趟结果：");
			scanf("\n%d",&m);
			for (i=1; i<n+1; i++)
				R[i].key=S[i].key;
			Heapsort();
			break;
		case '7':
			printf("请输入要输出第几趟结果：");
			scanf("\n%d",&m);
			for (i=1; i<n+1; i++)
				R[i].key=S[i].key;
			Mergesort();
			break;
		case '8':
			printf("请输入要输出第几趟结果：");
			scanf("\n%d",&m);
			for (i=0; i<n; i++)
				R[i].key=S[i+1].key;
			Radixsort();
			break;
		case '9':
			ch1='n';
			break;
		default:
			ch1='n';
		}
	}
}
/*******************************************************************/
void Insertsort() {
	/*对顺序表R中的记录R[1...n]按递增序进行插入排序*/
	int i,j,k;
	for(i=2; i<=n; i++) {
		if(R[i].key<R[i-1].key) {
			R[0]=R[i];
			j=i-1;
			do {
				/*从右向左在有序区R[1...i-1]中查找R[i]的插入位置*/
				R[j+1]=R[j];
				j--;
			} while(R[0].key<R[j].key);
			R[j+1]=R[0];
		}
		if (i-1==m) {
			printf("第%d趟的结果是：",m);
			for(k=1; k<=n; k++)
				printf("%5d",R[k].key);
			printf("\n");
			printf("请输入还要输出第几趟结果，不想输出时请输入0：");
			scanf("\n%d",&m);
		}
	}
	printf("最终排序结果是：");
	for (k=1; k<=n; k++)
		printf("%5d",R[k].key);
	printf("\n");
}
/********************************************************************/
int Bubblesort() {
	/*R[1...n]是待排序的文件，采用自下向上扫描对R做冒泡排序*/
	int i,j,k,m;
	int exchange;
	/* printf("请输入要输出第几趟结果：");
	scanf("\n%d",&m);*/
	for(i=1; i<n; i++) {
		/*最多做n-1趟排序*/
		exchange=FALSE;
		for (j=n-1; j>=i; j--) {
			if (R[j+1].key<R[j].key) {
				R[0]=R[j+1];
				R[j+1]=R[j];
				R[j]=R[0];
				exchange=TRUE;
			}
		}
		if((i==m)||(!exchange)) {
			printf("第%d趟的结果是：",m);
			for (k=1; k<=n; k++)
				printf("%5d",R[k].key);
			printf("\n");
			printf("请输入还要输出第几趟结果，不想输出时请输入0：");
			scanf("\n%d",&m);
		}
		if(!exchange) return(1);
	}
	printf("最终排序结果是：");
	for (k=1; k<=n; k++)
		printf("%5d",R[k].key);
	printf("\n");
	return(1);
}/*Bubblesort*/
/*******************************************************************/
int Partition(int i,int j) {
	/*调用Partition(R,low,high)时，返回在R[low...high]中基准记录的位置*/
	RecType pivot=R[i];
	while (i<j) {
		while(i<j && R[j].key>=pivot.key)
			j--;
		if (i<j)
			R[i++]=R[j];
		while (i<j && R[i].key<=pivot.key)
			i++;
		if (i<j)
			R[j--]=R[i];
	}
	R[i]=pivot;
	return i;
}/*Partition*/
/*******************************************************************/
void Quicksort(int low,int high) {
	/*对R[low...high]的快速排序*/
	int pivotpos,k;
	if (low<high) {
		/*当区间长度大于1时才需排序*/
		pivotpos=Partition(low,high);
		num++;
		if(m==num) {
			printf("第%d趟的结果是：",m);
			for (k=1; k<=n; k++)
				printf("%5d",R[k].key);
			printf("\n");
			printf("请输入还要输出第几趟结果，不想输出时请输入0：");
			scanf("\n%d",&m);
		}
		Quicksort(low,pivotpos-1);
		Quicksort(pivotpos+1,high);
	}
	if(low==1&&high==n) {
		printf("最终排序结果是：");
		for (k=1; k<=n; k++)
			printf("%5d",R[k].key);
		printf("\n");
		/*printf("请输入还要输出第几趟结果，不想输出时请输入0：");*/
		/*scanf("\n%d",&m);*/
	}
}/*Quicksort*/
/********************************************************************/
void Selectsort() {
	int i,j,k,h;
	for (i=1; i<n; i++) {
		h=i;
		for(j=i+1; j<=n; j++) {
			if(R[j].key<R[h].key) h=j;
		}
		if (h!=i) {
			R[0]=R[i];
			R[i]=R[h];
			R[h]=R[0];
		}
		if (i==m) {
			printf("第%d趟的结果是：",m);
			for (k=1; k<=n; k++)
				printf("%5d",R[k].key);
			printf("\n");
			printf("请输入还要输出第几趟结果，不想输出时请输入0：");
			scanf("\n%d",&m);
		}
	}
	printf("最终排序结果是：");
	for (k=1; k<=n; k++)
		printf("%5d",R[k].key);
	printf("\n");
}/*Selectsort*/
/********************************************************************/
void Heapify(int low,int high) {
	int large;
	RecType temp=R[low];
	for (large=2*low; large<=high; large*=2) {
		if (large<high && R[large].key<R[large+1].key)
			large++;
		if (temp.key>=R[large].key)
			break;
		R[low]=R[large];
		low=large;
	}
	R[low]=temp;
}/*Heapify*/
/********************************************************************/
void BuildHeap() {
	/*将初始文件R[1...n]构造为大根堆*/
	int i;
	for (i=n/2; i>0; i--)
		Heapify(i,n);
}
/********************************************************************/
void Heapsort() {
	/*对R[1...n]进行堆排序，用R[0]做暂存单元*/
	int i,k;
	BuildHeap();
	for (i=n; i>1; i--) {
		R[0]=R[1];
		R[1]=R[i];
		R[i]=R[0];
		if (i==(n-m+1)) {
			printf("第%d趟的结果是：",m);
			for (k=1; k<=n; k++)
				printf("%5d",R[k].key);
			printf("\n");
			printf("请输入还要输出第几趟结果，不想输出时请输入0：");
			scanf("\n%d",&m);
		}
		Heapify(1,i-1);
	}
	printf("最终排序结果是：");
	for (k=1; k<=n; k++)
		printf("%5d",R[k].key);
	printf("\n");
}/*Heapsort*/
/********************************************************************/
void Merge (int low,int mm,int high) {
	/*将两个有序序列R[low...mm]和R[mm+1...high]归并成一个有序序列*/
	int i=low,j=mm+1,p=0;
	RecType *R1;
	R1=(RecType * )malloc((high-low+1)* sizeof(RecType));
	if (!R1)
		Error("Insufficient memory available!");
	while (i<=mm && j<=high)
		R1[p++]=(R[i].key<=R[j].key)?R[i++]:R[j++];
	while (i<=mm)
		R1[p++]=R[i++];
	while (j<=high)
		R1[p++]=R[j++];
	for (p=0,i=low; i<=high; p++,i++)
		R[i]=R1[p];
}/*Merge*/
/********************************************************************/
void MergePass(int length) {
	/*对R[1...n]做一趟归并排序*/
	int i;
	for (i=1; i+2*length-1<=n; i=i+2*length)
		Merge(i,i+length-1,i+2*length-1);
	if (i+length-1<n)
		Merge(i,i+length-1,n);
}/*MergePass*/
/********************************************************************/
void Mergesort() {
	int length,k;
	for (length=1; length<n; length*=2) {
		MergePass(length);
		if (m==(int)(log(length))+1) {
			printf("第%d趟的结果是：",m);
			for (k=1; k<=n; k++)
				printf("%5d",R[k].key);
			printf("\n");
			printf("请输入还要输出第几趟结果，不想输出时请输入0：");
			scanf("\n%d",&m);
		}
	}
	printf("最终排序结果是：");
	for (k=1; k<=n; k++)
		printf("%5d",R[k].key);
	printf("\n");
}/*Mergesort*/
/********************************************************************/
#define KeySize 3 /*设关键字位数d=3*/
#define Radix 10 /*基数rd为10*/
typedef struct QNode {
	KeyType key;/*关键字*/
	InfoType otherinfo;/*其他数据项*/
	struct QNode *next;
} QNode,*QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
} LinkQueue;
LinkQueue B[Radix];
int EnQueue(int k,RecType Ri);
int QueueEmpty(int k);
RecType DeQueue(int k);
int InitQueue(int k);
int EnQueue(int k,RecType Ri) {
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p) return(0);
	p->key=Ri.key;
	p->otherinfo=Ri.otherinfo;
	p->next=NULL;
	B[k].rear->next=p;
	B[k].rear=p;
	return(1);
}
int InitQueue(int k) {
	B[k].front=(QueuePtr)malloc(sizeof(QNode));
	if(!B[k].front) return(0);
	B[k].rear=B[k].front;
	B[k].front->next=NULL;
	return(1);
}
int QueueEmpty(int k) {
	if(B[k].front==B[k].rear) return(1);
	else return(0);
}
RecType DeQueue(int k) {
	RecType p;
	QueuePtr t;
	/*if(QueueEmpty(ptrB)) return(NULL);*/
	t=B[k].front->next;
	p.key=t->key;
	p.otherinfo=t->otherinfo;
	B[k].front->next=t->next;
	if(B[k].rear==t)
		B[k].rear=B[k].front;
	free(t);
	return(p);
}
/********************************************************************/
void Distribute(int j) {
	int i,k,t;
	j=KeySize-j;
	for (i=0; i<n; i++) {
		k=R[i].key;
		for (t=1; t<j; t++) k=k/10;
		k=k%10;
		EnQueue(k,R[i]);
	}
}/*Distribute*/
/********************************************************************/
void Collect() {
	int i=0,j;
	for (j=0; j<Radix; j++)
		while (!QueueEmpty(j))
			R[i++]=DeQueue(j);
}/*Collect*/
/********************************************************************/
void Radixsort() {
	/*对R[0...n-1]进行基数排序，R[i].key为非负整数，且位数不超过KeySize*/
	int i,k;
	for (i=0; i<Radix; i++)
		InitQueue(i);
	for (i=KeySize-1; i>=0; i--) {
		Distribute(i);
		Collect(B);
		if ((KeySize-i)==m) {
			printf("第%d趟的结果是：",m);
			for(k=0; k<n; k++)
				printf("%5d",R[k].key);
			printf("\n");
			printf("请输入还要输出第几趟结果，不想输出时请输入0：");
			scanf("\n%d",&m);
		}
	}
	printf("最终排序结果是：");
	for (k=0; k<n; k++)
		printf("%5d",R[k].key);
	printf("\n");
}/*Radixsort*/
