/*
6����һC�������ܶ���һ����n������������-9999Ϊ������ǣ������жϵ�1�������ں�(n-1)�������г��ֵĴ�����������ô�����������ʱ���������ڵ������ÿո����)��

��ע������Ŀ�ִ���ļ��������� e2.exe����������˺Ż���debugĿ¼�¡���
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} ListNode;


void main()
{
	ListNode *head, *p, *t;
	int i, d, n;

	head = (ListNode*)malloc(sizeof(ListNode));
	head->data = 0;
	p = head;
	printf("input data\n");
	while(true)
	{
		scanf("%d", &d);
		if(d == -9999) break;

		t = (ListNode*)malloc(sizeof(ListNode));
		t->data = d;
		t->next = NULL;
		p->next = t;
		head->data++;
		p = t;
	}

	t = head->next;
	d = t->data;
	n= 0;
	while(t->next)
	{
		t = t->next;
		if(t->data == d) n++;
	}
	printf("%d count is %d\n\n", d, n);


	//�ͷ�����
	p = head;
	for(i=0; p!=NULL; i++)
	{
		t = p->next;
		free(p);
		printf("free %d\n", i);
		p = t;
	}
}
