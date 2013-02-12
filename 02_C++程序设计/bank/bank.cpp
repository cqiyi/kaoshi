#include<iostream>
#include<cstring>

#include"bank.h"
using std::cout;
using std::cin;
using std::endl;
Account::Account()
{
	ID=0;
	strcpy(name,"");
	balance=0;


}
Account::Account(int id,const char *names,double balances)
{
	ID=id;
	name=new char[50];
	strcpy(name,names);
	balance=balances;
}
void Account::saving()
{
	double number;
	cout<<"please input saving number: ";
	cin>>number;
	balance=balance+number;
	cout<<"now the balance of your account is "<<balance <<endl;
	return ;
	

} 
int Account::withdrow()
{
	double number;

	cout<<" please input withdraw number:";
	cin>>number;
	if(balance<number)
	{
		cout<<"sorry,now thd balance of your account is less than "<<number;
		cout<<"."<<endl<<"so you can not withdraw !"<<endl;
		return 0;
	}
	balance =balance-number;
	cout<<"now the balance of your account is "<<balance<<endl;
	return 1;


}
void Account::showme()
{
	cout<<" account ID: "<<ID<<endl;
	cout<<"name: "<<name<<endl;
	cout<<"balance: "<<balance<<endl;
	return ;



}
int Account::getID()
{
	return ID;

}
Bank::Bank()
{
	for(int i =0;i<50;i++)
		account[i]=NULL;
	maxID=0;
	accnum=0;



}
void Bank::append()
{
	if(accnum==50)
	{
		cout<<" sorry,the bank is full ,so can not add new account!"<<endl;
		return ;

	}
	int id;
	char *names=new char [50];
	double balance;
	cout<<endl<<"please input the name of the account: ";
	cin>>names;
	id=maxID;
	balance=0;
	Account *acc=new Account(id,names,balance);
	account[accnum]=acc;
	cout<<"append successful "<<endl;
	account[accnum]->showme();
	maxID++;
	accnum++;
	return ;


}
void Bank::deletes()
{
	int ID;
	cout<<" please input the account ID that you want to delete";
	cin>>ID;
	int flag=1;
	int i=0;
	while ((i<accnum)&&(flag))
	{
		if(ID==account[i]->getID())
		{
			flag=0;

		}

		else

		{
			i++;
		}

	}
		if(flag)
		{
			cout<<"the account does not exist !"<<endl;

		}
		else{

	
	for( int j=i;j<accnum;j++)
	{
		account[j]=account[j+1];
		
	}
	delete account[accnum-1];
	accnum--;
	cout<<" delete successful "<<endl;
		}
	return ;


}
void Bank::query()
{
	int ID;
	cout<<" please input the account ID that you want to query: ";
	cin>>ID;
	int flag=1;
	int i=0;
	while((i<accnum)&&(flag))
	{
		if(ID==account[i]->getID())
			flag=0;
		else 
			i++;
	}
		
		if(flag)
			cout<<endl<<" the account does not exist "<<endl;
		else 
		{
			account[i]->showme();
			int choice =0;
			while (choice!=3)
			{
				cout<<" 1: save money "<<endl;
				cout<<" 2: withdraw money "<<endl;
				cout<<"3: return "<<endl;
				cout<<" please input your choice:";
				cin>>choice;
				cout<<endl;
				switch( choice)
				{
				case 1:
					account[i]->saving();
					break;
				case 2:
					account[i]->withdrow();
					break;
				case 3:
					break;

				}
			}
	

	
		

}
	return ;

}