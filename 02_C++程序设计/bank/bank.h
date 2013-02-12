#ifndef BANK_H
#define BANK_H
class Account
{
public:
	Account();
	Account(int ,const char *,double);
	void saving();
	int withdrow();
	void showme();
	int getID();
private:
	int ID;
	char *name;
	double balance;


};
class Bank
{
public:
	Bank();
	void append();
	void deletes();
	void query();
private:
	Account *account[50];
	int maxID;
	int accnum;

};
#endif


