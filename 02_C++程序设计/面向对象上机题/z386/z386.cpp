#include<iostream.h>
#include<math.h>
#include"z386.h"

MyCircle::MyCircle(){
	centerX=0;
	centerY=0;
	radius=0;
}
double MyCircle::area(){
	double area;
	area=3.14159*radius*radius;
	return area;
}
istream & operator >> (istream & is,MyCircle & circle){
	cout<<"please input x coordinate of the circle center(integer):";
	cin>>circle.centerX;
	cout<<"please input y coordinate of the circle center(integer):";
	cin>>circle.centerY;
	cout<<"please input the radius of the circle(integer):";
	cin>>circle.radius;			
	return is;
}
MyRectangle::MyRectangle(){
	length=0;
	width=0;
}
double MyRectangle::area(){
	double area;
	area=length*width;
	return area;
}
istream & operator >> (istream & is,MyRectangle & rectangle){
	cout<<"please input the length of the rectangle(integer):";
	cin>>rectangle.length;
	cout<<"please input the width of the rectangle(integer):";
	cin>>rectangle.width;
	return is;
}
void main(){
	MyCircle circle;
	MyRectangle rectangle;
	cin>>circle;
	cout<<"the area of the circle is"<<circle.area()<<endl;
	cin>>rectangle;
	cout<<"the area of the rectangle is"<<rectangle.area()<<endl;
	return;
}
