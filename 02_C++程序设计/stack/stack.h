#ifndef STACK_H
#define STACK_H
#include<iosfwd>

class element
{
public:
	virtual void showme()=0;

	
};
class integer:public element
{
public:
	integer();
	void showme();
	friend std::istream &operator>>(std::istream & is,integer &myint);
protected:
	int myint;



	
};
class mystring:public element
{

public:
	mystring();
	void showme();
	friend std::istream &operator>>(std::istream &is,mystring &myster);

protected:
	char *mystr;
};
class stack
{
public:
	stack();
	void push(element *myele);
    void pop();
	void top();
	void  gettop();
private:
	element *stacks[5];
	int size;

};

#endif