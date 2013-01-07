/*
1、建立图的邻接距阵，输入为：n i1 j1 i2 j2 i3.....-1 -1输出该距阵，并输出拓扑排序。提示：有向图，n是顶点数，30 > n > 0,其它的都是整数，小于n且大于等于0。
*/

#include <iostream.h>
#include <stdlib.h>

void exit(int);
#define MAX_NODE 30

int arc[MAX_NODE][MAX_NODE]= {0};
int list[MAX_NODE]= {0};
int n,index = 0;

void showMGraph()
{
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<arc[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

//检查是否存在指向NodeID节点的边(入度)
bool hasInRoad(int nodeID)
{
	for(int i=0; i<n; i++) {
		if(arc[i][nodeID] == 1) return true;
	}
	return false;
}

//从图中移除该节点，移除了的节点，值为-1
void removeNode(int nodeID)
{
	for(int j=0; j<n; j++) {
		arc[nodeID][j] = -1;
	}
}

void showList()
{
	//输出拓扑排序结果
	cout<<"拓扑排序如下:"<<endl;
	for(int i=0; i<n; i++) {
		cout<<"V"<<list[i]<<" ";
	}
	cout<<endl;
}

void main()
{
	cout<<"请输入有向图的节点，以-1,-1结束:"<<endl;
	int i,j;
	while(true) {
		cin>>i>>j;
		if(i==-1 && j==-1) break;
		if(i<0  || j<0) {
			cout<<"输入错误"<<endl;
			exit(1);
		}
		arc[i][j] = 1;
		cout<<endl;
	}
	cout<<"节点数(1~"<<MAX_NODE<<"):"<<endl;
	cin>>n;
	if(n<1 || n>MAX_NODE) {
		cout<<"错误,节点数必须是在1到"<<MAX_NODE<<"之间的数"<<endl;
		exit(1);
	}

	cout<<"输出邻接矩阵如下："<<endl;
	showMGraph();

	//进行拓扑排序
	while(true) {
		//假设所有剩余的节点都没有入度
		bool flag = true;

		for(int i=0; i<n; i++) {
			//如果是已被移除或者存在入度的节点
			if((arc[nodeID][nodeID] == -1) || hasInRoad(i)) continue;

			//假设不成立
			flag = false;

			//该节点没有入度
			list[index++] = i;
			removeNode(i);

			//所有节点都已经排序
			if(index>=n) {
				showList();
				return;
			}
		}
		if(flag) {
			cout<<"该有向图含有环."<<endl;
			exit(2);
		}
	}
}