/*请实现一个栈，既可以存放整数，又可以存放字符串。
  简单的说，栈是一种数据结构，按照后进先出的顺序管理进、出栈的元素。本题要求完成：
1.实现描述栈的类Stack，其中定义了栈的实际大小Size，并包括进栈函数Push，出栈函数Pop和显示栈顶元素的函数Top
2.定义基类Element，至少包含纯虚函数ShowMe
3.从基类Element中派生整数类MyInteger和字符串类MyString，具体实现上述纯虚函数ShowMe,显示该元素的类型和相应的值
4.重载输入>>操作符，使可以通过cin读入整数和字符串
5.编写main函数，测试以上各种功能，栈中元素是整数或字符串*/
#include<iostream.h>
const int Max=20;
class Element
{
public:
	virtual void ShowMe()=0;
};
class MyInteger:public Element
{
private:
	int Integer;
public:
	MyInteger(){Integer=0;}
	friend istream& operator >> (istream& is,MyInteger& integer);
	void ShowMe();
};
istream& operator >> (istream& is,MyInteger& integer)
{
	cout<<endl<<"请输入要进栈的整数: ";cin>>integer.Integer;
	return is;
}
void MyInteger::ShowMe()
{
	cout<<endl<<"该元素为整型,值为: "<<Integer<<endl;
	return;
}
class MyString:public Element
{
private:
	char *String;
public:
	MyString(){String=NULL;}
	friend istream& operator >> (istream& is,MyString& string);
	void ShowMe();
};
istream& operator >> (istream& is,MyString& string)
{
	string.String=new char[20];
	cout<<endl<<"请输入要进栈的字符串: ";cin>>string.String;
	return is;
}
void MyString::ShowMe()
{
	cout<<endl<<"该元素为字符型,值为: "<<String<<endl;
	return;
}
class Stack
{
private:
	int Size;
	Element *stack[Max];
public:
	Stack(){Size=0;for(int i=0;i<Max;i++) stack[i]=NULL;}
	void Push(Element *element);
	void Pop();
	void Top();
};
void Stack::Push(Element *element)
{
	if(Size>=Max)
		cout<<endl<<"栈满!不能进行压栈!"<<endl;
	else{	
		Size++;
		stack[Size]=element;
		cout<<endl<<"数据已成功进栈!"<<endl;
	}
	return;
}
void Stack::Pop()
{
	if(Size==0)
		cout<<endl<<"栈空!没有元素可以出栈!"<<endl;
	else{
		stack[Size]->ShowMe();
		stack[Size]=NULL;
		Size--;
		cout<<endl<<"该数据已成功出栈!"<<endl;
	}
	return;
}
void Stack::Top()
{
	if(Size==0)
		cout<<endl<<"栈空!栈顶无元素"<<endl;
	else{
		cout<<endl<<"栈顶元素为: "<<endl;
		stack[Size]->ShowMe();
	}
	return;
}
void main()
{
	Stack *sta=new Stack;
	MyString *str;
	MyInteger *inte;
	int chioce,i;
	cout<<endl<<"**************本系统提供以下操作***************"<<endl;
	while(chioce!=4)
	{
		i=0;
		cout<<endl<<"1.压栈     2.出栈     3.显示栈顶元素     4.退出 "<<endl;
		cin>>chioce;
		switch(chioce)
		{
		case 1:
			while(i!=3)
			{
				cout<<endl<<"1.整数进栈      2.字符串进栈      3.退出"<<endl;
				cin>>i;
				switch(i)
				{
				case 1:
					inte=new MyInteger;
					cin>>*inte;
					sta->Push(inte);
					break;
				case 2:
					str=new MyString;
					cin>>*str;
					sta->Push(str);
					break;
				case 3:
					break;
				}
			}
			break;
		case 2:
			sta->Pop();
			break;
		case 3:
			sta->Top();
			break;
		case 4:
			break;
		}
	}
	cout<<endl<<"     谢谢使用本系统!"<<endl;
	return;
}