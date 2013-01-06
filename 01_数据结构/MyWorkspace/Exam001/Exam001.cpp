/*
1、建立图的邻接距阵，输入为：n i1 j1 i2 j2 i3.....-1 -1输出该距阵，并输出拓扑排序。提示：有向图，n是顶点数，30 > n > 0,其它的都是整数，小于n且大于等于0。
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
				cout<<"这个有向图含有环."<<endl;
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
							cout<<"这个有向图含有环, 自环."<<endl;
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
	cout<<"拓扑序列如下："<<endl;
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
	cout<<"请输入有向图节点，以-1 -1结束，和节点个数n:"<<endl;
	cin>>i>>j;
	while(i!=-1 && j!=-1)
	{
		if(i<0||j<0)
		{
			cout<<"输入错误"<<endl;
			exit(-2);
		}
		arc[i][j]=1;
		cin>>i>>j;

	}
	cin>>n;
	if(n<1||n>Maxnode)
	{
		cout<<"错误,节点数必须是在1到"<<Maxnode<<"之间的数!"<<endl;
		exit(-2);
	}
	cout<<"对应的邻接矩阵如下："<<endl;
	showMG(n);
	topsort(n);
}
