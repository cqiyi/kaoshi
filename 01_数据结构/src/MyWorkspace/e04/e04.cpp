#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
void main()
{
	//使用string类定义字符串，完成字符串连接
	string str1("C++"),str2("程序设计");
	string str3;
	str3 = str1+str2;//连接方式1
	cout<<str3<<endl;
	
	//使用char数组定义字符串，完成连接
	char c1[] = {"c++"},c2[] = {"program"};
	char c3[20];
	int i=0,k=0;
	for(i=0;i<20;i++)//初始化c3
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
