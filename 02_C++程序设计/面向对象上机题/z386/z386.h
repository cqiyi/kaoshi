#include<iomanip.h>
class MyGraph{
public:
	virtual double area()=0;                           //虚函数的定义
};
class MyCircle:MyGraph{                                //子类的定义
private:
	int centerX;
	int centerY;
	int radius;
public:
	MyCircle();
	double area();
	friend istream & operator >> (istream & is,MyCircle & circle);  //操作符重载函数的定义
};
class MyRectangle:MyGraph{
private:
	int length;
	int width;
public:
	MyRectangle();
	double area();
	friend istream & operator >> (istream & is,MyRectangle & Rectangle);
};


