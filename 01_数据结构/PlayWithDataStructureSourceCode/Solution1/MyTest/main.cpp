#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 255 /* 存储空间初始分配量 */
typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char String[MAXSIZE]; /*  0号单元存放串的长度 */


int main(){
	//String str = "sssssssssssssssssssssssssssssssss";
	//strcat(str, "bbbbb");
	//printf("%s\n", str);
	int i = 10;
	int* j = &i;
	int** k = &j;
	printf("%d", k);
	system("pause");




}