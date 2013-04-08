/*
超市商品管理系统
*/

#include <iostream>
#include <string>
using namespace std;

#define MAX 100
#define SUCCESS 0

//typedef char string[255];

//商品类Goods，包含属性名称、和商品现有数量，以及纯虚函数ShowMe
class Goods 
{ 
public: 
	virtual void ShowMe () = 0; 
	//名称
	string Name;
	//现有数量
	int Num;
}; 


//日常用品
class DialyGoods:public Goods{
public:
	DialyGoods(){}

	DialyGoods(string name, int num){
		Name = name;
		Num = num;
	}

	void Add(int num){
		Num += num;
	}

	friend istream& operator>>(istream& is, DialyGoods& item){
		cout<<"Input DialyGoods(Name, Num):"<<endl;
		is>>item.Name>>item.Num;
		return is;
	}

	void ShowMe(){
		cout<<"DialyGoods(Name:"<<Name<<", Num:"<<Num<<")"<<endl;
	}
};

//食品
class Food:public Goods{
private:
	//保质期
	string _life;
public:	
	Food(){}

	Food(string name, int num, string life){
		Name = name;
		Num = num;
		_life = life;
	}

	void Add(int num){
		Num += num;
	}

	friend istream& operator>>(istream& is, Food& item){
		cout<<"Input Food(Name, Num, Life):"<<endl;
		is>>item.Name>>item.Num>>item._life;
		return is;
	}

	void ShowMe(){
		cout<<"Food(Name:"<<Name<<", Num:"<<Num<<", Life:"<<_life<<")"<<endl;
	}
};

//家电
class ElectricalAppliance:public Goods{
private:
	//颜色
	string _color;
public:
	ElectricalAppliance(){}

	ElectricalAppliance(string name, int num, string color){
		Name = name;
		Num = num;
		_color = color;
	}

	void Add(int num){
		Num += num;
	}

	friend istream& operator>>(istream& is, ElectricalAppliance& item){
		cout<<"Input ElectricalAppliance(Name, Num, Color):"<<endl;
		is>>item.Name>>item.Num>>item._color;
		return is;
	}

	void ShowMe(){
		cout<<"ElectricalAppliance(Name:"<<Name<<", Num:"<<Num<<", Color:"<<_color<<")"<<endl;
	}

	friend ostream& operator<<(ostream& os, ElectricalAppliance& item){
		cout<<"xxxxxxxxxx"<<endl;
		os<<"ElectricalAppliance(Name:"<<item.Name<<", Num:"<<item.Num<<", Color:ERROR)"<<endl;
		return os;
	}
};

class Supermarket{
private:
	Goods* item[MAX];
	int count;
	int _get(string name){
		for(int i=0; i<count; i++){
			if(item[i]->Name == name){
				return i;
			}
		}
		cout<<"未找到商品:"<<name<<endl;
		return -1;
	};
public:
	void Add(Goods* g){
		item[count++] = g;
	}

	void Add(string name, int num){
		int i = _get(name);
		if(i>=0){
			item[i]->Num += num;
		}
	}

	void Sale(string name, int num){
		int i = _get(name);
		if(i<0) return;
		if(item[i]->Num >= num){
			item[i]->Num -= num;
		}
		else{
			cout<<"卖出失败, 现有商品数量不足。"<<endl;
		}
	}

	void Search(){
		cout<<"Supermarket.Search:"<<endl;
		for(int i=0; i<count; i++){
			item[i]->ShowMe();
		}
	}
	Supermarket(){
		count =0;
	}
};

int main(){
	char choice;
	Supermarket market = Supermarket();
	while(true){
		system("cls");
		cout<<"超市商品管理系统"<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"  1、 增加日常用品"<<endl;
		cout<<"  2、 增加食品"<<endl;
		cout<<"  3、 增加家电"<<endl;
		cout<<"  4、 增加商品数量"<<endl;
		cout<<"  5、 卖出"<<endl;
		cout<<"  6、 查询"<<endl;
		cout<<"  0、 退出"<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"请选择[0~5]:";
		cin>>choice;
		switch(choice){
		case '1'://增加日常用品
			{
				DialyGoods* dialyGoods = new DialyGoods();
				cin>>*dialyGoods;
				market.Add(dialyGoods);
				break;
			}
		case '2'://增加食品
			{
				Food* food = new Food();
				cin>>*food;
				market.Add(food);
				cout<<food;
				break;
			}
		case '3'://增加家电
			{
				ElectricalAppliance* electricalAppliance = new ElectricalAppliance();
				cin>>*electricalAppliance;
				market.Add(electricalAppliance);
				cout<<*electricalAppliance;
				break;
			}
		case '4'://增加商品数量
			{
				string myname;
				int mynum;
				cout<<"输入要增加的商品(Name, Num):"<<endl;
				cin>>myname>>mynum;
				market.Add(myname, mynum);
				break;
			}
		case '5'://卖出
			{
				string myname;
				int mynum;
				cout<<"输入要卖出的商品(Name, Num):"<<endl;
				cin>>myname>>mynum;
				market.Sale(myname, mynum);
				break;
			}
		case '6'://查询
			{
				market.Search();
				break;
			}
		case '0':
			return SUCCESS;
		default:
			{
				cout<<"输入错误."<<endl;
				break;
			}
		}
		cout<<endl;
		system("pause");
	}
}