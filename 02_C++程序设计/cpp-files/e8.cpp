/*������������������ϻ������⣨9��19�գ�
����һ���򵥵�ѧУ��Ա����ϵͳ��������ѧ����Ա������ְѧ��������Ա������ѧ�����Ĺ���
��Ҫ������¹��ܣ� 
1������һ��SCHOOL��,�����ж��尴������������Ա��APPEND������
   ɾ����Ա��DELETE�ĺ�����SEARCH�Ĳ�ѯ������������ΪΪ׼���� 
2������һ������PERSON�࣬Ҫ�����������Ա�����ԣ������������SHOWME()����Ϊ���麯���� 
3������һ��Ա��STAFF���һ��ѧ��STUDENT�࣬����PERSON�̳ж�����
   Ҫ��������Ա���ࣨѧ���ࣩ��������ԣ��������Ա�͹���֤���루��ѧ��ѧ�ţ���
   �ֱ�д����SHOWME()�����ľ���ʵ�֡� 
4������һ����ְѧ����STAFF_STUDENT�࣬��Ա�����ѧ����̳ж�����
   д����SHOWME()�����ľ���ʵ�֣���������������ԣ��� 
5�����أ�ʵ����CINΪԱ���ࡢѧ�������ְѧ�������ֵ�� 
6����дMAIN�����������������������ܣ����Բ˵���ʽʵ�ֶԸ�����Ա�����ӡ�ɾ���Ͳ�ѯ��������Ϊ��������*/
#include<iostream.h>
#include<string.h>
#include<math.h>
const int con=1000;
class Person
{
protected:				
	int ID;
	char *Name;
	char *Sex;
	char *Type;
public:
	virtual void ShowMe()=0;
	char *GetName(){return Name;}
	int GetID(){return ID;}
};
class Staff:virtual public Person
{
public:
	Staff()
	{
	    ID=0;
		Name=new char[10];
		Sex=new char[2];
		Type="Staff";
	}
	friend istream & operator >> (istream &is,Staff &staff)
	{
		cout<<"Please input Staff message:"<<endl;
		cout<<"Staff ID: ";
		cin>>staff.ID;
		cout<<"Staff Name: ";
		cin>>staff.Name; 
		cout<<"Staff Sex: ";
		cin>>staff.Sex;
		return is;
	}
	void ShowMe()
	{cout<<"ID:"<<ID<<"  "<<"Name:"<<Name<<"  "<<"Sex:"<<Sex<<"  "<<Type<<endl;}
};
class Student:virtual public Person
{
public:
	Student()
	{
		ID=0;
		Name=new char[10];
		Sex=new char[2];
		Type="Student";
	}
	friend istream & operator >> (istream &is,Student &student)
	{
		cout<<"Please input Student message is:"<<endl;
		cout<<"Student ID: ";
		cin>>student.ID;
		cout<<"Student Name: ";
		cin>>student.Name; 
		cout<<"Student Sex: ";
		cin>>student.Sex;
		return is;
	}
	void ShowMe()
	{cout<<"ID:"<<ID<<"  "<<"Name:"<<Name<<"  "<<"Sex:"<<Sex<<"  "<<Type<<endl;}
};
class Staff_Student:public Staff,public Student		//����������Ӧ����ô�õ�
{
public:	
	Staff_Student()
	{
		ID=0;
		Name=new char[10];
		Sex=new char[2];
		Type="Staff_Student";
	}

	friend istream & operator >> (istream &is,Staff_Student &ss)
	{
		cout<<"Please input Staff message is:"<<endl;
		cout<<"Staff_Student ID: ";
		cin>>ss.ID;
		cout<<"Staff_Student Name: ";
		cin>>ss.Name; 
		cout<<"Staff_Student Sex: ";
		cin>>ss.Sex;
		return is;
	}
	void ShowMe()
	{cout<<"ID:"<<ID<<"  "<<"Name:"<<Name<<"  "<<"Sex:"<<Sex<<"  "<<Type<<endl;}
};
class School
{
private:
    int num;
	Person *school[con];
public:
	School(){	
		num=0;
		for(int i=0;i<con;i++)
			school[i]=NULL;}
	void Append(Person *per)
	{
		if(num==con)
		   cout<<"Sorry the datebase is Full!so can not add new member!"<<endl;
		else{
		school[num]=per;
		school[num]->ShowMe();
		num++;
		cout<<"Append successful!"<<endl;}
		return;
	}
	void Delete();
	void Search();
};
void School::Delete()
{
	int flag=1,i=0;							
	char *name=new char[10];						
	cout<<"Please input the name that you will delete"<<endl; 
	cin>>name;		
	while((i<num)&&(flag))
		if(!strcmp(school[i]->GetName(),name))
		{
			for(int j=i;j<num-1;j++)			//���ҵ���ɾ�������������ǰ��
				school[j]=school[j+1];
			school[j+1]=NULL;					//�����һ����Ϊ��	
			num--;								//��������һ��
			flag=0;
		}
		else i++;
	/*int id;									//��������ID��ѯ�������ȷ
	cout<<"Please input the ID that you will delete"<<endl;	
	cin>>id;
	while((i<num)&&(flag)){
		if(school[i]->GetID()==id)
		{
			for(int j=i;j<num-1;j++)		
				school[j]=school[j+1];
			school[j+1]=NULL;				
			num--;		
			flag=0;
		}
		else i++;}*/
	if(flag)
		cout<<"Not search this person!"<<endl; 
	else{
		school[i]->ShowMe();
		cout<<"This record had been delete!"<<endl;}
	return;
}
void School::Search()
{
	int flag=1,i=0;
	/*char *name=new char[10];
	cout<<"Please input the name that you will search"<<endl;
	cin>>name;
	int result;
	result=strcmp(!school[i]->GetName(),name);   
	while((i<num)&&(flag))
	    if(result)
			flag=0;  
		else 
		    i++;*/
	int id;									//��������ID��ѯ�������ȷ
	cout<<"Please input the ID that you will search"<<endl;
	cin>>id;
	while((i<num)&&(flag)){
	    if(school[i]->GetID()==id)
			flag=0;
		else
			i++;}
	if(flag)
		cout<<"Not search this person!"<<endl; 
	else{
		cout<<"The Search result is:"<<endl;
		school[i]->ShowMe();}
	return;
}
void main()
{
	Student *stu;							
	Staff *sta;
	Staff_Student *ss;
	School sh;
	int choice=0,j=0;
	cout<<"Welcom into The school system!"<<endl;
	while(choice!=4)
	{	
		cout<<"1.Append the Student or Staff message"<<endl;
		cout<<"2.Delete the Student or Staff message"<<endl;
		cout<<"3.Search the student or Staff message"<<endl;
		cout<<"4.Exit the system"<<endl;
		cout<<"Please input your choice: ";
		cin>>choice;
		j=0;
		switch(choice){
        case 1:
			cout<<"You will Append:"<<endl;
			cout<<"1.Student   2.Append Staff  3.Append Staff_Student"<<endl;
			cin>>j;
			switch(j){
			case 1:
				stu=new Student;
				cin>>*stu;
				sh.Append(stu);
				break;
			case 2:
				sta=new Staff;
				cin>>*sta;
				sh.Append(sta);
				break;
			case 3:
				ss=new Staff_Student;
				cin>>*ss;
				sh.Append(ss);
				break;}
			break;
		case 2:
			sh.Delete();
			break;
		case 3:
			sh.Search();
			break;
		case 4:
			break;
		}
		cout<<endl;
	}
	return;
}