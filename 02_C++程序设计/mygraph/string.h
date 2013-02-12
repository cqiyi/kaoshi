#ifndef STRING_H
#define STRING_H

#include<iomanip>
#include<iostream>
using std::istream;

class graphy
{
public:
	virtual double area()=0;

};
class mycircle:graphy
{
public:
	mycircle();
	double area();
	friend istream &operator >>(istream & is,mycircle &circle);


private:
	int centerx;
	int centery;
	int radius;

};
class myrectangle :graphy
{
public:
	myrectangle();
	double area();
	friend istream &operator >>(istream & is ,myrectangle &rectangle);
private:
	int length;
	int width;
	


};
#endif 
