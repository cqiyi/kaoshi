/*
Annie�ĳ���С������12������,ÿ�����ӿ��ԷŲ�ͬ�Ķ���,����è,������,��ͬһʱ��һ������ֻ�ܷ�0ֻ��1ֻ����,����Ҫ�����:
(1)ʵ��һ���򵥵Ĺ���ϵͳ,��������,ɾ��ָ�������еĳ���,��ѯÿ�������д�ų�������,ͳ�Ƴ�������������.
(2)������������С�ݵ���Shelves,���а���12���������ڴ�Ÿ��ֳ���;
(3)�����������Animal,���ٰ������麯��Showme;
(4)����������Cat,Dog,Snake,����ʵ���������麯��showme,��ʾ�ó��������,����,��ɫ,���غ�ϲ����ʳ��.
(5)��������>>������,ʹ�ÿ���ͨ��cinֱ�Ӷ���������ɫ,����,��ϲ����ʳ��;
(6)��дmain����,��������Ҫ��ĸ��ֹ���;
*/

#include <iostream>
#include"animal.h"
using namespace std;

int main()
{
	Shelves * shelves=new Shelves;
	Cat *cat;
	Dog *dog;
	Snake *snake;
	int n;
	int i=0;
	char ch;
	while(i!=5)
	{
		cout<<" please chiose(1-5):"<<endl;
		cout<<" 1:add an animal"<<endl;
		cout<<"2:delete an animal"<<endl;
		cout<<" 3:query"<<endl;
		cout<<"4:stat"<<endl;
		cout<<"5:exit"<<endl;
		cin>>i;
		switch(i)
		{
		case 1:
			cout<<"which cage?";
			cin>>n;
			cout<<"c:cat d:dog s:snake"<<endl;
			cout<<"please choise an animal:";
			cin>>ch;
			switch(ch)
			{
			case'c':
				cat=new Cat;
				cin>>*cat;
				if(!shelves ->add(n,cat))
					cat->deleteme();
					break;
			case'd':
				dog=new Dog;
				cin>>*dog;
				if(!shelves->add(n,dog))
					dog->deleteme();
				break;
			case's':
				snake=new Snake;
				cin>>*snake;
				if(!shelves->add(n,snake))
					snake->deleteme();
				break;
			default:
				cout<<" your choise is wrong"<<endl;

				break;

			}
			break;
			case 3:
				cout<<" thich cage ?";
				cin>>n;
				shelves->query(n);
				break;
			case 2:
				cout<<"which cage?";//���ڲ�����д���Ծ͸�������;
				cin>>n;
				shelves->Delete(n);
				break;
			case 4:
				shelves->stat();
				break;
			case 5:
				break;
				

		}
	}
	return 0;

}