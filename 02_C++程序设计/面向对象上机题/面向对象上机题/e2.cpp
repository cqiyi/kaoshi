/*实现一个可以操作图形的程序，要求：
1.定义基类MyGraph，至少包含图形种类type和显示函数ShowMe；
2.从基类MyGraph中派生矩形类MyRectangle和圆形类MyCircle，
  其中矩形信息包括矩形的对角线两个顶点，圆形信息包括圆形的圆心和半径，
  分别实现ShowMe函数用于显示图形的具体信息；
3.重载输入”>>”操作符，使得可以通过cin直接输入上述矩形类和圆形类的对象值；
4.编写main函数测试上述要求的各项功能，即可以读入圆形或矩形的对象值，并且显示对象的详细信息*/
#include<iostream.h>
#include<math.h>
class MyGraph
{
private:
	int type;
public:
	void ShowMe();
};
class MyRectangle:public MyGraph
{
private:
	int x1,y1;
	int x2,y2;
public:
	MyRectangle(){x1=0;y1=0;x2=0;y2=0;}
	friend istream& operator >> (istream& is,MyRectangle& R);
	void ShowMe();
};
istream& operator >> (istream& is,MyRectangle& R)
{
	cout<<"***请输入矩形信息!***"<<endl<<endl;
	cout<<"矩形左上角横坐标x1: ";cin>>R.x1;
	cout<<"..........纵坐标y1: ";cin>>R.y1;
	cout<<"....右下角横坐标x2: ";cin>>R.x2;
	cout<<"..........纵坐标y2: ";cin>>R.y2;
	cout<<endl;
	return is;
}
void MyRectangle::ShowMe()
{
	cout<<"***矩形的信息如下!***"<<endl<<endl;
	cout<<"矩形左上角坐标: "<<"("<<x1<<","<<y1<<")"<<endl;
	cout<<"....右下角坐标: "<<"("<<x2<<","<<y2<<")"<<endl;
	cout<<endl;
	return;
}
class MyCircle:public MyGraph
{
private:
	int x,y;
	int r;
public:
	MyCircle(){x=0;y=0;r=0;}
	friend istream& operator >> (istream& is,MyCircle& C);
	void ShowMe();
};
istream& operator >> (istream& is,MyCircle& C)
{
	cout<<"***请输入圆形信息!***"<<endl<<endl;
	cout<<"圆心横坐标x: ";cin>>C.x;
	cout<<"....纵坐标y: ";cin>>C.y;
	cout<<"......半径r: ";cin>>C.r;
	cout<<endl;
	return is;
}
void MyCircle::ShowMe()
{
	cout<<"***圆形信息如下!***"<<endl<<endl;
	cout<<"圆心坐标为: "<<"("<<x<<","<<y<<")  "<<"半径为: "<<r<<endl<<endl;
	return;
}
void main()
{
	MyRectangle num1;
	MyCircle num2;
	int choice;
	cout<<endl;
	cout<<"**************本系统提供以下功能***************"<<endl<<endl;
	while(choice!=3)
	{
		cout<<"1.输入矩形并显示     2.输入圆形并显示     3.退出"<<endl<<endl;
		cout<<"请输入你的选择: ";
		cin>>choice;
		cout<<endl;
		switch(choice)
		{
		case 1:
			cin>>num1;
			num1.ShowMe();
			break;
		case 2:
			cin>>num2;
			num2.ShowMe();
			break;
		case 3:
			break;
		default:
			break;
		}
	}
	cout<<"谢谢使用本系统！"<<endl;
}
