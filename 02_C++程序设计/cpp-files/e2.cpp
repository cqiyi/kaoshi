/*ʵ��һ�����Բ���ͼ�εĳ���Ҫ��
1.�������MyGraph�����ٰ���ͼ������type����ʾ����ShowMe��
2.�ӻ���MyGraph������������MyRectangle��Բ����MyCircle��
  ���о�����Ϣ�������εĶԽ����������㣬Բ����Ϣ����Բ�ε�Բ�ĺͰ뾶��
  �ֱ�ʵ��ShowMe����������ʾͼ�εľ�����Ϣ��
3.�������롱>>����������ʹ�ÿ���ͨ��cinֱ�����������������Բ����Ķ���ֵ��
4.��дmain������������Ҫ��ĸ���ܣ������Զ���Բ�λ���εĶ���ֵ��������ʾ�������ϸ��Ϣ*/
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
	cout<<"***�����������Ϣ!***"<<endl<<endl;
	cout<<"�������ϽǺ�����x1: ";cin>>R.x1;
	cout<<"..........������y1: ";cin>>R.y1;
	cout<<"....���½Ǻ�����x2: ";cin>>R.x2;
	cout<<"..........������y2: ";cin>>R.y2;
	cout<<endl;
	return is;
}
void MyRectangle::ShowMe()
{
	cout<<"***���ε���Ϣ����!***"<<endl<<endl;
	cout<<"�������Ͻ�����: "<<"("<<x1<<","<<y1<<")"<<endl;
	cout<<"....���½�����: "<<"("<<x2<<","<<y2<<")"<<endl;
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
	cout<<"***������Բ����Ϣ!***"<<endl<<endl;
	cout<<"Բ�ĺ�����x: ";cin>>C.x;
	cout<<"....������y: ";cin>>C.y;
	cout<<"......�뾶r: ";cin>>C.r;
	cout<<endl;
	return is;
}
void MyCircle::ShowMe()
{
	cout<<"***Բ����Ϣ����!***"<<endl<<endl;
	cout<<"Բ������Ϊ: "<<"("<<x<<","<<y<<")  "<<"�뾶Ϊ: "<<r<<endl<<endl;
	return;
}
void main()
{
	MyRectangle num1;
	MyCircle num2;
	int choice;
	cout<<endl;
	cout<<"**************��ϵͳ�ṩ���¹���***************"<<endl<<endl;
	while(choice!=3)
	{
		cout<<"1.������β���ʾ     2.����Բ�β���ʾ     3.�˳�"<<endl<<endl;
		cout<<"���������ѡ��: ";
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
	cout<<"ллʹ�ñ�ϵͳ��"<<endl;
}
