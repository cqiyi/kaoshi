/*
6．编一C程序，它能读入一串（n个）整数（以-9999为结束标记），并判断第1个整数在后(n-1)个整数中出现的次数，再输出该次数。（输入时，两个相邻的整数用空格隔开)。

（注：程序的可执行文件名必须是 e2.exe，存于你的账号或其debug目录下。）
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


	//释放链表
	p = head;
	for(i=0; p!=NULL; i++)
	{
		t = p->next;
		free(p);
		printf("free %d\n", i);
		p = t;
	}
}
