#include "iostream.h" 
#include "string.h" 
const max=1000; 
#define NULL 0 

class Element 
{ 
public: 
  virtual void ShowMe () = 0; }; 

class MyInteger:public Element 
{ int a; 
public: 
 MyInteger(){a=0;} 
 friend istream &operator>>(istream &is, MyInteger &MyI); 
 int Get() {return a;}; 
 void ShowMe() 
 { 
  cout<<" ������"<<a<<endl; 
 } 
}; 

istream &operator>>(istream &is, MyInteger &MyI) 
{ is>>MyI.a; 
 return is;} 

class MyString:public Element 
{ char s[100]; 
public: 
  
 friend istream &operator>>(istream &is, MyString &MyS); 
 void ShowMe() 
 { cout<<" �ַ�����"<<s<<endl; } 
}; 

istream &operator>>(istream &is, MyString &MyS) 
{ is>>MyS.s; 
 return is; } 

class stack 
{ MyString MyS[max]; 
 MyInteger MyI[max]; 
 int top; 
public: 
 stack() {top=-1;} 
 void push(MyInteger &My) 
 { MyI[++top]=My; } 

 void push(MyString &My) 
 { MyS[++top]=My; } 

 void Top() 
 {   
  if (empty()) cout<<"ջΪ��"<<endl; 
  else MyI[top].ShowMe(); 
 } 
 void Tops() 
 {   
  if (empty()) cout<<"ջΪ��"<<endl; 
  else MyS[top].ShowMe(); 
 } 

 void pop() 
 {  MyI[top--].ShowMe(); } 

 void pops() 
 { MyS[top--].ShowMe(); } 

 bool empty() 
 { return (bool)(top==-1); } 

 bool full() 
 { return (bool)(top==max-1); } 
}; 

int main(int argc, char* argv[]) 
{ MyInteger My1; 
 MyString My2; 
 stack st1, st2; 
 int i, j; 
  
 cout<<"������Ҫ��ջ����������"; 
 cin>>j; 
 cout<<"������"<<j<<"������"<<endl; 
 for (i=0; i<j; i++) 
 { cin>>My1; 
  st1.push(My1);  
 } 
 cout<<"ջ��Ԫ��Ϊ��"; 
 st1.Top(); 
 cout<<"������Ҫ��ջ��Ԫ�ظ�����"; 
 cin>>j; 
 cout<<"���γ�ջԪ��Ϊ��"<<endl; 
 for (i=0; i<j; i++) 
  st1.pop();  
 cout<<"��ջ��ջ��Ԫ��Ϊ��"; 
 st1.Top(); 
 cout<<"������Ҫ��ջ���ַ���������"; 
 cin>>j; 
 cout<<"������"<<j<<"���ַ���"<<endl; 
 for (i=0; i<j; i++) 
 {   
  cin>>My2; 
  st2.push(My2);  
 } 
 cout<<"ջ��Ԫ��Ϊ��"; 
 st2.Tops(); 
 cout<<"������Ҫ��ջ��Ԫ�ظ�����"; 
 cin>>j; 
 cout<<"���γ�ջԪ��Ϊ��"<<endl; 
 for (i=0; i<j; i++) 
  st2.pops();  
 cout<<"��ջ��ջ��Ԫ��Ϊ��"; 
 st2.Tops(); 

 return 0; 
}  
 
