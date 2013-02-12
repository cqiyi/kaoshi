
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
  cout<<"�����볤���εĳ���"; 
  is>>rec.length; 
  cout<<"�����볤���εĿ�"; 
  is>>rec.width; 
  return is; 
 } 
 void ShowMe() 
 { 
  cout<<"�����εĳ���ֱ�Ϊ��("<<length 
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
  cout<<"������Բ��Բ������(x,y)��"; 
  is>>cir.width; 
  is>>cir.length; 
  cout<<"������Բ�İ뾶��"; 
  is>>cir.r; 
  return is; 
 } 
 void ShowMe() 
 { 
  cout<<"Բ��Բ������Ϊ��("<<width<<","<<length<<")" 
   <<" �뾶Ϊ��"<<r<<endl; 
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
  if (empty()) cout<<"ջΪ��"<<endl; 
  else { 
   cout<<"ջ��Ԫ��Ϊ:"<<endl; 
   sp[size]->ShowMe();    
  } 
   
 } 

 void pop() 
 { 
  if (empty()) cout<<"ջΪ��"<<endl; 
  else { 
   cout<<"��ջԪ��Ϊ:"<<endl; 
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
  cout<<"��ѡ��1-5�ż�*��"<<endl; 
  cout<<" 1: ���ν�ջ;"<<endl; 
  cout<<" 2: Բ��ջ;"<<endl; 
  cout<<" 3: ��ʾջ��Ԫ��;"<<endl; 
  cout<<" 4: ��ջ;"<<endl; 
  cout<<" 5: �˳�����;"<<endl; 
  cin>>s; 
  switch(s) 
  { 
  case 1: cin>>rec; Stack.push(rec); break; 
  case 2: cin>>cir; Stack.push(cir); break; 
  case 3: Stack.top(); break; 
  case 4: Stack.pop(); break; 
  case 5: s=0; break; 
  //default: cout<<"����������"<<endl; break; 
  } 
 } 
}  
 