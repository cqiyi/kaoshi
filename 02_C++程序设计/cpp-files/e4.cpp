/*请实现一个简单的银行储蓄系统，承担活期用户的存款和取款业务，要求如下：
1.实现描述银行的类Bank，记录系统中现有哪些储户(可用数组实现，但注意判断数组越界的情况)，
  定义生成储户的函数Append，按照帐号删除储户的函数Delete，按照帐号查询储户的函数Query，并显示查询结果；
2.定义储户类Account，具有帐号、存款人姓名和余额等属性，操作Saving（处理存款业务）、
  Withdraw（处理取款业务，余额不足时不予取款并给出提示）和ShowMe（显示储户所有信息）。
3.编写main函数，测试以上所要求的各种功能，即可以根据菜单命令增加、删除和查询储户，以及储户存款和取款的操作。*/
#include<iostream.h>
#include<string.h>
class Account
{
private:
	int ID;
	char Name[20];
	float Balance;
public:
	Account(){}
	Account(int id,char *name,float balance)
	{
		ID=id;
		strcpy(Name,name);
		Balance=balance;
	}
	int GetID(){return ID;}
	void Saving();
	void Withdraw();
	void ShowMe();
};
void Account::ShowMe()
{
	cout<<endl<<"该帐户信息如下: "<<endl<<endl;
	cout<<"********帐号为: "<<ID<<endl;
	cout<<"********姓名为: "<<Name<<endl;
	cout<<"********余额为: "<<Balance<<endl;
	return;
}
void Account::Saving()
{
	int money;
	cout<<endl<<"请输入要存入的金额: ";
	cin>>money;
	Balance+=money;
	cout<<endl<<"您的帐户余额为: "<<Balance<<endl<<endl;
	return;
}
void Account::Withdraw()
{
	int money;
	cout<<endl<<"请出入要取款的金额: ";
	cin>>money;
	while(money>Balance){
		cout<<endl<<"余额不足!请重新输入要取款的金额: ";
		cin>>money;
	}
	Balance-=money;
	cout<<endl<<"您的帐户余额为: "<<Balance<<endl<<endl;
	return;
}
class Bank
{
private:
	int NewID;
	int k;
	Account account[20];
public:
	Bank(){NewID=1100;k=0;}
	void Append();
	void Delete();
	void Query();
};
void Bank::Append()
{
	NewID=NewID+2;
	if(k==20){
		cout<<"增加新帐户失败！系统帐户已满！"<<endl;
	}
	else{
	int id=NewID;
	char name[20];
	float init;
	cout<<"请输入新帐户的姓名: ";cin>>name;
	cout<<"请输入帐户初始金额: ";cin>>init;
	Account newaccount(NewID,name,init);
	account[k]=newaccount;
	k++;
	cout<<endl<<"     新建帐户成功!"<<endl;
	newaccount.ShowMe();
	}
	return;
}
void Bank::Delete()
{
	int id;
	cout<<"请输入要删除帐户的帐号: ";
	cin>>id;
	for(int i=0;i<k;i++)
		if(account[i].GetID()==id)
			break;
	if(i==k)
		cout<<endl<<"   对不起!查无此帐户!"<<endl;
	else{
		for(int j=i;j<k;j++)
			account[j]=account[j+1];
		k--;
		cout<<endl<<"     成功删除此帐户!"<<endl;
	}
	return;
}
void Bank::Query()
{
	int id,chioce;
	cout<<"请输入要查询帐户的帐号: ";
	cin>>id;
	for(int i=0;i<k;i++)
		if(account[i].GetID()==id)
			break;
	if(i==k)
		cout<<endl<<"   对不起!查无此帐户!"<<endl;
	else{
		account[i].ShowMe();
		while(chioce!=3)
		{
			cout<<endl<<"      请选择您的操作"<<endl<<endl;
			cout<<"1.存款    2.取款   3.退出"<<endl;
			cin>>chioce;
			switch(chioce)
			{
			case 1:
				account[i].Saving();
				break;
			case 2:
				account[i].Withdraw();
				break;
			case 3:
				break;
			}
		}
	}
	return;
}
void main()
{
	Bank bank;
	int chioce;
	cout<<endl<<"************本系统提供以下功能**************"<<endl<<endl;
	while(chioce!=4)
	{
		cout<<endl;
		cout<<"1.增加新帐户  2.删除帐户  3.查询帐户  4.退出"<<endl;
		cin>>chioce;
		switch(chioce)
		{
		case 1:
			bank.Append();
			break;
		case 2:
			bank.Delete();
			break;
		case 3:
			bank.Query();
			break;
		case 4:
			break;
		default:
			break;
		}
	}
	cout<<endl<<"     谢谢使用本系统!"<<endl<<endl;
}