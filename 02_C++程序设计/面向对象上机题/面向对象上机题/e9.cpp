/*北京大学计算机应用专业的系统班（业余）2001年10月份面向对象上机考试题
请实现一个简单的超市商品管理系统，超市有三个货架，分别放着日常用品、食品和家电。本题要求完成： 
(1) 实现描述超市的类Supermarket，其中定义了增加商品的函数Add（可以增加新的商品，也可以增加已有商品的数量），
    按照//商品名称//卖出商品的函数Sale（如果商品现有数量少于卖出数量，则不能继续卖出商品，并给出提示信息），
	按照//商品类别//查询商品情况的函数Search，并显示查询结果（每类商品中有哪些商品，每种商品的名称和现有数量）。 
(2) 定义商品类Goods，包含属性名称、和商品现有数量，以及纯虚函数ShowMe。 
(3) 从基类Goods中派生日常用品类DailyGoods、食品类Food和家电类ElectricalAppliance，
    其中食品类商品拥有保质期属性，家电类商品拥有颜色属性，具体实现上述纯虚函数ShowMe，
	显示商品的名称、现有数量和食品类商品的保质期，以及家电类商品的颜色。 
(4) 重载输入“>>”*作符，使得可以通过cin直接读入上述日常用品类、食品类和家电类的对象值。 
(5) 编写main函数，测试上述所要求的各种功能，即可以根据菜单命令增加、卖出和查询各类商品，
    其中的商品可以是日常用品、食品和家用电器。 
提示： 
虚拟基类Goods的定义至少包括以下纯虚函数ShowMe， 
class Goods 
{ 
// …… 
public: 
virtual void ShowMe () = 0; 
// …… 
}; */  
#include<iostream.h>
#include<string.h>
const int con=1000;
class Goods
{
protected:
	char *Name;
	int Num;
	int Type;
public:
	virtual void ShowMe()=0;
	char *getName(){return Name;}
	int getNum(){return Num;}
	int getNum(int m){Num=m;return Num;}
	int getType(){return Type;}
};
class DailyGoods:public Goods
{
public:
	DailyGoods(){Name=new char[20];Num=0;Type=1;}
	friend istream &operator >>(istream & is,DailyGoods &dg);
	void ShowMe()
	{	cout<<"Good name: "<<Name<<"  "<<"Good num: "<<Num<<"  "<<endl;}
};
istream &operator >>(istream & is,DailyGoods &dg)
{
	cout<<"the DailyGoods's name: ";
	cin>>dg.Name;
	cout<<"the DailyGoods's num: ";
	cin>>dg.Num;
	return is;
}
class Food:public Goods
{
	char *Date;
public:
	Food(){Name=new char[20];Num=0;Date=new char[10];Type=2;}
	friend istream &operator >>(istream & is,Food &fg);
	void ShowMe()
	{cout<<"Good name: "<<Name<<"  "<<"Good num: "<<Num<<"  "<<"Good date: "<<Date<<endl;}
};
istream &operator >>(istream & is,Food &fg)
{
	cout<<"the Food's name: ";
	cin>>fg.Name;
	cout<<"the Food's num: ";
	cin>>fg.Num;
	cout<<"the Food's Date: ";
	cin>>fg.Date;
	return is;
}
class ElectricalAppliance:public Goods
{
	char *Color;
public:
	ElectricalAppliance(){Name=new char[20];Num=0;Color=new char[6];Type=3;}
	friend istream &operator >>(istream & is,ElectricalAppliance &eg);
	void ShowMe()
	{	cout<<"Good name: "<<Name<<"  "<<"Good num: "<<Num<<"  "<<"Good color: "<<Color<<endl;}
};
istream &operator >>(istream & is,ElectricalAppliance &eg)
{
	cout<<"the ElectricalAppliance's name: ";
	cin>>eg.Name;
	cout<<"the ElectricalAppliance's num: ";
	cin>>eg.Num;
	cout<<"the ElectricalAppliance's color: ";
	cin>>eg.Color;
	return is;
}
class Supermarket
{	
	int max;
	Goods *good[con];
public:
	Supermarket(){
		max=0;
		for(int i=0;i<con;i++)
			good[i]=NULL;}
	void Add(Goods *,char *,int);
	void Sale();
	void Search();
};
void Supermarket::Add(Goods *xg,char *name,int n)
{
	int i=0,m=0,flag=1;
	while(i<max)
	{
		if(!strcmp(good[i]->getName(),name))
		{   flag=0;
			cout<<"The originally message is"<<endl;
			good[i]->ShowMe();
			m=good[i]->getNum();
			m=m+n;
			good[i]->getNum(m);
			cout<<"The now message is"<<endl;
			good[i]->ShowMe();
		}
		i++;	
	}
	if(flag)
	{	
		good[max]=xg;
		cout<<"The follow good had be Add sucessful!"<<endl;
		good[max]->ShowMe();
		max++;
	}
	cout<<endl;
	return;
}
void Supermarket::Sale()
{
	int i=0,n=0,m=0;
	int flag=1;
	char *name=new char[20];
	cout<<"Input you will saling good's name and num:";
	cin>>name;
	cin>>n;
	while((i<max)&&(flag))
	{
		if(!strcmp(good[i]->getName(),name))
		{   cout<<"The originally message is"<<endl; 
		    good[i]->ShowMe();
			flag=0;
			if(good[i]->getNum()<n)
				cout<<"This good had lack amount!"<<endl;
			else
			{	 m=good[i]->getNum();
				 m=m-n;
				 good[i]->getNum(m);
				 cout<<"The now message is"<<endl;
				 good[i]->ShowMe();
			}
		}
		i++;
	}
	if(flag)
	{cout<<"Not search this good!"<<endl;}
	return;
}
void Supermarket::Search()
{
	int i=0,j=0;
	int type;
	cout<<"What good typr that will you search?"<<endl;
	while(type!=4){
	    cout<<"1.DailyGoods    2.Food    3.ElectricalAppliance    4.exit"<<endl;
		cin>>type;
		switch(type){
		case 1:
			cout<<"The DailyGood message as follow:"<<endl;
			for(j=0;j<max;j++)
			{
				if(good[j]->getType()==1)
					good[j]->ShowMe();
			}
			break;
		case 2:
			cout<<"The Food message as follow:"<<endl;
			for(j=0;j<max;j++)
			{
				if(good[j]->getType()==2)
			        good[j]->ShowMe();

			}
			break;
		case 3:
	    	cout<<"The ElectricalAppliance message as follow:"<<endl;
	    	for(j=0;j<max;j++)
			{
				if(good[j]->getType()==3)
			        good[j]->ShowMe();
			}
			break;
		case 4:
			break;}
	}
	return;
}
void main()
{
	DailyGoods *dago;
	ElectricalAppliance *elap;
	Food *food;
	Supermarket sup;
	int i=0,j=0,k=0;
	cout<<"Welcome into the Supermarket system!"<<endl;
	while(i!=4)
	{
		cout<<"1.Add the Good"<<endl;
		cout<<"2.Sale the Good"<<endl;
		cout<<"3.Search the Good"<<endl;
		cout<<"4.Exit the system"<<endl;
		cout<<"Please input your choice: ";
		cin>>i;
		switch(i)
		{
		case 1:
				while(j!=4){
				cout<<"you will adding:"<<endl;
				cout<<"1.DailyGoods   2.ElectricalApplianc   3.Food   4.exit"<<endl;
				cin>>j;
				switch(j){
				case 1:
					dago=new DailyGoods;
					cin>>*dago;
					sup.Add(dago,dago->getName(),dago->getNum());
					break;
				case 2:
					elap=new ElectricalAppliance;
					cin>>*elap;
					sup.Add(elap,elap->getName(),elap->getNum());
					break;
				case 3:
					food=new Food;
					cin>>*food;
					sup.Add(food,food->getName(),food->getNum());
					break;
				case 4:
					break;}
				}	
			break;
		case 2:
			sup.Sale();
			break;
		case 3:
			sup.Search();
			break;
		case 4:
			break;
		}
		cout<<endl;
	}
}

