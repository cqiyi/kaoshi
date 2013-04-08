/*
������Ʒ����ϵͳ
*/

#include <iostream>
#include <string>
using namespace std;

#define MAX 100
#define SUCCESS 0

//typedef char string[255];

//��Ʒ��Goods�������������ơ�����Ʒ�����������Լ����麯��ShowMe
class Goods 
{ 
public: 
	virtual void ShowMe () = 0; 
	//����
	string Name;
	//��������
	int Num;
}; 


//�ճ���Ʒ
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

//ʳƷ
class Food:public Goods{
private:
	//������
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

//�ҵ�
class ElectricalAppliance:public Goods{
private:
	//��ɫ
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
		cout<<"δ�ҵ���Ʒ:"<<name<<endl;
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
			cout<<"����ʧ��, ������Ʒ�������㡣"<<endl;
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
		cout<<"������Ʒ����ϵͳ"<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"  1�� �����ճ���Ʒ"<<endl;
		cout<<"  2�� ����ʳƷ"<<endl;
		cout<<"  3�� ���Ӽҵ�"<<endl;
		cout<<"  4�� ������Ʒ����"<<endl;
		cout<<"  5�� ����"<<endl;
		cout<<"  6�� ��ѯ"<<endl;
		cout<<"  0�� �˳�"<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"��ѡ��[0~5]:";
		cin>>choice;
		switch(choice){
		case '1'://�����ճ���Ʒ
			{
				DialyGoods* dialyGoods = new DialyGoods();
				cin>>*dialyGoods;
				market.Add(dialyGoods);
				break;
			}
		case '2'://����ʳƷ
			{
				Food* food = new Food();
				cin>>*food;
				market.Add(food);
				cout<<food;
				break;
			}
		case '3'://���Ӽҵ�
			{
				ElectricalAppliance* electricalAppliance = new ElectricalAppliance();
				cin>>*electricalAppliance;
				market.Add(electricalAppliance);
				cout<<*electricalAppliance;
				break;
			}
		case '4'://������Ʒ����
			{
				string myname;
				int mynum;
				cout<<"����Ҫ���ӵ���Ʒ(Name, Num):"<<endl;
				cin>>myname>>mynum;
				market.Add(myname, mynum);
				break;
			}
		case '5'://����
			{
				string myname;
				int mynum;
				cout<<"����Ҫ��������Ʒ(Name, Num):"<<endl;
				cin>>myname>>mynum;
				market.Sale(myname, mynum);
				break;
			}
		case '6'://��ѯ
			{
				market.Search();
				break;
			}
		case '0':
			return SUCCESS;
		default:
			{
				cout<<"�������."<<endl;
				break;
			}
		}
		cout<<endl;
		system("pause");
	}
}