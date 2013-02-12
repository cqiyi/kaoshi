#include "string.h"
#include "iostream.h"
enum AnimalType {EMPTY=0,CAT=1,DOG=2,SNAKE=3};
const int MAX_AMOUNT=12;
const int TRUE=1;
const int FALSE=0;
const int STRING_LENGTH=50;

class Animal
{
protected:
 AnimalType enmType;
 char strColor[STRING_LENGTH];
 int intWeight;
 char strFood[STRING_LENGTH]; 
public: 
 Animal()
 {
  enmType=EMPTY;
  strcpy(strColor,"");
  intWeight=0;
  strcpy(strFood,"");
 };
 virtual void ShowMe()=0;
};

class Cat:public Animal
{
public:
 friend istream& operator>>(istream&,Cat&); 
 Cat(){enmType=CAT;};
 void ShowMe()
 {
  cout<<endl<<"类型 颜色 体重 喜爱的食物"<<endl;
  cout<<"猫,"<<strColor<<","<<intWeight<<","<<strFood<<endl;
 }; 
};

istream& operator>>(istream& is,Cat& cat)
{
 cout<<"请输入猫的颜色：";
 is>>cat.strColor; 
 cout<<"体重：";
 is>>cat.intWeight; 
 cout<<"喜欢的食物：";
 is>>cat.strFood; 
 return is;
};

class Dog:public Animal
{
public:
 friend istream& operator>>(istream&,Dog&); 
 Dog()
 {
  enmType=DOG;
 };
 void ShowMe()
 {
  cout<<endl<<"类型 颜色 体重 喜爱的食物"<<endl;
  cout<<"狗,"<<strColor<<","<<intWeight<<","<<strFood<<endl;
 }; 
};

istream& operator>>(istream& is,Dog& dog)
{
 cout<<"请输入狗的颜色：";
 is>>dog.strColor; 
 cout<<"体重：";
 is>>dog.intWeight; 
 cout<<"喜欢的食物：";
 is>>dog.strFood; 
 return is;
};

class Snake:public Animal
{
public:
 friend istream& operator>>(istream&,Snake&); 
 Snake(){enmType=SNAKE;};
 void ShowMe()
 {
  cout<<endl<<"类型 颜色 体重 喜爱的食物"<<endl;
  cout<<"蛇,"<<strColor<<","<<intWeight<<","<<strFood<<endl;
 }; 
};

istream& operator>>(istream& is,Snake& snake)
{
 cout<<"请输入蛇的颜色：";
 is>>snake.strColor; 
 cout<<"体重：";
 is>>snake.intWeight; 
 cout<<"喜欢的食物：";
 is>>snake.strFood; 
 return is;
};

class shelves
{
protected:
 AnimalType aryType[MAX_AMOUNT];
 Animal *aryAnimal[MAX_AMOUNT]; 
private:
 int CheckIndex(int&);
public:  
 shelves();
 ~shelves();
 void AddAnimal(int,AnimalType);
 void RemoveAnimal(int);
 void GetAnimalInfo(int);
 void CountAnimalInfo();
};

shelves::shelves()
{ 
 for(int i=0;i<MAX_AMOUNT;i++)
  aryType[i]=EMPTY; 
};

shelves::~shelves()
{ 
 for(int i=0;i<MAX_AMOUNT;i++)
  if(aryType[i]!=EMPTY)delete aryAnimal[i]; 
};

inline int shelves::CheckIndex(int& Index)
{
 if(Index>0 && Index<=MAX_AMOUNT)
 {
  Index--;
  return TRUE;
 }
 else
 {
  cout<<"输入的笼子的编号错误，必须在1和"<<MAX_AMOUNT<<"之间！"<<endl;
  return FALSE;
 };
};

void shelves::AddAnimal(int Index,AnimalType animaltype)
{
 if(CheckIndex(Index)==FALSE)return;
 if(aryType[Index]==EMPTY)
 {  
  switch(animaltype)
  {
  case CAT:
   aryAnimal[Index]=new Cat;
   cin>>*((Cat*)aryAnimal[Index]);   
   break;
  case DOG:
   aryAnimal[Index]=new Dog;
   cin>>*((Dog*)aryAnimal[Index]);   
   break;
  case SNAKE:
   aryAnimal[Index]=new Snake;
   cin>>*((Snake*)aryAnimal[Index]);   
   break;
  default:
   cout<<"你选择的宠物类型错误！"<<endl;
   return;
  };
  aryType[Index]=animaltype;
  cout<<"添加宠物成功！"<<endl;
 }
 else
  cout<<"这个笼子里面已经有宠物了！"<<endl;
};

void shelves::RemoveAnimal(int Index)
{
 if(CheckIndex(Index)==FALSE)return;
 if(aryType[Index]!=EMPTY) 
 {
  aryType[Index]=EMPTY;
  delete aryAnimal[Index];
  cout<<"删除宠物成功！"<<endl;
 }
 else
  cout<<"这个笼子里面没有宠物！"<<endl;
};

void shelves::GetAnimalInfo(int Index)
{
 if(CheckIndex(Index)==FALSE)return;
 if(aryType[Index]!=EMPTY)
  aryAnimal[Index]->ShowMe();
 else
  cout<<"这个笼子里面没有宠物！"<<endl; 
};

void shelves::CountAnimalInfo()
{
 int CatCounter=0,DogCounter=0,SnakeCounter=0,EmptyCounter=0;
 for(int Index=0;Index<MAX_AMOUNT;Index++)
 {
  if(aryType[Index]==EMPTY)EmptyCounter++;
  if(aryType[Index]==CAT)CatCounter++;
  if(aryType[Index]==DOG)DogCounter++;
  if(aryType[Index]==SNAKE)SnakeCounter++;
 };
 cout<<"猫笼子有"<<CatCounter<<endl;
 cout<<"狗笼子有"<<DogCounter<<endl;
 cout<<"蛇笼子有"<<SnakeCounter<<endl;
 cout<<"空笼子有"<<EmptyCounter<<endl;
};

inline void SystemTips()
{
 cout<<endl<<"宠物管理系统，请选择你的操作："<<endl;
 cout<<" 1、添加宠物"<<endl;
 cout<<" 2、删除宠物"<<endl;
 cout<<" 3、查询宠物"<<endl;
 cout<<" 4、统计宠物"<<endl;
 cout<<" 5、退出系统"<<endl<<endl;
};
void main()
{ 
 shelves shelve; 
 int intSelect,Index,enmAnimalType;
 char UserInput[255];
  
 SystemTips();
 while(1) 
 {  
  cin>>UserInput;
  if(strlen(UserInput)==1&&UserInput[0]>='1'&&UserInput[0]<='5')
   intSelect=UserInput[0]-'0';
  else
   intSelect=0;
  switch(intSelect)
  {
  case 1:   
   cout<<"请输入添加的笼子的编号：";
   cin>>Index;
   cout<<"1、猫 2、狗 3、蛇 ：";
   cin>>enmAnimalType;
   shelve.AddAnimal(Index,AnimalType(enmAnimalType));
   break;
  case 2:
   cout<<"请输入需要删除的笼子的编号：";
   cin>>Index;
   shelve.RemoveAnimal(Index);
   break;
  case 3:
   cout<<"请输入需要查询的笼子的编号：";
   cin>>Index;
   shelve.GetAnimalInfo(Index);
   break;
  case 4:   
   shelve.CountAnimalInfo();
   break;
  case 5:
   return;
   break;
  default:   
   SystemTips();
   break;
  };
 }; 
};



