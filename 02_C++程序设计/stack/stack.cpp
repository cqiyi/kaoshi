#include<iostream>
#include"stack.h"
using std::cout;
using std::cin;

integer::integer()
{
	myint=0;


}
void integer::showme()
{
	cout<<"the element is an integer,and its value is "<<myint<<'\n';
	

}
std::istream &operator>>(std::istream & is,integer &myint)
{
	cout<<"please input the value of integer:";
	return is>>myint.myint;
}
mystring::mystring()
{
mystr="";
}
void mystring::showme()
{
	cout<<"the element is an string ,and its value "<<mystr<<'\n';

}
std::istream & operator>>(std::istream &is,mystring &myster)
{
	cout<<"please input the value of string :";
	myster.mystr=new char [20];
	return is>>myster.mystr;
}
stack::stack()
{
	
	size =0;
	for(int i=0;i<5;i++)
	{
		stacks[i]=NULL;

	}
}
void stack::pop()
{

	if(size==0)
	{
		cout<<"the stack is empty!"<<'\n';
		return ;
	}
	for (int i=0;i<size-1;i++)
	{
		stacks[i]=stacks[i+1];
	

	}
		stacks[size-1]=NULL;
		size--;
		return ;
}
void stack::top()
{
	if(size ==0)
	{
		cout<<"the stack is empty!"<<'\n';
		return ;
	}
	stacks[0]->showme();
	return ;


}
void stack::push(element *myele)
{
	if(size==5)
	{
		cout<<"the stack is full your element can not be pushed !"<<'\n';
		return ;

	}
	for (int i=size;i>0;i--)
		stacks[i]=stacks[i-1];
	stacks[0]=myele;
	size++;
	return ;

} 
void stack::gettop()
{
	void top();
	void pop();
	return ;

}

