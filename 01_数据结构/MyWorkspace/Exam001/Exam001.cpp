/*
1������ͼ���ڽӾ�������Ϊ��n i1 j1 i2 j2 i3.....-1 -1����þ��󣬲��������������ʾ������ͼ��n�Ƕ�������30 > n > 0,�����Ķ���������С��n�Ҵ��ڵ���0��
*/

#include "iostream.h"

void exit(int);

#define Maxnode 40
int arc[Maxnode][Maxnode]= {0};

void topsort(int n)
{
	int Inde[Maxnode]= {0},count=0,flag,sort[Maxnode];
	flag=0;
	while (true)
	{
		if(count>=n)break;
		for(int j = 0; j<n;)
		{
			if(flag>=n-1)
			{
				cout<<"�������ͼ���л�."<<endl;
				return;
			}
			if(Inde[j]!=1)
			{
				for(int i=0; i<n; i++)
				{
					if(arc[i][j]==1)
					{
						if(i==j)
						{
							cout<<"�������ͼ���л�, �Ի�."<<endl;
							return;
						}
						flag++;
						goto L1;
					}
				}
				sort[count++]=j;
				Inde[j]=1;
				flag--;
				for(int a=0; a<n; a++)
				{
					if(arc[j][a]==1)
					{
						arc[j][a]=0;
					}
				}
			}
L1:
			j++;
		}
	}
	cout<<"�����������£�"<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"V"<<sort[i]<<" ";
	}
	cout<<endl;

}
void showMG(int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<arc[i][j]<<" ";
		cout<<endl;
	}
}
void main()

{
	int i,j,n;
	cout<<"����������ͼ�ڵ㣬��-1 -1�������ͽڵ����n:"<<endl;
	cin>>i>>j;
	while(i!=-1 && j!=-1)
	{
		if(i<0||j<0)
		{
			cout<<"�������"<<endl;
			exit(-2);
		}
		arc[i][j]=1;
		cin>>i>>j;

	}
	cin>>n;
	if(n<1||n>Maxnode)
	{
		cout<<"����,�ڵ�����������1��"<<Maxnode<<"֮�����!"<<endl;
		exit(-2);
	}
	cout<<"��Ӧ���ڽӾ������£�"<<endl;
	showMG(n);
	topsort(n);
}
