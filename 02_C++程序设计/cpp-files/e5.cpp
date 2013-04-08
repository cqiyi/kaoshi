/*����������12�����ӣ�ÿ�����ӿ��ԷŲ�ͬ�Ķ������èCat����Dog����Snake����ͬһʱ��һ����������ܷ�1ֻ���Ҫ��
1.ʵ��һ�����׵Ĺ���ϵͳ���������ӡ�ɾ��ָ�������еĳ��
  ��ѯÿ�������д�ų�����������������Ϊ�յ��������ͳ�Ƴ���������������
2.�������������ݵ���Shelves, ������12���������ڴ�Ÿ��ֳ��
3.�����������Animal�����ٰ������麯��ShowMe��
4.����������Cat��Dog��Snake������ʵ���������麯��ShowMe����ʾ�ó�������ࡢ���ơ���ɫ�����غ�ϲ����ʳ�
5.�������롰>>����������ʹ�ÿ���ͨ��cinֱ�Ӷ��������ɫ�����غ�ϲ����ʳ�
6.��дmain����������������Ҫ��ĸ��ֹ��ܡ�*/
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
	cout<<"��������������: ";cin>>cat.name;
	cout<<"************��ɫ: ";cin>>cat.color;
	cout<<"************����: ";cin>>cat.weigh;
	cout<<"******ϲ����ʳ��: ";cin>>cat.favor;
	return is;
}
void Cat::ShowMe()
{
	cout<<endl;
	cout<<"����è����Ϣ"<<endl;
	cout<<"���������: "<<name<<endl;
	cout<<"******��ɫ: "<<color<<endl;
	cout<<"******����: "<<weigh<<endl;
	cout<<"ϲ����ʳ��: "<<favor<<endl;
}
int Dog::dognum=0;
istream& operator >> (istream& is,Dog& dog)
{
	cout<<"��������������: ";cin>>dog.name;
	cout<<"************��ɫ: ";cin>>dog.color;
	cout<<"************����: ";cin>>dog.weigh;
	cout<<"******ϲ����ʳ��: ";cin>>dog.favor;
	return is;
}
void Dog::ShowMe()
{
	cout<<endl;
	cout<<"���ﹷ����Ϣ"<<endl;
	cout<<"���������: "<<name<<endl;
	cout<<"******��ɫ: "<<color<<endl;
	cout<<"******����: "<<weigh<<endl;
	cout<<"ϲ����ʳ��: "<<favor<<endl;

}
int Snake::snakenum=0;
istream& operator >> (istream& is,Snake& snake)
{
	cout<<"��������������: ";cin>>snake.name;
	cout<<"************��ɫ: ";cin>>snake.color;
	cout<<"************����: ";cin>>snake.weigh;
	cout<<"******ϲ����ʳ��: ";cin>>snake.favor;
	return is;
}
void Snake::ShowMe()
{
	cout<<endl;
	cout<<"�����ߵ���Ϣ"<<endl;
	cout<<"���������: "<<name<<endl;
	cout<<"******��ɫ: "<<color<<endl;
	cout<<"******����: "<<weigh<<endl;
	cout<<"ϲ����ʳ��: "<<favor<<endl;
}
void Shelves::Append()
{
	int no,t;
	cout<<endl<<"������Ҫ��ӳ������ı��(1--12): ";cin>>no;
	no--;
	if(cage[no]!=NULL||no>=12)
		cout<<endl<<"���������Ѿ��г���,������ѡ������."<<endl;
	else{
		cout<<endl<<"������Ҫ��ӳ��������(0. è 1.�� 2.��): ";
		cin>>t;
		if(t==0){
			Cat *cat;
			cat=new Cat;
			cin>>*cat;
			cage[no]=cat;
			cage[no]->AddNum();
			cout<<endl<<"     ������ӳɹ�!"<<endl;
		}
		else if(t==1){
			Dog *dog;
			dog=new Dog;
			cin>>*dog;
			cage[no]=dog;
			cage[no]->AddNum();
			cout<<endl<<"     ������ӳɹ�!"<<endl;
		}
			 else if(t==2){
				 Snake *snake=new Snake;
				 cin>>*snake;
				 cage[no]=snake;
				 cage[no]->AddNum();
				 cout<<endl<<"     ������ӳɹ�!"<<endl;
		}
		          else
						return;
	}

}
void Shelves::Delete()
{
	int no;
	cout<<endl<<"������Ҫɾ���������ı��(1--12): ";cin>>no;
	no--;
	if(cage[no]==NULL)
		cout<<endl<<"���������Ѿ�û�г�����!"<<endl;
	else if(no>=12)
		cout<<endl<<"�����Ӳ�����!"<<endl;
	else{
			cage[no]->DeleteNum();
			cage[no]=NULL;
			cout<<endl<<"�ó���ɹ�����!"<<endl;
	}
	return;
}
void Shelves::Query()
{
	int no;
	cout<<endl<<"������Ҫ��ѯ���ӵı��(1-12): ";cin>>no;
	no--;
	if(cage[no]==NULL)
		cout<<endl<<"�������ǿյ�!"<<endl;
	else if(no>=12||no<0)
			cout<<endl<<"�����Ӳ�����!"<<endl;
		else
			cage[no]->ShowMe();
	return;
}
void Shelves::Stat()
{
	Cat cat;
	Dog dog;
	Snake snake;
	cout<<endl<<"����������"<<endl;
	cout<<"******è: "<<cat.Getcatnum()<<"ֻ"<<endl;
	cout<<"******��: "<<dog.Getdognum()<<"ֻ"<<endl;
	cout<<"******��: "<<snake.Getsnakenum()<<"ֻ"<<endl;
}
void main()
{
	Shelves shelves;
	int chioce;
	cout<<endl<<"********************��ϵͳ�ṩ���¹���********************"<<endl;
	while(chioce!=5)
	{
		cout<<endl;
		cout<<"1.�������   2.�������   3.��ѯ����   4.ͳ�Ƴ���   5.�˳�"<<endl;
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
