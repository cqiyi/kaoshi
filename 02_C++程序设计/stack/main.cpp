#include"stack.h"
#include<iostream>
using std::cout;
using std::cin;


int  main()
{
	int i=0;
		integer *myint;
	mystring *mystrings;
	stack* stack1=new stack;

		while(i!=6){

		cout<<"please chiose(1-6):";
		cout<<"1:push an integer"<<'\n';
		cout<<"2:push a string "<<'\n';
		cout<<"3:pop"<<'\n';
		cout<<"4:top"<<'\n';
		cout<<"5:gettop"<<'\n';
		cout<<"6:exit"<<'\n';
				cin>>i;
	
	
	
		switch(i)
		{
		case 1:
			myint=new integer;
			cin>>*myint;
			stack1->push(myint);
			break;
		case 2:
			mystrings =new mystring;
			cin>>*mystrings;
			stack1->push(mystrings);
			break;
		case 3:
			stack1->pop();
			break;
		case 4:
			stack1 ->top();
			break;
		case 5:
			stack1->gettop();
			break;
		case 6:
			break;


		}
		}
	
	
	return 0;


}
