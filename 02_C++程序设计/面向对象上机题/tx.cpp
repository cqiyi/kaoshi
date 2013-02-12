
#include "iostream.h" 
#include "string.h" 
const n=50; 

class shape 
{ 
protected: 
 double width, length; 
public: 
 shape() {} 
 virtual void ShowMe()=0; 
}; 

class rectangle:public shape 
{ 
public: 
 rectangle():shape(){} 
 friend istream &operator>>(istream &is, rectangle &rec) 
 { 
  cout<<"请输入长方形的长："; 
  is>>rec.length; 
  cout<<"请输入长方形的宽："; 
  is>>rec.width; 
  return is; 
 } 
 void ShowMe() 
 { 
  cout<<"长方形的长宽分别为：("<<length 
   <<","<<width<<")"<<endl;   
 } 
}; 

class circle:public shape 
{ 
private: 
 //double x, y; 
 double r; 
public: 
 circle():shape(){r=0;} 
 friend istream &operator>>(istream &is, circle &cir) 
 { 
  cout<<"请输入圆的圆心坐标(x,y)："; 
  is>>cir.width; 
  is>>cir.length; 
  cout<<"请输入圆的半径："; 
  is>>cir.r; 
  return is; 
 } 
 void ShowMe() 
 { 
  cout<<"圆的圆心坐标为：("<<width<<","<<length<<")" 
   <<" 半径为："<<r<<endl; 
 } 
}; 

class stack 
{ 
 shape *sp[n]; 
 rectangle rec[n]; 
 circle cir[n]; 
 int size; 
public: 
 stack() 
 { 
  for (int i=0; i<n; i++) 
   sp[i]=NULL; 
  size=-1; 
 } 
 bool empty(){return size==-1;} 
 bool full(){return size==n-1;} 

 void push(rectangle &rect) 
 { 
  rec[++size]=rect; 
  sp[size]=new rectangle; 
  sp[size]=&rec[size]; 
 } 
 void push(circle &circ) 
 { 
  cir[++size]=circ; 
  sp[size]=new circle; 
  sp[size]=&cir[size]; 
 } 
 void top() 
 { 
  if (empty()) cout<<"栈为空"<<endl; 
  else { 
   cout<<"栈顶元素为:"<<endl; 
   sp[size]->ShowMe();    
  } 
   
 } 

 void pop() 
 { 
  if (empty()) cout<<"栈为空"<<endl; 
  else { 
   cout<<"出栈元素为:"<<endl; 
   sp[size--]->ShowMe();      
  } 
 } 
}; 

void main() 
{ 
 stack Stack; 
 rectangle rec; 
 circle cir; 
 int s=1; 
 while (s) 
 { 
  cout<<endl; 
  cout<<"请选择1-5号键*作"<<endl; 
  cout<<" 1: 矩形进栈;"<<endl; 
  cout<<" 2: 圆进栈;"<<endl; 
  cout<<" 3: 显示栈顶元素;"<<endl; 
  cout<<" 4: 出栈;"<<endl; 
  cout<<" 5: 退出程序;"<<endl; 
  cin>>s; 
  switch(s) 
  { 
  case 1: cin>>rec; Stack.push(rec); break; 
  case 2: cin>>cir; Stack.push(cir); break; 
  case 3: Stack.top(); break; 
  case 4: Stack.pop(); break; 
  case 5: s=0; break; 
  //default: cout<<"请重新输入"<<endl; break; 
  } 
 } 
}  
 