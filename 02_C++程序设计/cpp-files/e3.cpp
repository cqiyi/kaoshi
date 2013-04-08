/*实现一个可以操作图形的程序，要求：
1.定义基类MyGraph，至少包含纯虚函数Area，计算图形面积；
2.从基类MyGraph中派生矩形类MyRectangle和圆形类MyCircle，其中矩形信息包括矩形的长和宽，
  圆形信息包括圆形的圆心和半径，具体实现上述纯虚函数Area，计算矩形和圆形的面积；
3.重载输入”>>”操作符，使得可以通过cin输入矩形类和圆形类的对象值；
4.在main函数中，体现面向对象的多态特性，即定义指向MyGraph的指针，
  根据用户选择输入矩形或者圆形的对象值，并且调用Area计算其面积。*/
#include<iostream.h>
class MyGraph
{
public:
	virtual void Area()=0;
};
class MyRectangle:public MyGraph
{
private:
	float h,w;
public:
	MyRectangle(){h=0;w=0;}
	friend istream& operator >> (istream& is,MyRectangle& R);
	void Area();
};
istream& operator >> (istream& is,MyRectangle& R)
{
	cout<<endl<<"******请输入矩形信息********"<<endl<<endl;
	cout<<"矩形长: ";cin>>R.h;cout<<endl;
	while(R.h<=0){
		cout<<"非法输入!请重新输入长: ";
		cin>>R.h;
	}
	cout<<"    宽: ";cin>>R.w;cout<<endl;
	while(R.w<=0){
		cout<<"非法输入!请重新输入宽: ";
		cin>>R.w;
	}
	return is;
}
void MyRectangle::Area()
{
	cout<<"矩形面积为: "<<h*w<<endl;
}
class MyCircle:public MyGraph
{
private:
	float x,y;
	float r;
public:
	MyCircle(){x=0;y=0;r=0;}
	friend istream& operator >> (istream& is,MyCircle& C);
	void Area();
};
istream& operator >> (istream& is,MyCircle& C)
{
	cout<<endl<<"******请输入圆形信息********"<<endl<<endl;
	cout<<"圆形横坐标: ";cin>>C.x;cout<<endl;
	cout<<"    纵坐标: ";cin>>C.y;cout<<endl;
	cout<<"      半径: ";cin>>C.r;cout<<endl;
	while(C.r<=0){
		cout<<"非法输入!请重新输入半径: ";
		cin>>C.r;
	}
	return is;
}
void MyCircle::Area()
{
	cout<<"圆形面积为: "<<3.1416*r*r<<endl;
	return;
}
void main()
{
	MyCircle cir;
	MyRectangle rec;
	MyGraph *graph;
	int chioce;
	cout<<endl<<"**********************本系统提供以下功能**********************"<<endl;
	while(chioce!=3)
	{
		cout<<endl;
		cout<<"1.输入矩形并计算矩形面积    2.输入圆形并计算圆形面积    3.退出"<<endl<<endl;
		cout<<"请输入你的选择: ";
		cin>>chioce;
		switch(chioce)
		{
		case 1:
			cin>>rec;
			//rec.Area();
			graph=&rec;
			break;
		case 2:
			cin>>cir;
			//cir.Area();
			graph=&cir;
			break;
		case 3:
			break;
		default:
			break;
		}
		if(chioce==1||chioce==2)
			graph->Area();
	}
	cout<<endl<<"谢谢使用本系统！"<<endl;
}


