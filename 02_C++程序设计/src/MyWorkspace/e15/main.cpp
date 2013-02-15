#include<iostream>
#include"graphy.h"
using namespace std;

int main()
{
	mycircle circle;
	myrectangle rectangles;
	cin>>circle;
	cout<<"the area of the circle is "<<circle.area()<<'\n';
	cin>>rectangles;
	cout<<"the area of the rectangle is "<<rectangles.area()<<'\n';
	return 0;
}