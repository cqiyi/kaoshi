/*
6. ��һC�������ܶ���һ��������������2000������-9999Ϊ������ǣ�����һ����n���ж�n�Ƿ�����һ�����У����ǣ������yes���������Ǵ������е���ţ���Ŵ�0��ʼ�����������no��(��������ʱ�����ڵ������ÿո����)��
��ע������Ŀ�ִ���ļ��������� e6.exe��
*/
/*
#include <stdio.h>

typedef struct
{
	int data[2000];
	int length;
} SeqList;

void main()
{
	int i,num;
	SeqList a;
	printf("input data\n");
	for(i=0; i<2000; i++)
	{
		scanf("%d",&a.data[i]);
		if(a.data[i]==-9999)
			break;
	}
	a.length=i-1;
	
	printf("input the number\n");
	scanf("%d",&num);
	for(i=0; i<=a.length; i++)
	{
		if(a.data[i]==num)
		{
			printf("\nyes\n");
			printf(" is at %d\n",i);
			return;
			
		}
	}
	printf("\nno\n");
}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}ListNode;


void main(){
	ListNode *head, *p, *t;
	int i, n;

	head = (ListNode*)malloc(sizeof(ListNode));
	head->data = 0;
	p = head;
	printf("input data\n");
	for(i=0; true; i++){
		t = (ListNode*)malloc(sizeof(ListNode));
		scanf("%d", &t->data);
		if(t->data == -9999) {
			free(t);
			break;
		}
		t->next = NULL;
		p->next = t;
		head->data++;
		p = t;
	}

	printf("input the number\n");
	scanf("%d", &n);
	p = head->next;
	for(i=0; i<head->data; i++){
		printf("%d ", p->data);
		if(p->data== n){
			printf("\n YES.\n is at %d\n", i);
			return;
		}
		p = p->next;
	}
	printf("\nNO.\n");
}
