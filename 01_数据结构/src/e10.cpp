/*
3．编一C程序，它能读入两组整数（每组整数都是66个整数），它们分别是下三角矩阵A和下三角矩阵B的按行优先排列的元素（A和B的其它元素均为零）。计算并输出矩阵A与B的乘积。

（注：程序的可执行文件名必须是 e1.exe，存于你的账号或其debug目录下。）
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	int i,j, k1,k2,c[66],s,k,count=0,flag=0;
	int a[66];
	int b[66];
	printf("请输入66个数到a中：\n");
	for(i=0; i<66; i++)
		scanf("%d",&a[i]);
	printf("请输入66个数到b中：\n");
	for(i=0; i<66; i++)
		scanf("%d",&b[i]);
	for(i=0; i<11; i++) {
		for(k=0; k<11; k++) {
			s=0;
			for(j=0; j<11&&i>=j; j++)
				k1=i*(i+1)/2+j;
			if(j>=k) 
				k2=j*(j+1)/2+i;
			else 
				continue;
			s+=a[k1]*b[k2];
			flag=1;
		}
		if(flag) {
			c[count++]=s;
			flag=0;
		}
	}
	for(i=0; i<66; i++) {
		printf("%d",c[i]);
	}
	system("pause");
}
