#include<cmath>
#include<iostream>
#include"string.h"
//using std::istream;

mycircle ::mycircle()
{
	centerx=0;
	centery=0;
	radius=0;

}
double mycircle::area()
{
	double area;
	area=3.14*radius*radius;
	return area;

}
istream &operator >>(istream & is,mycircle &circle)
{
	std::cout<<"please input x coordinate of the circle center(interger):"<<'\n';

	is>>circle.centerx;
	 std::cout<<"please input y coordinate of the circle center(integer)"<<'\n';
	 is>>circle.centery;
	std::cout<<"please input the radius of the circle (integer)"<<'\n';
	is>>circle.radius;
	return is;


}
myrectangle ::myrectangle()
{
	length=0;
	width=0;

}
double myrectangle::area()
{
	double area;
	area=length*width;
	return area;

}
istream &operator >>(istream &is ,myrectangle& rectangle)
{
	  std::cout<<"please in put the length of the rectangle (integer)"<<'\n';
	  is>>rectangle.length;
	  std::cout<<"please input the width of the rectangle (integer)"<<'\n';
	  is>>rectangle.width;
	return is;


}