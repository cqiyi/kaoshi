/*****************************************************\
4����һC�������ܶ������һ��������������1000������-9999Ϊ������ǣ�������a�У��ٶ�a��Ԫ�ؽ���ֱ�Ӳ������򣨴�С�������򣩣���������������ùؼ��ֱȽϴ�����������ʱ���������ڵ������ÿո����)��
\*****************************************************/
#include "iostream.h"
#define  MAX 1000
int a[MAX] = {-9999};

int InsertSort(int n)
{
	int count= 1;
	int temp;
	int j;
	for(int i = 1; i< n ; i++)
	{
		if(a[i] < a[i-1] && count ++)
		{
			temp = a[i];
			j = i-1;
			do
			{
				a[j+1] = a[j];
				j--;
			}
			while (temp < a[j] && count ++);
			a[j+1] = temp;
		}
	}
	return count -1;
}

void main()
{
	cout<<"enter a"<<endl;

	int temp;
	cin>>temp;

	int n = 0;
	while(temp != -9999)
	{
		a[n++]= temp;
		cin>>temp;
	}

	int count = InsertSort(n);

	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\nthe num is "<<count<<endl;
}