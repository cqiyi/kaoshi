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
		cout<<"������"<<a<<endl;
	}
};
istream &operator>>(istream &is, MyInteger &MyI)
{
	cout<<" ������������";
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
		cout<<"�ַ�����"<<s<<endl;
	}
};
istream &operator>>(istream &is, MyString &MyS)
{
	cout<<" �������ַ�����";
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
		if (full()) cout<<"��������"<<endl;
		else
		{
			MyI[++size]=My;
			Elm[size]=new MyInteger;
			Elm[size]=&MyI[size];
		}
	}

	void add(MyString &My)
	{
		if (full()) cout<<"��������"<<endl;
		else
		{
			MyS[++size]=My;
			Elm[size]=new MyString;
			Elm[size]=&MyS[size];
		}
	}

	void tail()
	{
		if(empty()) cout<<"����Ϊ��"<<endl;
		else
		{
			cout<<" ���е�βԪ��Ϊ";
			Elm[size]->ShowMe();
		}
	}
	void head()
	{
		if(empty()) cout<<"����Ϊ��"<<endl;
		else
		{
			cout<<" ���е�ͷԪ��Ϊ";
			Elm[0]->ShowMe();
		}
	}

	void del()
	{
		if(empty()) cout<<"����Ϊ��"<<endl;
		else
		{
			cout<<" �����е�Ԫ��Ϊ";
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
		cout<<" 1: ����������;"<<endl;
		cout<<" 2: �ַ���������;"<<endl;
		cout<<" 3: ��ʾ����ͷԪ��;"<<endl;
		cout<<" 4: ��ʾ����βԪ��"<<endl;
		cout<<" 5: ������;"<<endl;
		cout<<" 6: �˳�����"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"��ѡ�����Ĳ�����";
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

