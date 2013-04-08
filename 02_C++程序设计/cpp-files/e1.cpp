/*实现一个复数类的程序，要求：
1.定义复数类Complex，其中包含实部real和虚部image；
2.在复数类中定义方法mod计算复数的模，即squ(real2+image2)返回值为浮点数，
3.重载输入”>>”操作符，使得可以通过cin直接读入复数类的对象值；
4.重载输出”<<”操作符，使得可以通过cout直接输出复数类的对象值；
5.重载”+”、”-”运算符，使得复数类之间可以进行加减运算；
6.编写main函数，测试上述所要求的功能*/
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