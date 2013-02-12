/*ʵ��һ��������ĳ���Ҫ��
1.���帴����Complex�����а���ʵ��real���鲿image��
2.�ڸ������ж��巽��mod���㸴����ģ����squ(real2+image2)����ֵΪ��������
3.�������롱>>����������ʹ�ÿ���ͨ��cinֱ�Ӷ��븴����Ķ���ֵ��
4.���������<<����������ʹ�ÿ���ͨ��coutֱ�����������Ķ���ֵ��
5.���ء�+������-���������ʹ�ø�����֮����Խ��мӼ����㣻
6.��дmain����������������Ҫ��Ĺ���*/
#include<iostream.h>
#include<math.h>
class Complex
{
private:
	float real,image;
public:
	Complex(){real=0;image=0;}
	Complex(float r,float i){real=r;image=i;}
	float mod();
	friend istream& operator >> (istream& is,Complex& num);
	friend ostream& operator << (ostream& os,Complex& num);
	friend Complex operator + (Complex& a,Complex& b);
	friend Complex operator - (Complex& a,Complex& b);
};

istream& operator >>(istream& is,Complex& num)
{
	cout<<"Please input the number real: ";
	is>>num.real;
	cout<<".......................image: ";
	is>>num.image;
	return is;
}
ostream& operator <<(ostream& os,Complex& num)
{
	os<<"The resual is: ";
	if(num.image==0)
	{
		if(num.real==0)
			cout<<"0"<<endl;
		else
			cout<<num.real<<endl;
	}
	else
	{
		if(num.real==0)
			cout<<num.image<<"i"<<endl;
		else
			if(num.image<0)
				cout<<num.real<<num.image<<"i"<<endl;
			else
				cout<<num.real<<"+"<<num.image<<"i"<<endl;
	}
	return os;
}
Complex operator - (Complex& a,Complex& b)
{
	float r=a.real-b.real;
	float i=a.image-b.image;
	return Complex(r,i);
}
Complex operator + (Complex& a,Complex& b)
{
	float r=a.real+b.real;
	float i=a.image+b.image;
	return Complex(r,i);
}
float Complex::mod()
{
	return sqrt(real*real+image*image);
}
void main()
{
	Complex num1,num2,num3;
	int chioce;
	cin>>num1;
	cin>>num2;
	while(chioce!=4)
	{
		cout<<"1.sum    2.dec   3.mod    4.exit"<<endl;
		cin>>chioce;
		switch(chioce){
		case 1:
			num3=num1+num2;
			cout<<num3;
			break;
		case 2:
			num3=num1-num2;
			cout<<num3;
			break;
		case 3:
			cout<<"The fist number mod is: "<<num1.mod()<<endl;
			cout<<"The second number mod is: "<<num2.mod()<<endl;
			break;
		case 4:
			break;
		default:
			break;
		}
	}
	cout<<"Thank you for using the system!"<<endl;
}