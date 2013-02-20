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
		cout<<" 整数："<<a<<endl;
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
		cout<<" 整数："<<a<<endl;
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
			cout<<"栈已满"<<endl;
		}
	}

	void top() {
		if(loc>=0){
			el[loc]->ShowMe();
		} else {
			cout<<"top():栈已空"<<endl;
		}
	}

	void pop() {
		if(loc>=0){
			el[loc--]->ShowMe();
		} else {
			cout<<"pop():栈已空"<<endl;
		}
	}
};

int main(int argc, char* argv[])
{
	Stack st1;
	int i, j;

	cout<<"请输入要进栈整数个数：";
	cin>>j;
	cout<<"请输入"<<j<<"个整数"<<endl;
	for (i=0; i<j; i++) {
		MyInteger* my1 = new MyInteger();
		cin>>*my1;
		st1.push(my1);
	}
	cout<<"栈顶元素为：";
	st1.top();
	cout<<"请输入要出栈的元素个数：";
	cin>>j;
	cout<<"依次出栈元素为："<<endl;
	for (i=0; i<j; i++)
		st1.pop();
	cout<<"出栈后栈顶元素为：";
	st1.top();

	return 0;
}

