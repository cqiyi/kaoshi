#include<iostream>
#include"bank.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	Bank bank;
	int choice=0;
	cout<<" welcome to bank system "<<endl;
	while(choice!=4)
	{
		cout<<" 1: add an account "<<endl;
		cout<<"2: delete an account "<<endl;
		cout<<" 3: query an account "<<endl;
		cout<<" 4: exit "<<endl;
		cout<<" please input your choice:";
		cin >>choice;
		switch(choice)
		{
		case 1:
			bank.append();
			break;
		case 2:
			bank.deletes();
			break;
		case 3:
			bank.query();
			break;
		case 4:
			break;


		}

	}
	return 0;

}