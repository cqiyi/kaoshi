/*ʵ��һ�����Բ���ͼ�εĳ���Ҫ��
1.�������MyGraph�����ٰ������麯��Area������ͼ�������
2.�ӻ���MyGraph������������MyRectangle��Բ����MyCircle�����о�����Ϣ�������εĳ��Ϳ�
  Բ����Ϣ����Բ�ε�Բ�ĺͰ뾶������ʵ���������麯��Area��������κ�Բ�ε������
3.�������롱>>����������ʹ�ÿ���ͨ��cin����������Բ����Ķ���ֵ��
4.��main�����У������������Ķ�̬���ԣ�������ָ��MyGraph��ָ�룬
  �����û�ѡ��������λ���Բ�εĶ���ֵ�����ҵ���Area�����������*/
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
	cout<<endl<<"******�����������Ϣ********"<<endl<<endl;
	cout<<"���γ�: ";cin>>R.h;cout<<endl;
	while(R.h<=0){
		cout<<"�Ƿ�����!���������볤: ";
		cin>>R.h;
	}
	cout<<"    ��: ";cin>>R.w;cout<<endl;
	while(R.w<=0){
		cout<<"�Ƿ�����!�����������: ";
		cin>>R.w;
	}
	return is;
}
void MyRectangle::Area()
{
	cout<<"�������Ϊ: "<<h*w<<endl;
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
	cout<<endl<<"******������Բ����Ϣ********"<<endl<<endl;
	cout<<"Բ�κ�����: ";cin>>C.x;cout<<endl;
	cout<<"    ������: ";cin>>C.y;cout<<endl;
	cout<<"      �뾶: ";cin>>C.r;cout<<endl;
	while(C.r<=0){
		cout<<"�Ƿ�����!����������뾶: ";
		cin>>C.r;
	}
	return is;
}
void MyCircle::Area()
{
	cout<<"Բ�����Ϊ: "<<3.1416*r*r<<endl;
	return;
}
void main()
{
	MyCircle cir;
	MyRectangle rec;
	MyGraph *graph;
	int chioce;
	cout<<endl<<"**********************��ϵͳ�ṩ���¹���**********************"<<endl;
	while(chioce!=3)
	{
		cout<<endl;
		cout<<"1.������β�����������    2.����Բ�β�����Բ�����    3.�˳�"<<endl<<endl;
		cout<<"���������ѡ��: ";
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
	cout<<endl<<"ллʹ�ñ�ϵͳ��"<<endl;
}


