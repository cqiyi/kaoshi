#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
void main()
{
	//ʹ��string�ඨ���ַ���������ַ�������
	string str1("C++"),str2("�������");
	string str3;
	str3 = str1+str2;//���ӷ�ʽ1
	cout<<str3<<endl;
	
	//ʹ��char���鶨���ַ������������
	char c1[] = {"c++"},c2[] = {"program"};
	char c3[20];
	int i=0,k=0;
	for(i=0;i<20;i++)//��ʼ��c3
		c3[i]='\0';
	i=0;
	while(c1[i]!='\0')
	{
		c3[k]=c1[i];
		i++;
		k++;
	}
	i=0;
	while(c2[i]!='\0')
	{
		c3[k]=c2[i];
		i++;
		k++;
	}
	cout<<c3<<endl<<endl;

	system("pause");
}
