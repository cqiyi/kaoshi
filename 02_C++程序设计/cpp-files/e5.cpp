/*宠物屋里有12个笼子，每个笼子可以放不同的动物，包括猫Cat、狗Dog和蛇Snake，但同一时刻一个笼子最多能放1只宠物，要求：
1.实现一个简易的管理系统，可以增加、删除指定笼子中的宠物，
  查询每个笼子中存放宠物的情况（包括笼子为空的情况），统计宠物的种类和数量；
2.定义描述宠物屋的类Shelves, 其中有12个笼子用于存放各种宠物；
3.定义虚拟基类Animal，至少包括纯虚函数ShowMe；
4.定义派生类Cat、Dog和Snake，具体实现上述纯虚函数ShowMe，显示该宠物的种类、名称、颜色、体重和喜爱的食物；
5.重载输入“>>”操作符，使得可以通过cin直接读入宠物颜色、体重和喜爱的食物；
6.编写main函数，测试上述所要求的各种功能。*/
#include<iostream.h>
class Animal
{
protected:
	int type;
	char *name;
	char *color;
	int weigh;
	char *favor;
public:
	virtual void AddNum()=0;
	virtual void DeleteNum()=0;
	virtual void ShowMe()=0;
};
class Cat:public Animal
{
private:
	static int catnum;
public:
	Cat(){
		type=0;
		name=new char[20];
		color=new char[20];
		weigh=0;
		favor=new char[20];
	}
	void AddNum(){catnum++;}
	int Getcatnum(){return catnum;}
	void DeleteNum(){catnum--;}
	friend istream& operator >> (istream& is,Cat& cat);
	void ShowMe();
};
class Dog:public Animal
{
private:
	static int dognum;
public:
	Dog(){
		type=1;
		name=new char[20];
		color=new char[20];
		weigh=0;
		favor=new char[20];
	}
	void AddNum(){dognum++;}
	int Getdognum(){return dognum;}
	void DeleteNum(){dognum--;}
	friend istream& operator >> (istream& is,Dog& dog);
	void ShowMe();
};
class Snake:public Animal
{
private:
	static int snakenum;
public:
	Snake(){
		type=2;
		name=new char[20];
		color=new char[20];
		weigh=0;
		favor=new char[20];
	}
	void AddNum(){snakenum++;}
	int Getsnakenum(){return snakenum;}
	void DeleteNum(){snakenum--;}
	friend istream& operator >> (istream& is,Snake& snake);
	void ShowMe();
};
class Shelves 
{
private:
	Animal *cage[12];
public:
	Shelves()
{
		for(int i=0;i<12;i++)
			cage[i]=NULL;
	}
	void Append();
	void Delete();
	void Query();
	void Stat();
};
int Cat::catnum=0;
istream& operator >> (istream& is,Cat& cat)
{
	cout<<"请输入宠物的名称: ";cin>>cat.name;
	cout<<"************颜色: ";cin>>cat.color;
	cout<<"************体重: ";cin>>cat.weigh;
	cout<<"******喜爱的食物: ";cin>>cat.favor;
	return is;
}
void Cat::ShowMe()
{
	cout<<endl;
	cout<<"宠物猫的信息"<<endl;
	cout<<"宠物的名称: "<<name<<endl;
	cout<<"******颜色: "<<color<<endl;
	cout<<"******体重: "<<weigh<<endl;
	cout<<"喜爱的食物: "<<favor<<endl;
}
int Dog::dognum=0;
istream& operator >> (istream& is,Dog& dog)
{
	cout<<"请输入宠物的名称: ";cin>>dog.name;
	cout<<"************颜色: ";cin>>dog.color;
	cout<<"************体重: ";cin>>dog.weigh;
	cout<<"******喜爱的食物: ";cin>>dog.favor;
	return is;
}
void Dog::ShowMe()
{
	cout<<endl;
	cout<<"宠物狗的信息"<<endl;
	cout<<"宠物的名称: "<<name<<endl;
	cout<<"******颜色: "<<color<<endl;
	cout<<"******体重: "<<weigh<<endl;
	cout<<"喜爱的食物: "<<favor<<endl;

}
int Snake::snakenum=0;
istream& operator >> (istream& is,Snake& snake)
{
	cout<<"请输入宠物的名称: ";cin>>snake.name;
	cout<<"************颜色: ";cin>>snake.color;
	cout<<"************体重: ";cin>>snake.weigh;
	cout<<"******喜爱的食物: ";cin>>snake.favor;
	return is;
}
void Snake::ShowMe()
{
	cout<<endl;
	cout<<"宠物蛇的信息"<<endl;
	cout<<"宠物的名称: "<<name<<endl;
	cout<<"******颜色: "<<color<<endl;
	cout<<"******体重: "<<weigh<<endl;
	cout<<"喜爱的食物: "<<favor<<endl;
}
void Shelves::Append()
{
	int no,t;
	cout<<endl<<"请输入要添加宠物笼的编号(1--12): ";cin>>no;
	no--;
	if(cage[no]!=NULL||no>=12)
		cout<<endl<<"该笼子中已经有宠物,请重新选择笼子."<<endl;
	else{
		cout<<endl<<"请输入要添加宠物的种类(0. 猫 1.狗 2.蛇): ";
		cin>>t;
		if(t==0){
			Cat *cat;
			cat=new Cat;
			cin>>*cat;
			cage[no]=cat;
			cage[no]->AddNum();
			cout<<endl<<"     宠物添加成功!"<<endl;
		}
		else if(t==1){
			Dog *dog;
			dog=new Dog;
			cin>>*dog;
			cage[no]=dog;
			cage[no]->AddNum();
			cout<<endl<<"     宠物添加成功!"<<endl;
		}
			 else if(t==2){
				 Snake *snake=new Snake;
				 cin>>*snake;
				 cage[no]=snake;
				 cage[no]->AddNum();
				 cout<<endl<<"     宠物添加成功!"<<endl;
		}
		          else
						return;
	}

}
void Shelves::Delete()
{
	int no;
	cout<<endl<<"请输入要删除宠物笼的编号(1--12): ";cin>>no;
	no--;
	if(cage[no]==NULL)
		cout<<endl<<"该笼子中已经没有宠物了!"<<endl;
	else if(no>=12)
		cout<<endl<<"该笼子不存在!"<<endl;
	else{
			cage[no]->DeleteNum();
			cage[no]=NULL;
			cout<<endl<<"该宠物成功出笼!"<<endl;
	}
	return;
}
void Shelves::Query()
{
	int no;
	cout<<endl<<"请输入要查询笼子的编号(1-12): ";cin>>no;
	no--;
	if(cage[no]==NULL)
		cout<<endl<<"该笼子是空的!"<<endl;
	else if(no>=12||no<0)
			cout<<endl<<"该笼子不存在!"<<endl;
		else
			cage[no]->ShowMe();
	return;
}
void Shelves::Stat()
{
	Cat cat;
	Dog dog;
	Snake snake;
	cout<<endl<<"宠物屋中有"<<endl;
	cout<<"******猫: "<<cat.Getcatnum()<<"只"<<endl;
	cout<<"******狗: "<<dog.Getdognum()<<"只"<<endl;
	cout<<"******蛇: "<<snake.Getsnakenum()<<"只"<<endl;
}
void main()
{
	Shelves shelves;
	int chioce;
	cout<<endl<<"********************本系统提供以下功能********************"<<endl;
	while(chioce!=5)
	{
		cout<<endl;
		cout<<"1.宠物进笼   2.宠物出笼   3.查询宠物   4.统计宠物   5.退出"<<endl;
		cin>>chioce;
		switch(chioce)
		{
		case 1:
			shelves.Append();
			break;
		case 2:
			shelves.Delete();
			break;
		case 3:
			shelves.Query();
			break;
		case 4:
			shelves.Stat();
			break;
		case 5:
			break;
		}
	}
	return;
}
