/*��������10����λ��ÿ����λ���ԷŲ�ͬ���͵ĳ���������С�ͳ���Car���ʹ󿨳���Truck����
  ��ͬһʱ��һ����λ���ֻ�ܷ�1����������Ҫ����ɣ�
1.ʵ�������������Garage���������к�������ָ����λ�г����ĺ���Add��int n, Vehicle vehicle����
  ɾ��ָ����λ�г����ĺ���Delete��int n������ʾָ����λ�г����ĺ���Display��int n��
2.�����������Vehicle�����ٰ������麯��ShowMe
3.����������Car��Truck, ����ʵ���������麯��ShowMe
4.�������롰>>����������ʹ�ÿ���ͨ��cinֱ�Ӷ��복�� 
5.��дmain����������������Ҫ��ĸ��ֹ���*/
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
	cout<<endl<<"�����복�ĳ��ƺ�: ";
	cin>>car.VID;
	cout<<endl<<"************��ɫ: ";
	car.color=new char[20];
	cin>>car.color;
	return is;
}
void Car::ShowMe()
{
	cout<<endl<<"�����ĳ��ƺ�Ϊ: "<<VID<<endl;
	cout<<"********��ɫΪ: "<<color<<endl;
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
	cout<<endl<<"�����복�ĳ��ƺ���: ";
	cin>>truck.VID;
	cout<<endl<<"**************��ɫ: ";
	truck.color=new char[20];
	cin>>truck.color;
	return is;
}
void Truck::ShowMe()
{
	cout<<endl<<"�����ĳ��ƺ�Ϊ: "<<VID<<endl;
	cout<<"********��ɫΪ: "<<color<<endl;
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
		cout<<endl<<"�ó�λ��ͣ�г���!��ѡ���ĳ�λ!"<<endl;
	else{
		garage[n]=vehicle;
		cout<<endl<<"      �����ѳɹ�ͣ�복λ!"<<endl;
	}
	return;
}
void Garage::Delete(int n)
{
	if(garage[n]==NULL)
		cout<<endl<<"�ó�λû�г���!"<<endl;
	else{
		garage[n]->ShowMe();
		garage[n]=NULL;
		cout<<endl<<"       �ó����ɹ�����!"<<endl;
	}
	return;
}
void Garage::Display(int n)
{
	if(garage[n]==NULL)
		cout<<endl<<"�ó�λû�г���!"<<endl;
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
	cout<<endl<<"**************��ӭ���복�����ϵͳ**************"<<endl;
	while(chioce!=4)
	{
		cout<<endl; 
		cout<<"1.ͣ��        2.ȡ��        3.��ѯ        4.�˳�"<<endl;
		cin>>chioce;
		switch(chioce)
		{
		case 1:
			cout<<endl<<"��ѡ����Ҫͣ�ĳ�λ(1-10): ";cin>>j;
			while(j<1||j>10){
				cout<<endl<<"�Բ���!������û��"<<j<<"�ų�λ,����������!"<<endl;
				cin>>j;
			}
			cout<<endl<<"��Ҫͣ�ĳ�����(1.ͣС��  2.����):  ";
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
				else cout<<endl<<"     �������!"<<endl;
			break;
		case 2:
			cout<<endl<<"��ѡ����Ҫ�뿪�ĳ�λ(1-10): ";cin>>j;
			while(j<1||j>10){
				cout<<endl<<"�Բ���!������û��"<<j<<"�ų�λ,����������!"<<endl;
				cin>>j;
			}
			gar.Delete(j);
			break;
		case 3:
			cout<<endl<<"��ѡ����Ҫ��ѯ�ĳ�λ(1-10): ";cin>>j;
			while(j<1||j>10){
				cout<<endl<<"�Բ���!������û��"<<j<<"�ų�λ,����������!"<<endl;
				cin>>j;
			}
			gar.Display(j);
			break;
		case 4:
			break;
		}
	}
	cout<<endl<<"     ллʹ�ñ�ϵͳ!"<<endl;
}