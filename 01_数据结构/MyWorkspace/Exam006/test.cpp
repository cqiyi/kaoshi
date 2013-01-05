/****************************************
11�����ݽṹ?�ϻ�?������?����?ȫ��ʵ��
 
****************************************/
#include<stdio.h>

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
typedef struct{ 
KeyType key; 
InfoType otherinfo; 
}RecType; 
typedef RecType Seqlist[n+1]; 
int m,num; /*ȫ�ֱ���m��num�洢����ĵ��˽�����ݹ���õĴ���*/ 
Seqlist R;/*��¼�������10����*/ 
void Insertsort(); 
int Bubblesort(); 
void Quicksort(int low,int high); 
void Selectsort(); 
void Heapsort(); 
void Mergesort(); 
void Radixsort(); 
int Partition(int i,int j); 
void main() 
{Seqlist S; 
int i; 
char ch1,ch2; 
printf("������10������������:(ÿ�����ݼ��ÿո����)\n"); 
for(i=1;i<=n;i++) 
scanf("%d",&S[i].key); 
ch1='y'; 
while (ch1=='y' || ch1=='Y') 
{ 
printf("*****************�˵�***********************\n"); 
printf("��ѡ������*����\n"); 
printf("1------------------���´���������-----------\n"); 
printf("2------------------ֱ�Ӳ�������-------------\n"); 
printf("3------------------ð������-----------------\n"); 
printf("4------------------��������-----------------\n"); 
printf("5------------------ֱ��ѡ������-------------\n"); 
printf("6------------------������-------------------\n"); 
printf("7------------------�鲢����-----------------\n"); 
printf("8------------------��������-----------------\n"); 
printf("9------------------�˳�---------------------\n"); 
printf("��ѡ��*�����(1-9)��"); 
scanf("\n%c",&ch2); 
switch (ch2) 
{ 
case '1': 
printf("��������´��������ݣ�\n"); 
for (i=1;i<=n;i++) 
scanf ("%d",&S[i].key); 
break; 
case '2':printf("������Ҫ����ڼ��˽��:"); 
scanf("\n%d",&m); 
for (i=1;i<=n;i++) 
R[i].key=S[i].key; 
Insertsort(); 
break; 
case '3': printf("������Ҫ����ڼ��˽��:"); 
scanf("\n%d",&m); 
for (i=1;i<n+1;i++) 
R[i].key=S[i].key; 
Bubblesort(); 
break; 
case '4':printf("������Ҫ����ڼ��˽����"); 
scanf("\n%d",&m); 
for (i=1;i<n+1;i++) 
R[i].key=S[i].key; 
num=0;Quicksort(1,n); 
break; 
case '5':printf("������Ҫ����ڼ��˽����"); 
scanf("\n%d",&m); 
for (i=1;i<n+1;i++) 
R[i].key=S[i].key; 
Selectsort(); 
break; 
case '6':printf("������Ҫ����ڼ��˽����"); 
scanf("\n%d",&m); 
for (i=1;i<n+1;i++) 
R[i].key=S[i].key; 
Heapsort(); 
break; 
case '7':printf("������Ҫ����ڼ��˽����"); 
scanf("\n%d",&m); 
for (i=1;i<n+1;i++) 
R[i].key=S[i].key; 
Mergesort(); 
break; 
case '8':printf("������Ҫ����ڼ��˽����"); 
scanf("\n%d",&m); 
for (i=0;i<n;i++) 
R[i].key=S[i+1].key; 
Radixsort(); 
break; 
case '9':ch1='n';break; 
default:ch1='n'; 
} 
} 
} 
/*******************************************************************/ 
void Insertsort() 
{/*��˳���R�еļ�¼R[1...n]����������в�������*/ 
int i,j,k; 
for(i=2;i<=n;i++) 
{ 
if(R[i].key<R[i-1].key) 
{ 
R[0]=R[i]; j=i-1; 
do 
{/*����������������R[1...i-1]�в���R[i]�Ĳ���λ��*/ 
R[j+1]=R[j]; 
j--; 
} 
while(R[0].key<R[j].key); 
R[j+1]=R[0]; 
} 
if (i-1==m) 
{ 
printf("��%d�˵Ľ���ǣ�",m); 
for(k=1;k<=n;k++) 
printf("%5d",R[k].key); 
printf("\n"); 
printf("�����뻹Ҫ����ڼ��˽�����������ʱ������0��"); 
scanf("\n%d",&m); 
} 
} 
printf("�����������ǣ�"); 
for (k=1;k<=n;k++) 
printf("%5d",R[k].key); 
printf("\n"); 
} 
/********************************************************************/ 
int Bubblesort() 
{/*R[1...n]�Ǵ�������ļ���������������ɨ���R��ð������*/ 
int i,j,k,m; 
int exchange; 
/* printf("������Ҫ����ڼ��˽����"); 
scanf("\n%d",&m);*/ 
for(i=1;i<n;i++) 
{/*�����n-1������*/ 
exchange=FALSE; 
for (j=n-1;j>=i;j--) 
{ 
if (R[j+1].key<R[j].key) 
{ 
R[0]=R[j+1]; 
R[j+1]=R[j]; 
R[j]=R[0]; 
exchange=TRUE; 
} 
} 
if((i==m)||(!exchange)) 
{ 
printf("��%d�˵Ľ���ǣ�",m); 
for (k=1;k<=n;k++) 
printf("%5d",R[k].key); 
printf("\n"); 
printf("�����뻹Ҫ����ڼ��˽�����������ʱ������0��"); 
scanf("\n%d",&m); 
} 
if(!exchange) return(1); 
} 
printf("�����������ǣ�"); 
for (k=1;k<=n;k++) 
printf("%5d",R[k].key); 
printf("\n"); 
return(1); 
}/*Bubblesort*/ 
/*******************************************************************/ 
int Partition(int i,int j) 
{/*����Partition(R,low,high)ʱ��������R[low...high]�л�׼��¼��λ��*/ 
RecType pivot=R[i]; 
while (i<j) 
{while(i<j && R[j].key>=pivot.key) 
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
void Quicksort(int low,int high) 
{/*��R[low...high]�Ŀ�������*/ 
int pivotpos,k; 
if (low<high) 
{/*�����䳤�ȴ���1ʱ��������*/ 
pivotpos=Partition(low,high); 
num++; 
if(m==num) 
{ 
printf("��%d�˵Ľ���ǣ�",m); 
for (k=1;k<=n;k++) 
printf("%5d",R[k].key); 
printf("\n"); 
printf("�����뻹Ҫ����ڼ��˽�����������ʱ������0��"); 
scanf("\n%d",&m); 
} 
Quicksort(low,pivotpos-1); 
Quicksort(pivotpos+1,high); 
} 
if(low==1&&high==n) 
{ 
printf("�����������ǣ�"); 
for (k=1;k<=n;k++) 
printf("%5d",R[k].key); 
printf("\n"); 
/*printf("�����뻹Ҫ����ڼ��˽�����������ʱ������0��");*/ 
/*scanf("\n%d",&m);*/ 
} 
}/*Quicksort*/ 
/********************************************************************/ 
void Selectsort() 
{ 
int i,j,k,h; 
for (i=1;i<n;i++) 
{ 
h=i; 
for(j=i+1;j<=n;j++) 
{ 
if(R[j].key<R[h].key) h=j; 
} 
if (h!=i) 
{ 
R[0]=R[i];R[i]=R[h];R[h]=R[0]; 
} 
if (i==m) 
{ 
printf("��%d�˵Ľ���ǣ�",m); 
for (k=1;k<=n;k++) 
printf("%5d",R[k].key); 
printf("\n"); 
printf("�����뻹Ҫ����ڼ��˽�����������ʱ������0��"); 
scanf("\n%d",&m); 
} 
} 
printf("�����������ǣ�"); 
for (k=1;k<=n;k++) 
printf("%5d",R[k].key); 
printf("\n"); 
}/*Selectsort*/ 
/********************************************************************/ 
void Heapify(int low,int high) 
{int large; 
RecType temp=R[low]; 
for (large=2*low;large<=high;large*=2) 
{if (large<high && R[large].key<R[large+1].key) 
large++; 
if (temp.key>=R[large].key) 
break; 
R[low]=R[large];low=large; 
} 
R[low]=temp; 
}/*Heapify*/ 
/********************************************************************/ 
void BuildHeap() 
{/*����ʼ�ļ�R[1...n]����Ϊ�����*/ 
int i; 
for (i=n/2;i>0;i--) 
Heapify(i,n); 
} 
/********************************************************************/ 
void Heapsort() 
{/*��R[1...n]���ж�������R[0]���ݴ浥Ԫ*/ 
int i,k; 
BuildHeap(); 
for (i=n;i>1;i--) 
{R[0]=R[1];R[1]=R[i];R[i]=R[0]; 
if (i==(n-m+1)) 
{printf("��%d�˵Ľ���ǣ�",m); 
for (k=1;k<=n;k++) 
printf("%5d",R[k].key);printf("\n"); 
printf("�����뻹Ҫ����ڼ��˽�����������ʱ������0��"); 
scanf("\n%d",&m); 
} 
Heapify(1,i-1); 
} 
printf("�����������ǣ�"); 
for (k=1;k<=n;k++) 
printf("%5d",R[k].key); 
printf("\n"); 
}/*Heapsort*/ 
/********************************************************************/ 
void Merge (int low,int mm,int high) 
{/*��������������R[low...mm]��R[mm+1...high]�鲢��һ����������*/ 
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
for (p=0,i=low;i<=high;p++,i++) 
R[i]=R1[p]; 
}/*Merge*/ 
/********************************************************************/ 
void MergePass(int length) 
{/*��R[1...n]��һ�˹鲢����*/ 
int i; 
for (i=1;i+2*length-1<=n;i=i+2*length) 
Merge(i,i+length-1,i+2*length-1); 
if (i+length-1<n) 
Merge(i,i+length-1,n); 
}/*MergePass*/ 
/********************************************************************/ 
void Mergesort() 
{int length,k; 
for (length=1;length<n;length*=2) 
{MergePass(length); 
if (m==(int)(log(length))+1) 
{ printf("��%d�˵Ľ���ǣ�",m); 
for (k=1;k<=n;k++) 
printf("%5d",R[k].key); 
printf("\n"); 
printf("�����뻹Ҫ����ڼ��˽�����������ʱ������0��"); 
scanf("\n%d",&m); 
} 
} 
printf("�����������ǣ�"); 
for (k=1;k<=n;k++) 
printf("%5d",R[k].key); 
printf("\n"); 
}/*Mergesort*/ 
/********************************************************************/ 
#define KeySize 3 /*��ؼ���λ��d=3*/ 
#define Radix 10 /*����rdΪ10*/ 
typedef struct QNode{ 
KeyType key;/*�ؼ���*/ 
InfoType otherinfo;/*����������*/ 
struct QNode *next; 
}QNode,*QueuePtr; 
typedef struct { 
QueuePtr front; 
QueuePtr rear; 
}LinkQueue; 
LinkQueue B[Radix]; 
int EnQueue(int k,RecType Ri); 
int QueueEmpty(int k); 
RecType DeQueue(int k); 
int InitQueue(int k); 
int EnQueue(int k,RecType Ri) 
{ 
QueuePtr p; 
p=(QueuePtr)malloc(sizeof(QNode)); 
if(!p) return(0); 
p->key=Ri.key;p->otherinfo=Ri.otherinfo; 
p->next=NULL;B[k].rear->next=p; 
B[k].rear=p;return(1); 
} 
int InitQueue(int k) 
{ 
B[k].front=(QueuePtr)malloc(sizeof(QNode)); 
if(!B[k].front) return(0); 
B[k].rear=B[k].front; 
B[k].front->next=NULL; 
return(1); 
} 
int QueueEmpty(int k) 
{ 
if(B[k].front==B[k].rear) return(1); 
else return(0); 
} 
RecType DeQueue(int k) 
{ 
RecType p; 
QueuePtr t; 
/*if(QueueEmpty(ptrB)) return(NULL);*/ 
t=B[k].front->next; 
p.key=t->key;p.otherinfo=t->otherinfo; 
B[k].front->next=t->next; 
if(B[k].rear==t) 
B[k].rear=B[k].front; 
free(t); 
return(p); 
} 
/********************************************************************/ 
void Distribute(int j) 
{int i,k,t; 
j=KeySize-j; 
for (i=0;i<n;i++) 
{k=R[i].key; 
for (t=1;t<j;t++) k=k/10; 
k=k%10; 
EnQueue(k,R[i]); 
} 
}/*Distribute*/ 
/********************************************************************/ 
void Collect() 
{int i=0,j; 
for (j=0;j<Radix;j++) 
while (!QueueEmpty(j)) 
R[i++]=DeQueue(j); 
}/*Collect*/ 
/********************************************************************/ 
void Radixsort() 
{/*��R[0...n-1]���л�������R[i].keyΪ�Ǹ���������λ��������KeySize*/ 
int i,k; 
for (i=0;i<Radix;i++) 
InitQueue(i); 
for (i=KeySize-1;i>=0;i--) 
{ Distribute(i); 
Collect(B); 
if ((KeySize-i)==m) 
{ 
printf("��%d�˵Ľ���ǣ�",m); 
for(k=0;k<n;k++) 
printf("%5d",R[k].key); 
printf("\n"); 
printf("�����뻹Ҫ����ڼ��˽�����������ʱ������0��"); 
scanf("\n%d",&m); 
} 
} 
printf("�����������ǣ�"); 
for (k=0;k<n;k++) 
printf("%5d",R[k].key); 
printf("\n"); 
}/*Radixsort*/
