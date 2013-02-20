#include <stdio.h>

#define StackSize 10 /*�ٶ�Ԥ�����ջ�ռ����Ϊ10*/
#define Error printf
typedef int DataType; /*ջ��Ԫ��������Ϊ����*/
typedef struct {
	DataType data[StackSize];
	int top;
} SeqStack;
void InitStack(SeqStack *S) { /*��ʼջ*/
	S->top=0;
}
int StackEmpty(SeqStack *S) { /*��ջ��*/
	if (S->top==0) return 1;
	else return 0;
}
int StackFull(SeqStack *S) { /*��ջ��*/
	return S->top==StackSize;
}
void Push(SeqStack *S, DataType x) { /*��ջ*/
	if(StackFull(S))
		Error("Stack overflow"); /*�����˳�*/
	else S->data[(S->top)++]=x; /*ջ��ָ���1��x��ջ*/
}
DataType Pop(SeqStack *S) { /*��ջ*/
	if (StackEmpty(S))
		Error("Stack underflow"); /*�����˳�*/
	else return S->data[--(S->top)]; /*ջ��ָ�뷵�غ�ջ��ָ���1*/
}
/* DataType StackTop(SeqStack *S) //ȡջ��Ԫ��
{if (StackEmpty(S))
Error("Stack is empty");
Return S->data[S->top];
} */
void conversion(int N,int B);
void main() {
	int N,B;
	char ch;
	printf("����ת��������Y,�˳�������N:");
	scanf("\n%c",&ch);
	while (ch=='Y'|| ch=='y') {
		printf("��������Ҫת����ʮ��������");
		scanf("%d",&N);
		printf("\n��������Ҫת���Ľ�������");
		scanf("%d",&B);
		conversion(N,B);
		printf("����ת��������Y,�˳�������N");
		scanf("\n%c",&ch);
	}
}
void conversion(int N,int B) { /*��ʮ���Ƶ�Nת����B������*/
	DataType i;
	SeqStack *S;
	InitStack(S);
	while (N) { /*�ӵ�λ���λ����B�������ĸ�λ���֣��������ջ*/
		Push(S,N%B);
		N=N/B;
	}
	printf("ת���Ľ��Ϊ:");
	while (!StackEmpty(S)) { /*ջ�ǿ�ʱ��ջ���*/
		i=Pop(S);
		switch(i) {
		case 10:
			printf("%c",'a');
			break;
		case 11:
			printf("%c",'b');
			break;
		case 12:
			printf("%c",'c');
			break;
		case 13:
			printf("%c",'d');
			break;
		case 14:
			printf("%c",'e');
			break;
		case 15:
			printf("%c",'f');
			break;
		default:
			printf("%d",i);
		}
	}
	printf("\n");
}