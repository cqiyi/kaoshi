/*��ʵ��һ��ջ���ȿ��Դ���������ֿ��Դ���ַ�����
  �򵥵�˵��ջ��һ�����ݽṹ�����պ���ȳ���˳����������ջ��Ԫ�ء�����Ҫ����ɣ�
1.ʵ������ջ����Stack�����ж�����ջ��ʵ�ʴ�СSize����������ջ����Push����ջ����Pop����ʾջ��Ԫ�صĺ���Top
2.�������Element�����ٰ������麯��ShowMe
3.�ӻ���Element������������MyInteger���ַ�����MyString������ʵ���������麯��ShowMe,��ʾ��Ԫ�ص����ͺ���Ӧ��ֵ
4.��������>>��������ʹ����ͨ��cin�����������ַ���
5.��дmain�������������ϸ��ֹ��ܣ�ջ��Ԫ�����������ַ���*/
#include<iostream.h>
const int Max=20;
class Element
{
public:
	virtual void ShowMe()=0;
};
class MyInteger:public Element
{
private:
	int Integer;
public:
	MyInteger(){Integer=0;}
	friend istream& operator >> (istream& is,MyInteger& integer);
	void ShowMe();
};
istream& operator >> (istream& is,MyInteger& integer)
{
	cout<<endl<<"������Ҫ��ջ������: ";cin>>integer.Integer;
	return is;
}
void MyInteger::ShowMe()
{
	cout<<endl<<"��Ԫ��Ϊ����,ֵΪ: "<<Integer<<endl;
	return;
}
class MyString:public Element
{
private:
	char *String;
public:
	MyString(){String=NULL;}
	friend istream& operator >> (istream& is,MyString& string);
	void ShowMe();
};
istream& operator >> (istream& is,MyString& string)
{
	string.String=new char[20];
	cout<<endl<<"������Ҫ��ջ���ַ���: ";cin>>string.String;
	return is;
}
void MyString::ShowMe()
{
	cout<<endl<<"��Ԫ��Ϊ�ַ���,ֵΪ: "<<String<<endl;
	return;
}
class Stack
{
private:
	int Size;
	Element *stack[Max];
public:
	Stack(){Size=0;for(int i=0;i<Max;i++) stack[i]=NULL;}
	void Push(Element *element);
	void Pop();
	void Top();
};
void Stack::Push(Element *element)
{
	if(Size>=Max)
		cout<<endl<<"ջ��!���ܽ���ѹջ!"<<endl;
	else{	
		Size++;
		stack[Size]=element;
		cout<<endl<<"�����ѳɹ���ջ!"<<endl;
	}
	return;
}
void Stack::Pop()
{
	if(Size==0)
		cout<<endl<<"ջ��!û��Ԫ�ؿ��Գ�ջ!"<<endl;
	else{
		stack[Size]->ShowMe();
		stack[Size]=NULL;
		Size--;
		cout<<endl<<"�������ѳɹ���ջ!"<<endl;
	}
	return;
}
void Stack::Top()
{
	if(Size==0)
		cout<<endl<<"ջ��!ջ����Ԫ��"<<endl;
	else{
		cout<<endl<<"ջ��Ԫ��Ϊ: "<<endl;
		stack[Size]->ShowMe();
	}
	return;
}
void main()
{
	Stack *sta=new Stack;
	MyString *str;
	MyInteger *inte;
	int chioce,i;
	cout<<endl<<"**************��ϵͳ�ṩ���²���***************"<<endl;
	while(chioce!=4)
	{
		i=0;
		cout<<endl<<"1.ѹջ     2.��ջ     3.��ʾջ��Ԫ��     4.�˳� "<<endl;
		cin>>chioce;
		switch(chioce)
		{
		case 1:
			while(i!=3)
			{
				cout<<endl<<"1.������ջ      2.�ַ�����ջ      3.�˳�"<<endl;
				cin>>i;
				switch(i)
				{
				case 1:
					inte=new MyInteger;
					cin>>*inte;
					sta->Push(inte);
					break;
				case 2:
					str=new MyString;
					cin>>*str;
					sta->Push(str);
					break;
				case 3:
					break;
				}
			}
			break;
		case 2:
			sta->Pop();
			break;
		case 3:
			sta->Top();
			break;
		case 4:
			break;
		}
	}
	cout<<endl<<"     ллʹ�ñ�ϵͳ!"<<endl;
	return;
}