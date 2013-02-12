/*��ʵ��һ���򵥵����д���ϵͳ���е������û��Ĵ���ȡ��ҵ��Ҫ�����£�
1.ʵ���������е���Bank����¼ϵͳ��������Щ����(��������ʵ�֣���ע���ж�����Խ������)��
  �������ɴ����ĺ���Append�������ʺ�ɾ�������ĺ���Delete�������ʺŲ�ѯ�����ĺ���Query������ʾ��ѯ�����
2.���崢����Account�������ʺš�������������������ԣ�����Saving��������ҵ�񣩡�
  Withdraw������ȡ��ҵ������ʱ����ȡ�������ʾ����ShowMe����ʾ����������Ϣ����
3.��дmain����������������Ҫ��ĸ��ֹ��ܣ������Ը��ݲ˵��������ӡ�ɾ���Ͳ�ѯ�������Լ���������ȡ��Ĳ�����*/
#include<iostream.h>
#include<string.h>
class Account
{
private:
	int ID;
	char Name[20];
	float Balance;
public:
	Account(){}
	Account(int id,char *name,float balance)
	{
		ID=id;
		strcpy(Name,name);
		Balance=balance;
	}
	int GetID(){return ID;}
	void Saving();
	void Withdraw();
	void ShowMe();
};
void Account::ShowMe()
{
	cout<<endl<<"���ʻ���Ϣ����: "<<endl<<endl;
	cout<<"********�ʺ�Ϊ: "<<ID<<endl;
	cout<<"********����Ϊ: "<<Name<<endl;
	cout<<"********���Ϊ: "<<Balance<<endl;
	return;
}
void Account::Saving()
{
	int money;
	cout<<endl<<"������Ҫ����Ľ��: ";
	cin>>money;
	Balance+=money;
	cout<<endl<<"�����ʻ����Ϊ: "<<Balance<<endl<<endl;
	return;
}
void Account::Withdraw()
{
	int money;
	cout<<endl<<"�����Ҫȡ��Ľ��: ";
	cin>>money;
	while(money>Balance){
		cout<<endl<<"����!����������Ҫȡ��Ľ��: ";
		cin>>money;
	}
	Balance-=money;
	cout<<endl<<"�����ʻ����Ϊ: "<<Balance<<endl<<endl;
	return;
}
class Bank
{
private:
	int NewID;
	int k;
	Account account[20];
public:
	Bank(){NewID=1100;k=0;}
	void Append();
	void Delete();
	void Query();
};
void Bank::Append()
{
	NewID=NewID+2;
	if(k==20){
		cout<<"�������ʻ�ʧ�ܣ�ϵͳ�ʻ�������"<<endl;
	}
	else{
	int id=NewID;
	char name[20];
	float init;
	cout<<"���������ʻ�������: ";cin>>name;
	cout<<"�������ʻ���ʼ���: ";cin>>init;
	Account newaccount(NewID,name,init);
	account[k]=newaccount;
	k++;
	cout<<endl<<"     �½��ʻ��ɹ�!"<<endl;
	newaccount.ShowMe();
	}
	return;
}
void Bank::Delete()
{
	int id;
	cout<<"������Ҫɾ���ʻ����ʺ�: ";
	cin>>id;
	for(int i=0;i<k;i++)
		if(account[i].GetID()==id)
			break;
	if(i==k)
		cout<<endl<<"   �Բ���!���޴��ʻ�!"<<endl;
	else{
		for(int j=i;j<k;j++)
			account[j]=account[j+1];
		k--;
		cout<<endl<<"     �ɹ�ɾ�����ʻ�!"<<endl;
	}
	return;
}
void Bank::Query()
{
	int id,chioce;
	cout<<"������Ҫ��ѯ�ʻ����ʺ�: ";
	cin>>id;
	for(int i=0;i<k;i++)
		if(account[i].GetID()==id)
			break;
	if(i==k)
		cout<<endl<<"   �Բ���!���޴��ʻ�!"<<endl;
	else{
		account[i].ShowMe();
		while(chioce!=3)
		{
			cout<<endl<<"      ��ѡ�����Ĳ���"<<endl<<endl;
			cout<<"1.���    2.ȡ��   3.�˳�"<<endl;
			cin>>chioce;
			switch(chioce)
			{
			case 1:
				account[i].Saving();
				break;
			case 2:
				account[i].Withdraw();
				break;
			case 3:
				break;
			}
		}
	}
	return;
}
void main()
{
	Bank bank;
	int chioce;
	cout<<endl<<"************��ϵͳ�ṩ���¹���**************"<<endl<<endl;
	while(chioce!=4)
	{
		cout<<endl;
		cout<<"1.�������ʻ�  2.ɾ���ʻ�  3.��ѯ�ʻ�  4.�˳�"<<endl;
		cin>>chioce;
		switch(chioce)
		{
		case 1:
			bank.Append();
			break;
		case 2:
			bank.Delete();
			break;
		case 3:
			bank.Query();
			break;
		case 4:
			break;
		default:
			break;
		}
	}
	cout<<endl<<"     ллʹ�ñ�ϵͳ!"<<endl<<endl;
}