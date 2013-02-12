#include<iostream>

#include"animal.h"
using std::cout;
using std::cin;
using std::endl;
int Cat::Catnum=0;
Cat::Cat()
{
	type=0;
	weight=0;

	name=new char[20];
	color =new char [20];
	food=new char [20];
	Catnum++;
	
}
void Cat::showme()
{
	cout<<"I am a Cat."<<endl;
	cout<<" My name is "<<name<<endl;
	cout<<" My color is "<<color<<endl;
	cout<<"My weight is "<<weight<<endl;
	cout <<" My favorite foood is "<<food <<endl;
	return ;

}
int Cat::number()
{
	return Catnum;

}
std::istream & operator>>(std::istream & is ,Cat &cat)
{
	cout<<" the cat's name is :";
	is>>cat.name;
	cout<<endl<<"the cat's color is:";
	is>>cat.color;
	cout<<endl<<" the cat's weight is :";
	is>>cat.weight;
	cout<<endl<<"the cat's fovarite food is :";
	cin>>cat.food;
	return is;

}
void Cat::deleteme()
{
	Catnum--;

}
Cat::~Cat()
{

}
int Dog::Dognum=0;
Dog::Dog()
{
	type=1;
	name=new char [20];
	color =new char [20];
	food=new char [20];
	weight=0;

	Dognum++;

}
void Dog::showme()
{
	cout<<endl<<"I am a Dog"<<endl;
	cout<<"My name is "<<name<<endl;
	cout<<" My color is "<<color<<endl;
	cout<<"My weight is  "<<weight<<endl;
	cout<<"My favorite food is "<<food<<endl;
	return ;

}
int Dog::number()
{
	return Dognum;

}
std::istream & operator>>(std::istream &is ,Dog &dog)
{
	cout<<"the dog's name is";
	is>>dog.name;
	cout<<endl<<" the dog's color is ";
	is>>dog.color;
	cout<<endl<<"the dog's weight is ";
	is>>dog.weight;
	cout<<endl<<"the dog's fovarite food is:";
	is>>dog.food;
	return is;


}
void Dog::deleteme()
{
	Dognum--;

}
Dog::~Dog()
{}
int Snake::Snakenum=0;
Snake::Snake()
{
	type=2;
	name=new char [20];
	color=new char [20];
	food=new char [20];
	Snakenum++;
}
void Snake::showme()
{
	cout<<endl<<"I am a Snake"<<endl;
	cout<<"My name is "<<name<<endl;
	cout<<" My color is "<<color<<endl;
	cout<<"My weight is  "<<weight<<endl;
	cout<<"My favorite food is "<<food<<endl;
	return ;


}
int Snake::number()
{
	return Snakenum;

} 
std::istream & operator>>(std::istream &is ,Snake &snake)
{
	cout<<"the snake's name is";
	is>>snake.name;
	cout<<endl<<" the snake's color is ";
	is>>snake.color;
	cout<<endl<<"the snake's weight is ";
	is>>snake.weight;
	cout<<endl<<"the snake's fovarite food is:";
	is>>snake.food;
	return is;


}
void Snake::deleteme()
{
	Snakenum--;

}
Snake::~Snake()
{}

Shelves::Shelves()
{
	for(int i=0;i<12;i++)
	{
		shelves[i]=NULL;

	}
}
int Shelves::add(int n,Animal * animal)
{
	int successful=1;
	if(shelves[n]!=NULL)
	{
		cout<<"the "<<n<<" the shelve is full"<<endl;
		successful=0;
		return successful;

	}
	shelves[n]=animal;
	cout<<" successful!"<<endl;
	return successful;

}
void Shelves::query(int n)
{
	if(shelves[n]==NULL)
	{
		cout<<"the "<<n<<" the shelve is empty!"<<endl;
		return ;

	}
	shelves[n]->showme();
	return ;

}
void Shelves::Delete(int n)
{
	if(shelves[n]==NULL)
	{
		cout<<"the "<<n<<" shelves is empty"<<endl;
		return ;

	}
	 shelves[n]->deleteme();
	shelves[n]=NULL;
	cout<<"successful!"<<endl;
	return ;

}
void Shelves::stat()
{
	cout<<"there ar "<<Cat::number()<<"cats"
	<<Dog::number()<<"dog,and"<<Snake::number()
		<<"snake."<<endl;
	return ;








}