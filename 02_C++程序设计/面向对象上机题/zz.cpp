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
  cout<<" 整数："<<a<<endl; 
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
 { cout<<" 字符串："<<s<<endl; } 
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
  if (empty()) cout<<"栈为空"<<endl; 
  else MyI[top].ShowMe(); 
 } 
 void Tops() 
 {   
  if (empty()) cout<<"栈为空"<<endl; 
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
  
 cout<<"请输入要进栈整数个数："; 
 cin>>j; 
 cout<<"请输入"<<j<<"个整数"<<endl; 
 for (i=0; i<j; i++) 
 { cin>>My1; 
  st1.push(My1);  
 } 
 cout<<"栈顶元素为："; 
 st1.Top(); 
 cout<<"请输入要出栈的元素个数："; 
 cin>>j; 
 cout<<"依次出栈元素为："<<endl; 
 for (i=0; i<j; i++) 
  st1.pop();  
 cout<<"出栈后栈顶元素为："; 
 st1.Top(); 
 cout<<"请输入要进栈的字符串个数："; 
 cin>>j; 
 cout<<"请输入"<<j<<"个字符串"<<endl; 
 for (i=0; i<j; i++) 
 {   
  cin>>My2; 
  st2.push(My2);  
 } 
 cout<<"栈顶元素为："; 
 st2.Tops(); 
 cout<<"请输入要出栈的元素个数："; 
 cin>>j; 
 cout<<"依次出栈元素为："<<endl; 
 for (i=0; i<j; i++) 
  st2.pops();  
 cout<<"出栈后栈顶元素为："; 
 st2.Tops(); 

 return 0; 
}  
 
