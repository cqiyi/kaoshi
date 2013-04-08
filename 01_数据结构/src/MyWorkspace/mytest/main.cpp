#include <stdlib.h>
#include <stdio.h>

typedef char string[255];
#define TRUE 1;
#define FALSE 0;


int main(){
	string *stack, str;
	char* code = "0123456789ABCDEF";
	gets(str);
	printf("OUTPUT:%s,%c,%c\n", str, code[11], code[5]);

	bool i = FALSE;
	printf("\n%d\n", i);

	//int top = 0;
	//stack = (string*)malloc(100*sizeof(string));

	//for(int i=0; i<100; i++){
	//	gets_s(stack[top++]);	
	//	if(stack[top-1][0] == '\0') break;
	//}
	//printf("输入完毕\n");

	//for(int i=0; i<100 && top>0; i++){		
	//	printf("%s\n", stack[--top]);
	//}

	//int data[5][5];
	//for(int i=0; i<5; i++){
	//	for(int j=0; j<5; j++){
	//		data[i][j] = rand() % 100;			
	//		printf("%2d  ", data[i][j]);
	//	}	
	//	printf("\n");
	//}                     

	//int data[5];
	//for(int i=0; i<5; i++){
	//	scanf("%d", data + i);
	//}

	//for(int i=0; i<5; i++){
	//	printf("%d\n", data[i]);
	//}


	printf("输出完毕\n");

	system("pause");
}