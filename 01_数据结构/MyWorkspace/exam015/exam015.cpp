/*
��һC�������ܶ���һ����������-9999Ϊ������ǣ��������ǽ��д�С����ֱ�Ӳ�������ͬʱ�������ʱ����Щ�������бȽϵ��ܴ�������������ʱ�����ڵ������ÿո��������������<2000���� ��ע������Ŀ�ִ���ļ��������� e4.exe��
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