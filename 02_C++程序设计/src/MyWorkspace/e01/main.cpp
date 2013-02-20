#include "iostream.h"
#include "string.h"
const int MAX=1000;
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
	MyInteger() {
		a=0;
	}
	friend istream& operator>>(istream& is, MyInteger& myi) {
		is>>myi.a;
		myi.a = myi.a * 10;
		return is;
	}

	int Get() {
		return a;
	}
	void ShowMe() {
		cout<<" ������"<<a<<endl;
	}
};

class MyString:public Element
{
	int a;
public:
	MyInteger() {
		a=0;
	}
	friend istream& operator>>(istream& is, MyInteger& myi) {
		is>>myi.a;
		myi.a = myi.a * 10;
		return is;
	}

	int Get() {
		return a;
	}
	void ShowMe() {
		cout<<" ������"<<a<<endl;
	}
};

class Stack
{
	Element* el[MAX];
	int loc;
public:
	Stack() {
		loc=-1;
	}
	void push(Element* my) {
		if(loc<MAX){
			el[++loc]=my;
		} else {
			cout<<"ջ����"<<endl;
		}
	}

	void top() {
		if(loc>=0){
			el[loc]->ShowMe();
		} else {
			cout<<"top():ջ�ѿ�"<<endl;
		}
	}

	void pop() {
		if(loc>=0){
			el[loc--]->ShowMe();
		} else {
			cout<<"pop():ջ�ѿ�"<<endl;
		}
	}
};

int main(int argc, char* argv[])
{
	Stack st1;
	int i, j;

	cout<<"������Ҫ��ջ����������";
	cin>>j;
	cout<<"������"<<j<<"������"<<endl;
	for (i=0; i<j; i++) {
		MyInteger* my1 = new MyInteger();
		cin>>*my1;
		st1.push(my1);
	}
	cout<<"ջ��Ԫ��Ϊ��";
	st1.top();
	cout<<"������Ҫ��ջ��Ԫ�ظ�����";
	cin>>j;
	cout<<"���γ�ջԪ��Ϊ��"<<endl;
	for (i=0; i<j; i++)
		st1.pop();
	cout<<"��ջ��ջ��Ԫ��Ϊ��";
	st1.top();

	return 0;
}

