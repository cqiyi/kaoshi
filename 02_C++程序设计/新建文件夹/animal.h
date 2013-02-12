#ifndef ANIMAL_H
#define ANIMAL_H

#include<iosfwd>
class Animal
{
public:
	virtual void showme()=0;
	virtual void deleteme()=0;
	~Animal(){}
protected:
	char *name ;
	char *color;
	float weight;
	char *food;
	int type;

};
class Cat:public Animal
{
public:
	Cat();
	void showme();
	static int number();
	friend std::istream & operator >>(std::istream & is,Cat &cat);
	void deleteme();
	~Cat();
private:
	static int Catnum;

};
class Dog:public Animal
{
public:
	Dog();
	void showme();
	static int number();
	friend std::istream & operator>>(std::istream & is,Dog &dog);
	void deleteme();
	~Dog();
private:
	static int Dognum;

};
class Snake:public Animal
{
public:
	Snake();
	void showme();
	static int number();
	friend std::istream & operator>>(std::istream & is ,Snake &snake);
	void deleteme();
	~Snake();
private:
	static int Snakenum;

};
class Shelves
{
public:
	Shelves();
	int add(int n,Animal *animal);
	void Delete(int n);
    void query(int n);
	void stat();
private:
	Animal * shelves[12];

};
#endif

