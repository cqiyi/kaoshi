/*
1������ͼ���ڽӾ�������Ϊ��n i1 j1 i2 j2 i3.....-1 -1����þ��󣬲��������������ʾ������ͼ��n�Ƕ�������30 > n > 0,�����Ķ���������С��n�Ҵ��ڵ���0��
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

//����Ƿ����ָ��NodeID�ڵ�ı�(���)
bool hasInRoad(int nodeID)
{
	for(int i=0; i<n; i++) {
		if(arc[i][nodeID] == 1) return true;
	}
	return false;
}

//��ͼ���Ƴ��ýڵ㣬�Ƴ��˵Ľڵ㣬ֵΪ-1
void removeNode(int nodeID)
{
	for(int j=0; j<n; j++) {
		arc[nodeID][j] = -1;
	}
}

void showList()
{
	//�������������
	cout<<"������������:"<<endl;
	for(int i=0; i<n; i++) {
		cout<<"V"<<list[i]<<" ";
	}
	cout<<endl;
}

void main()
{
	cout<<"����������ͼ�Ľڵ㣬��-1,-1����:"<<endl;
	int i,j;
	while(true) {
		cin>>i>>j;
		if(i==-1 && j==-1) break;
		if(i<0  || j<0) {
			cout<<"�������"<<endl;
			exit(1);
		}
		arc[i][j] = 1;
		cout<<endl;
	}
	cout<<"�ڵ���(1~"<<MAX_NODE<<"):"<<endl;
	cin>>n;
	if(n<1 || n>MAX_NODE) {
		cout<<"����,�ڵ�����������1��"<<MAX_NODE<<"֮�����"<<endl;
		exit(1);
	}

	cout<<"����ڽӾ������£�"<<endl;
	showMGraph();

	//������������
	while(true) {
		//��������ʣ��Ľڵ㶼û�����
		bool flag = true;

		for(int i=0; i<n; i++) {
			//������ѱ��Ƴ����ߴ�����ȵĽڵ�
			if((arc[nodeID][nodeID] == -1) || hasInRoad(i)) continue;

			//���費����
			flag = false;

			//�ýڵ�û�����
			list[index++] = i;
			removeNode(i);

			//���нڵ㶼�Ѿ�����
			if(index>=n) {
				showList();
				return;
			}
		}
		if(flag) {
			cout<<"������ͼ���л�."<<endl;
			exit(2);
		}
	}
}