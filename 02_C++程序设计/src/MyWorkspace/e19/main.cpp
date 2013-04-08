#include "iostream"
#include "string.h"
const max=1000;
#define NULL 0

class Element
{
public:
	virtual void ShowMe () = 0;
};

class MyInteger:public Element
{
	int a;
public:
	MyInteger()
	{
		a=0;
	}
	friend istream &operator>>(istream &is, MyInteger &MyI);
	int Get()
	{
		return a;
	};
	void ShowMe()
	{
		cout<<"整数："<<a<<endl;
	}
};
istream &operator>>(istream &is, MyInteger &MyI)
{
	cout<<" 请输入整数：";
	is>>MyI.a;
	return is;
}

class MyString:public Element
{
	char s[100];
public:
	friend istream &operator>>(istream &is, MyString &MyS);
	void ShowMe()
	{
		cout<<"字符串："<<s<<endl;
	}
};
istream &operator>>(istream &is, MyString &MyS)
{
	cout<<" 请输入字符串：";
	is>>MyS.s;
	return is;
}

class Queue
{
	int size;
	Element *Elm[max];
	MyInteger MyI[max];
	MyString MyS[max];
public:
	Queue()
	{
		for (int i=0; i<max; i++)
			Elm[i]=NULL;
		size=-1;
	}
	void add(MyInteger &My)
	{
		if (full()) cout<<"队列已满"<<endl;
		else
		{
			MyI[++size]=My;
			Elm[size]=new MyInteger;
			Elm[size]=&MyI[size];
		}
	}

	void add(MyString &My)
	{
		if (full()) cout<<"队列已满"<<endl;
		else
		{
			MyS[++size]=My;
			Elm[size]=new MyString;
			Elm[size]=&MyS[size];
		}
	}

	void tail()
	{
		if(empty()) cout<<"队列为空"<<endl;
		else
		{
			cout<<" 队列的尾元素为";
			Elm[size]->ShowMe();
		}
	}
	void head()
	{
		if(empty()) cout<<"队列为空"<<endl;
		else
		{
			cout<<" 队列的头元素为";
			Elm[0]->ShowMe();
		}
	}

	void del()
	{
		if(empty()) cout<<"队列为空"<<endl;
		else
		{
			cout<<" 出队列的元素为";
			Elm[size--]->ShowMe();
		}
	}
	bool empty()

	{
		return (bool)(size==-1);
	}
	bool full()
	{
		return (bool)(size==max-1);
	}
};

void main()
{
	MyInteger my1;
	MyString my2;
	Queue queue;
	int s=1;
	while(s)
	{
		cout<<"Please select 1-6 "<<endl;
		cout<<" 1: 整数进队列;"<<endl;
		cout<<" 2: 字符串进队列;"<<endl;
		cout<<" 3: 显示队列头元素;"<<endl;
		cout<<" 4: 显示队列尾元素"<<endl;
		cout<<" 5: 出队列;"<<endl;
		cout<<" 6: 退出程序"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"请选择您的操作：";
		cin>>s;
		switch(s)
		{
		case 1:
			cin>>my1;
			queue.add(my1);
			break;
		case 2:
			cin>>my2;
			queue.add(my2);
			break;
		case 3:
			queue.head();
			break;
		case 4:
			queue.tail();
			break;
		case 5:
			queue.del();
			break;
		default:
			s=0;
			break;
		}
	}
}

