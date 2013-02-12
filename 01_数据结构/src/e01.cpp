/*
6. 编一C程序，它能读入一串整数（不多于2000，并以-9999为结束标记）及另一整数n，判断n是否在那一串数中，若是，则输出yes及该数在那串整数中的序号（序号从0开始），否则输出no。(输入整数时，相邻的两个用空格隔开)。
（注：程序的可执行文件名必须是 e6.exe）
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
