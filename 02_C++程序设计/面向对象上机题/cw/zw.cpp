 
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
  cout<<"è����ɫ��ϲ����ʳ����طֱ�Ϊ:"; 
  cout<<color<<","<<food<<","<<weight<<endl;   
 } 
}; 

istream & operator>>(istream &is, Cat &cat) 
{ 
 cout<<" ������è����ɫ: ";  
 is>>cat.color;  
 cout<<" ϲ����ʳ��:"; 
 is>>cat.food;  
 cout<<" ����:"; 
 is>>cat.weight;  
 return is; 
} 


class Dog:public Animal 
{ 
public: 
 friend istream& operator>>(istream &is, Dog &Dog); 
 void ShowMe() 
 { 
  cout<<"������ɫ��ϲ����ʳ����طֱ�Ϊ:"; 
  cout<<color<<","<<food<<","<<weight<<endl;   
 } 
}; 

istream& operator>>(istream &is, Dog &dog) 
{ 
 cout<<" �����빷����ɫ: ";  
 is>>dog.color; 
 cout<<" ϲ����ʳ��:"; 
 is>>dog.food; 
 cout<<" ����:"; 
 is>>dog.weight;  
 return is; 
} 

class Snake:public Animal 
{ 
public: 
 friend istream& operator>>(istream &is, Snake &snake); 
 void ShowMe() 
 { 
  cout<<"�ߵ���ɫ��ϲ����ʳ����طֱ�Ϊ��"; 
  cout<<color<<","<<food<<","<<weight<<endl;   
 } 
}; 

istream& operator>>(istream &is, Snake &snake) 
{ 
 cout<<" �������ߵ���ɫ: ";  
 is>>snake.color; 
 cout<<" ϲ����ʳ��: "; 
 is>>snake.food; 
 cout<<" ����: "; 
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
   cout<<"������û�ж���"<<endl; 
  else 
  {  
   cage[n]=NONE; 
   cout<<"��ɾ��������Ķ���"<<endl; 
  }   
  cout<<endl; 
 } 

 void seek(int n) 
 { 
  if (cage[n]==NONE) cout<<"��"<<n<<"��������û�ж���"<<endl; 
  if (cage[n]==CAT) 
  { 
   cout<<"��"<<n<<"��������Ķ���Ϊè,"; 
   cats[n].ShowMe(); 
  } 
  if (cage[n]==DOG) 
  { 
   cout<<"��"<<n<<"��������Ķ���Ϊ��,"; 
   dogs[n].ShowMe(); 
  } 
  if (cage[n]==SNAKE) 
  { 
   cout<<"��"<<n<<"��������Ķ���Ϊ��,";    
   snakes[n].ShowMe(); 
  } 
  cout<<endl;   
 } 

 void count() 
 {   
  cout<<"�������è�ܹ��У�"<<sum[0]<<"ֻ"<<endl; 
  cout<<"������Ĺ��ܹ��У�"<<sum[1]<<"ֻ"<<endl; 
  cout<<"����������ܹ��У�"<<sum[2]<<"ֻ"<<endl; 
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

 cout<<"���ǹ�����������Ŷ��������: "<<endl; 
 cout<<endl; 
  cout<<" 1: ���������è��"<<endl; 
  cout<<" 2: ��������Ź���"<<endl; 
  cout<<" 3: ����������ߣ�"<<endl; 
  cout<<" 4: ��ѯ������Ķ��"<<endl; 
  cout<<" 5: ɾ��������Ķ��"<<endl; 
  cout<<" 6��ͳ��������Ķ������༰������"<<endl; 
  cout<<" 7: �˳�����;"<<endl; 
  cout<<"------------------------------------------"<<endl; 
 while(i) 
 { 
  cout<<"��ѡ������*����"; 
  cin>>i; 
  switch(i) 
  { 
  case 1: 
   cout<<" ����ֻ���������: "; 
   cin>>j; 
   cin>>cat;     
   while (shelves.push_cat(cat, j)==0) 
   { 
    cout<<" ���������ж���뻻һ������: "; 
    cin>>j; 
   } 
   break; 
  case 2: 
   cout<<" ����ֻ���������: "; 
   cin>>j; 
   cin>>dog;     
   while (shelves.push_dog(dog, j)==0) 
   { 
    cout<<" ���������ж���뻻һ������: "; 
    cin>>j; 
   } 
   break; 
  case 3: 
   cout<<" ����ֻ���������: "; 
   cin>>j; 
   cin>>snake;     
   while (shelves.push_snake(snake, j)==0) 
   { 
    cout<<" ���������ж���뻻һ������: "; 
    cin>>j; 
   } 
   break; 
  case 4:  
   cout<<" ��ѯ��ֻ����: "; 
   cin>>j; 
   shelves.seek(j); 
   break; 
  case 5:  
   cout<<" ɾ����ֻ������Ķ���: "; 
   cin>>j; 
   shelves.del(j); break; 
  case 6: 
   shelves.count(); break; 
  default: i=0; break; 
  } 
  cout<<endl; 
 } 
}  
 