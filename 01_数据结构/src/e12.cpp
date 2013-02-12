#define StackSize 10 /*假定预分配的栈空间最多为10*/
#define Error printf
typedef int DataType; /*栈的元素类型设为整型*/
typedef struct {
	DataType data[StackSize];
	int top;
} SeqStack;
void InitStack(SeqStack *S) { /*初始栈*/
	S->top=0;
}
int StackEmpty(SeqStack *S) { /*判栈空*/
	if (S->top==0) return 1;
	else return 0;
}
int StackFull(SeqStack *S) { /*判栈满*/
	return S->top==StackSize;
}
void Push(SeqStack *S, DataType x) { /*进栈*/
	if(StackFull(S))
		Error("Stack overflow"); /*上溢退出*/
	else S->data[(S->top)++]=x; /*栈顶指针加1后将x进栈*/
}
DataType Pop(SeqStack *S) { /*出栈*/
	if (StackEmpty(S))
		Error("Stack underflow"); /*下溢退出*/
	else return S->data[--(S->top)]; /*栈顶指针返回后将栈顶指针减1*/
}
/* DataType StackTop(SeqStack *S) //取栈顶元素
{if (StackEmpty(S))
Error("Stack is empty");
Return S->data[S->top];
} */
void conversion(int N,int B);
main() {
	int N,B;
	char ch;
	printf("进行转换请输入Y,退出请输入N:");
	scanf("\n%c",&ch);
	while (ch=='Y'|| ch=='y') {
		printf("请输入需要转换的十进制数：");
		scanf("%d",&N);
		printf("\n请输入想要转换的进制数：");
		scanf("%d",&B);
		conversion(N,B);
		printf("继续转换请输入Y,退出请输入N");
		scanf("\n%c",&ch);
	}
}
void conversion(int N,int B) { /*将十进制的N转换成B进制数*/
	DataType i;
	SeqStack *S;
	InitStack(S);
	while (N) { /*从低位向高位生成B进制数的各位数字，并将其进栈*/
		Push(S,N%B);
		N=N/B;
	}
	printf("转换的结果为:");
	while (!StackEmpty(S)) { /*栈非空时退栈输出*/
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