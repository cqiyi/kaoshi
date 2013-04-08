/*北大面向对象程序设计上机考试题（9月19日）
建立一个简单的学校人员管理系统，包括对学生、员工和在职学生（既是员工又是学生）的管理。
需要完成如下功能： 
1、建立一个SCHOOL类,在其中定义按照姓名增加人员的APPEND函数，
   删除人员的DELETE的函数和SEARCH的查询函数（以姓名为为准）。 
2、建立一个基类PERSON类，要具有姓名和性别的属性，并把输出函数SHOWME()定义为纯虚函数； 
3、建立一个员工STAFF类和一个学生STUDENT类，均由PERSON继承而来。
   要求可以输出员工类（学生类）对象的属性（姓名、性别和工作证号码（或学生学号），
   分别写出对SHOWME()函数的具体实现。 
4、建立一个在职学生类STAFF_STUDENT类，由员工类和学生类继承而来。
   写出对SHOWME()函数的具体实现，可以输出对象属性，。 
5、重载，实现用CIN为员工类、学生类和在职学生类对象赋值。 
6、编写MAIN（）主函数，测试上述功能，并以菜单方式实现对各种人员的增加、删除和查询（以姓名为线索）。*/
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
class Staff_Student:public Staff,public Student		//这个类的数据应该怎么得到
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
			for(int j=i;j<num-1;j++)			//将找到的删除，将后面的向前移
				school[j]=school[j+1];
			school[j+1]=NULL;					//将最后一个置为空	
			num--;								//总数减少一个
			flag=0;
		}
		else i++;
	/*int id;									//下面是用ID查询，结果正确
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
	int id;									//下面是用ID查询，结果正确
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