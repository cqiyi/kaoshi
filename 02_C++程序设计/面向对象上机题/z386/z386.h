#include<iomanip.h>
class MyGraph{
public:
	virtual double area()=0;                           //�麯���Ķ���
};
class MyCircle:MyGraph{                                //����Ķ���
private:
	int centerX;
	int centerY;
	int radius;
public:
	MyCircle();
	double area();
	friend istream & operator >> (istream & is,MyCircle & circle);  //���������غ����Ķ���
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


