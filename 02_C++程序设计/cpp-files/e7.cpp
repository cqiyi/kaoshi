/*车库里有10个车位，每个车位可以放不同车型的车辆，包括小客车（Car）和大卡车（Truck），
  但同一时刻一个车位最多只能放1辆车。本题要求完成：
1.实现描述车库的类Garage，包括下列函数增加指定车位中车辆的函数Add（int n, Vehicle vehicle）；
  删除指定车位中车辆的函数Delete（int n）；显示指定车位中车辆的函数Display（int n）
2.定义虚拟基类Vehicle，至少包括纯虚函数ShowMe
3.定义派生类Car和Truck, 具体实现上述纯虚函数ShowMe
4.重载输入“>>”操作符，使得可以通过cin直接读入车辆 
5.编写main函数，测试上述所要求的各种功能*/
#include<iostream.h>
const int Max=10;
class Vehicle
{
protected:
	int VID;
	char *color;
public:
	virtual void ShowMe()=0;
};
class Car:public Vehicle
{
public:
	Car(){VID=0;color=NULL;}
	friend istream& operator >> (istream& is,Car& car);
	void ShowMe();
};
istream& operator >> (istream& is,Car& car)
{
	cout<<endl<<"请输入车的车牌号: ";
	cin>>car.VID;
	cout<<endl<<"************颜色: ";
	car.color=new char[20];
	cin>>car.color;
	return is;
}
void Car::ShowMe()
{
	cout<<endl<<"车辆的车牌号为: "<<VID<<endl;
	cout<<"********颜色为: "<<color<<endl;
}
class Truck:public Vehicle
{
public:
	Truck(){VID=0;color=NULL;}
	friend istream& operator >> (istream& is,Truck& truck);
	void ShowMe();
};
istream& operator >> (istream& is,Truck& truck)
{
	cout<<endl<<"请输入车的车牌号码: ";
	cin>>truck.VID;
	cout<<endl<<"**************颜色: ";
	truck.color=new char[20];
	cin>>truck.color;
	return is;
}
void Truck::ShowMe()
{
	cout<<endl<<"车辆的车牌号为: "<<VID<<endl;
	cout<<"********颜色为: "<<color<<endl;
}
class Garage
{
private:
	Vehicle *garage[Max+1];
public:
	Garage(){for(int i=1;i<=Max;i++) garage[i]=NULL;}
	void Add(int n,Vehicle *vehicle);
	void Delete(int n);
	void Display(int n);
};
void Garage::Add(int n,Vehicle *vehicle)
{
	if(garage[n]!=NULL)
		cout<<endl<<"该车位已停有车辆!请选择别的车位!"<<endl;
	else{
		garage[n]=vehicle;
		cout<<endl<<"      车辆已成功停入车位!"<<endl;
	}
	return;
}
void Garage::Delete(int n)
{
	if(garage[n]==NULL)
		cout<<endl<<"该车位没有车辆!"<<endl;
	else{
		garage[n]->ShowMe();
		garage[n]=NULL;
		cout<<endl<<"       该车辆成功开走!"<<endl;
	}
	return;
}
void Garage::Display(int n)
{
	if(garage[n]==NULL)
		cout<<endl<<"该车位没有车辆!"<<endl;
	else{
		garage[n]->ShowMe();
	}
	return;
}
void main()
{
	Garage gar;
	Car *car;
	Truck *tru;
	int chioce,i,j;
	cout<<endl<<"**************欢迎进入车库管理系统**************"<<endl;
	while(chioce!=4)
	{
		cout<<endl; 
		cout<<"1.停车        2.取车        3.查询        4.退出"<<endl;
		cin>>chioce;
		switch(chioce)
		{
		case 1:
			cout<<endl<<"请选择您要停的车位(1-10): ";cin>>j;
			while(j<1||j>10){
				cout<<endl<<"对不起!本车库没有"<<j<<"号车位,请重新输入!"<<endl;
				cin>>j;
			}
			cout<<endl<<"您要停的车辆是(1.停小车  2.卡车):  ";
			cin>>i;
			if(i==1){
				car=new Car;
				cin>>*car;
				gar.Add(j,car);
			}
			else if(i==2){
				tru=new Truck;
				cin>>*tru;
				gar.Add(j,tru);
			}
				else cout<<endl<<"     输入错误!"<<endl;
			break;
		case 2:
			cout<<endl<<"请选择您要离开的车位(1-10): ";cin>>j;
			while(j<1||j>10){
				cout<<endl<<"对不起!本车库没有"<<j<<"号车位,请重新输入!"<<endl;
				cin>>j;
			}
			gar.Delete(j);
			break;
		case 3:
			cout<<endl<<"请选择您要查询的车位(1-10): ";cin>>j;
			while(j<1||j>10){
				cout<<endl<<"对不起!本车库没有"<<j<<"号车位,请重新输入!"<<endl;
				cin>>j;
			}
			gar.Display(j);
			break;
		case 4:
			break;
		}
	}
	cout<<endl<<"     谢谢使用本系统!"<<endl;
}