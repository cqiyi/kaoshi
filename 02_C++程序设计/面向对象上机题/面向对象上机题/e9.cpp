/*������ѧ�����Ӧ��רҵ��ϵͳ�ࣨҵ�ࣩ2001��10�·���������ϻ�������
��ʵ��һ���򵥵ĳ�����Ʒ����ϵͳ���������������ܣ��ֱ�����ճ���Ʒ��ʳƷ�ͼҵ硣����Ҫ����ɣ� 
(1) ʵ���������е���Supermarket�����ж�����������Ʒ�ĺ���Add�����������µ���Ʒ��Ҳ��������������Ʒ����������
    ����//��Ʒ����//������Ʒ�ĺ���Sale�������Ʒ�������������������������ܼ���������Ʒ����������ʾ��Ϣ����
	����//��Ʒ���//��ѯ��Ʒ����ĺ���Search������ʾ��ѯ�����ÿ����Ʒ������Щ��Ʒ��ÿ����Ʒ�����ƺ������������� 
(2) ������Ʒ��Goods�������������ơ�����Ʒ�����������Լ����麯��ShowMe�� 
(3) �ӻ���Goods�������ճ���Ʒ��DailyGoods��ʳƷ��Food�ͼҵ���ElectricalAppliance��
    ����ʳƷ����Ʒӵ�б��������ԣ��ҵ�����Ʒӵ����ɫ���ԣ�����ʵ���������麯��ShowMe��
	��ʾ��Ʒ�����ơ�����������ʳƷ����Ʒ�ı����ڣ��Լ��ҵ�����Ʒ����ɫ�� 
(4) �������롰>>��*������ʹ�ÿ���ͨ��cinֱ�Ӷ��������ճ���Ʒ�ࡢʳƷ��ͼҵ���Ķ���ֵ�� 
(5) ��дmain����������������Ҫ��ĸ��ֹ��ܣ������Ը��ݲ˵��������ӡ������Ͳ�ѯ������Ʒ��
    ���е���Ʒ�������ճ���Ʒ��ʳƷ�ͼ��õ����� 
��ʾ�� 
�������Goods�Ķ������ٰ������´��麯��ShowMe�� 
class Goods 
{ 
// ���� 
public: 
virtual void ShowMe () = 0; 
// ���� 
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

