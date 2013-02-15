/*
Annie的宠物小屋里有12个笼子,每个笼子可以放不同的动物,包括猫,狗和蛇,但同一时刻一个笼子只能放0只或1只宠物,本题要求完成:
(1)实现一个简单的管理系统,可以增加,删除指定笼子中的宠物,查询每个笼子中存放宠物的情况,统计宠物的种类和数量.
(2)定义描述宠物小屋的类Shelves,其中包括12个笼子用于存放各种宠物;
(3)定义虚拟基类Animal,至少包含纯虚函数Showme;
(4)定义派生类Cat,Dog,Snake,具体实现上述纯虚函数showme,显示该宠物的种类,名称,着色,体重和喜欢的食物.
(5)重载输入>>操作符,使得可以通过cin直接读入宠物的着色,体重,和喜欢的食物;
(6)编写main函数,测上述所要求的各种功能;
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
				cout<<"which cage?";//由于不想重写所以就改了数字;
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