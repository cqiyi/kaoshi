/*
编一C程序，它能读入一串整数（以-9999为结束标记）并对它们进行从小到大直接插入排序，同时输出排序时对这些整数进行比较的总次数（输入整数时，相邻的两个用空格隔开，整数个数<2000）。 （注：程序的可执行文件名必须是 e4.exe）
*/

#include<stdio.h>

void main()
{
	int a[2000],i,j,k=0,CountA;
	printf("input data\n");
	for(i=1; i<=2001; i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==-9999)
			break;
	}
	CountA=i-1;


	for(i=2; i<=CountA; i++)
		if(a[i]<a[i-1])
		{
			a[0]=a[i];
			j=i-1;

			do
			{
				a[j+1]=a[j];
				j--;
				k++;
			}
			while(a[0]<a[j]);
			a[j+1]=a[0];
		}

	printf("\n");
	for(i=1; i<=CountA; i++)
		printf("%d ",a[i]);
	printf("\nThe times of comparing = %d",k);
	printf("\n");
}