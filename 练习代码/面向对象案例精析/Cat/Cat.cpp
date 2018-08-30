/*
主要实现类的声明 定义 函数的声明 定义和调用
*/
#include<iostream>
#include <string>
#include<cstdlib>

using namespace std;

void CatTest();
//void CatOneMonth();

class Cat{
public:
	Cat(const string& name);
	void eat(int food);
	void drink(int water);
	void talk();
	void sleep(int hours);
	void sport(int hours);
private:
	int food;
	int water;
	int hour;
	string name;
	int weight;
	int age;
};

//实现Cat类
Cat::Cat(const string& name):name(name), food(0), water(0), weight(80), age(0)
{}

void Cat::talk()
{
	cout << name << "(age =  " << age << "  weight =  "
		<< weight << "  food=  " << food << "  water =  " << water << ")"
		<< endl;
}

void CatTest()
{
	Cat cat("Maomi");
	
	cat.eat(10);
	cat.drink(6);
	cat.sleep(2);
	cat.sport(3);
	cat.talk();
}


//void CatOneMonth()
//{
//	Cat cat("Maomi");
//	cat.drink(1);
//	...
//}

void Cat::eat(int f)
{
	food += f;
}

void Cat::drink(int w)
{
	water += w;
}

void Cat::sleep(int h)
{
	food -= 1 * h;
	water -= 1 * h;
	weight += 1 * h;
	if (food < 0)
	{
		weight += food;
		food = 0;
	}
	if (water < 0)
	{
		weight += water;
		water = 0;
	}
	age += h;
}

void Cat::sport(int h)
{
	food -= 3 * h;
	water -= 3 * h;
	weight += 1 * h;
	if (food < 0)
	{
		weight += food;
		food = 0;
	}
	if (water < 0)
	{
		weight += water;
		water = 0;
	}
	age += h;
}


int main(void)
{
	CatTest();
	//CatOneMonth();
	system("pause..");
}

