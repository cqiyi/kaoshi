#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 255 /* �洢�ռ��ʼ������ */
typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef char String[MAXSIZE]; /*  0�ŵ�Ԫ��Ŵ��ĳ��� */


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