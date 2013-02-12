 
#include "iostream.h" 
#include "string.h" 
enum {NONE=0, CAT=1, DOG=2, SNAKE=3}; 

class Animal 
{ 
protected: 
 char color[20]; 
 char food[20]; 
 double weight; 
public: 
 virtual void ShowMe()=0; 
}; 

class Cat:public Animal 
{ 
public: 
 friend istream& operator>>(istream &is, Cat &cat); 
 void ShowMe() 
 { 
  cout<<"猫的颜色、喜欢的食物、体重分别为:"; 
  cout<<color<<","<<food<<","<<weight<<endl;   
 } 
}; 

istream & operator>>(istream &is, Cat &cat) 
{ 
 cout<<" 请输入猫的颜色: ";  
 is>>cat.color;  
 cout<<" 喜爱的食物:"; 
 is>>cat.food;  
 cout<<" 体重:"; 
 is>>cat.weight;  
 return is; 
} 


class Dog:public Animal 
{ 
public: 
 friend istream& operator>>(istream &is, Dog &Dog); 
 void ShowMe() 
 { 
  cout<<"狗的颜色、喜欢的食物、体重分别为:"; 
  cout<<color<<","<<food<<","<<weight<<endl;   
 } 
}; 

istream& operator>>(istream &is, Dog &dog) 
{ 
 cout<<" 请输入狗的颜色: ";  
 is>>dog.color; 
 cout<<" 喜爱的食物:"; 
 is>>dog.food; 
 cout<<" 体重:"; 
 is>>dog.weight;  
 return is; 
} 

class Snake:public Animal 
{ 
public: 
 friend istream& operator>>(istream &is, Snake &snake); 
 void ShowMe() 
 { 
  cout<<"蛇的颜色、喜爱的食物、体重分别为："; 
  cout<<color<<","<<food<<","<<weight<<endl;   
 } 
}; 

istream& operator>>(istream &is, Snake &snake) 
{ 
 cout<<" 请输入蛇的颜色: ";  
 is>>snake.color; 
 cout<<" 喜爱的食物: "; 
 is>>snake.food; 
 cout<<" 体重: "; 
 is>>snake.weight; 
 return is; 
} 

class Shelves 
{ 
 int cage[12]; 
 int sum[3]; 
 Cat cats[12]; 
 Dog dogs[12]; 
 Snake snakes[12]; 
// int flag[12]; 
// int sum_c, sum_d, sum_s; 
public: 
 Shelves () 
 { 
  for (int i=0; i<12; i++) 
   cage[i]=NONE; 
  for (i=0; i<4; i++) 
   sum[i]=0; 
 } 

 int push_cat(Cat &cat, int n) 
 { 
  cats[n] = cat;   
  if (cage[n]!=NONE) return 0; 
  else { 
   sum[0]++; 
   return cage[n]=CAT; 
  } 
 } 

 int push_dog(Dog &dog, int n) 
 { 
  dogs[n]=dog;   
  if (cage[n]!=NONE) return 0; 
  else{ 
   sum[1]++; 
   return cage[n]=DOG; 
  } 
 } 
 int push_snake(Snake &snake, int n) 
 {   
  snakes[n]=snake;   
  if (cage[n]!=NONE) return 0; 
  else { 
   sum[2]++; 
   return cage[n]=SNAKE; 
  } 
 } 

 void del(int n) 
 { 
  if (cage[n]==CAT) sum[0]--; 
  if (cage[n]==DOG) sum[1]--; 
  if (cage[n]==SNAKE) sum[2]--; 
  if (cage[n]==NONE) 
   cout<<"笼子里没有动物"<<endl; 
  else 
  {  
   cage[n]=NONE; 
   cout<<"已删除笼子里的动物"<<endl; 
  }   
  cout<<endl; 
 } 

 void seek(int n) 
 { 
  if (cage[n]==NONE) cout<<"第"<<n<<"个笼子里没有动物"<<endl; 
  if (cage[n]==CAT) 
  { 
   cout<<"第"<<n<<"个笼子里的动物为猫,"; 
   cats[n].ShowMe(); 
  } 
  if (cage[n]==DOG) 
  { 
   cout<<"第"<<n<<"个笼子里的动物为狗,"; 
   dogs[n].ShowMe(); 
  } 
  if (cage[n]==SNAKE) 
  { 
   cout<<"第"<<n<<"个笼子里的动物为蛇,";    
   snakes[n].ShowMe(); 
  } 
  cout<<endl;   
 } 

 void count() 
 {   
  cout<<"笼子里的猫总共有："<<sum[0]<<"只"<<endl; 
  cout<<"笼子里的狗总共有："<<sum[1]<<"只"<<endl; 
  cout<<"笼子里的蛇总共有："<<sum[2]<<"只"<<endl; 
  cout<<endl; 
 } 
}; 

void main() 
{ 
 char c; 
 Cat cat; 
 Dog dog; 
 Snake snake; 
 Shelves shelves; 
 int i=1,j; 

 cout<<"这是关于往笼子里放动物的问题: "<<endl; 
 cout<<endl; 
  cout<<" 1: 往笼子里放猫；"<<endl; 
  cout<<" 2: 往笼子里放狗；"<<endl; 
  cout<<" 3: 往笼子里放蛇；"<<endl; 
  cout<<" 4: 查询笼子里的动物；"<<endl; 
  cout<<" 5: 删除笼子里的动物；"<<endl; 
  cout<<" 6：统计笼子里的动物种类及数量；"<<endl; 
  cout<<" 7: 退出程序;"<<endl; 
  cout<<"------------------------------------------"<<endl; 
 while(i) 
 { 
  cout<<"请选择您的*作："; 
  cin>>i; 
  switch(i) 
  { 
  case 1: 
   cout<<" 往哪只笼子里面放: "; 
   cin>>j; 
   cin>>cat;     
   while (shelves.push_cat(cat, j)==0) 
   { 
    cout<<" 笼子里已有动物，请换一个笼子: "; 
    cin>>j; 
   } 
   break; 
  case 2: 
   cout<<" 往哪只笼子里面放: "; 
   cin>>j; 
   cin>>dog;     
   while (shelves.push_dog(dog, j)==0) 
   { 
    cout<<" 笼子里已有动物，请换一个笼子: "; 
    cin>>j; 
   } 
   break; 
  case 3: 
   cout<<" 往哪只笼子里面放: "; 
   cin>>j; 
   cin>>snake;     
   while (shelves.push_snake(snake, j)==0) 
   { 
    cout<<" 笼子里已有动物，请换一个笼子: "; 
    cin>>j; 
   } 
   break; 
  case 4:  
   cout<<" 查询哪只笼子: "; 
   cin>>j; 
   shelves.seek(j); 
   break; 
  case 5:  
   cout<<" 删除哪只笼子里的动物: "; 
   cin>>j; 
   shelves.del(j); break; 
  case 6: 
   shelves.count(); break; 
  default: i=0; break; 
  } 
  cout<<endl; 
 } 
}  
 