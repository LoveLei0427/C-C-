#include<iostream>
#include<stdlib.h>
using namespace std;

class Base{
public:
	Base(){
		this->strf = "Fu";
		cout << "Create Fu!" << endl;
	}
	~Base(){
		cout << "Delete Fu!" << endl;
	}
	
	char *strf;
};

class Derived:public Base{
public:
	Derived(){
		this->strd = "Zi";
		cout << "Create Zi!" << endl;
	}

	~Derived(){
		cout << "Delete Zi!" << endl;
	}
	char *strd;
	char ch[1024 * 1024];//足够大的情况下 第四种情况会报错
};
int main()
{
	Base *base1 = new Base;  //Create Fu,Delete Fu
	delete base1;			
	cout << endl;

	Derived *derived1 = new Derived;
	delete derived1;     //Create Fu,Create Zi,Delete Zi,Delete Fu
	cout << endl;

	//每个子类对象内部包含父类对象 子类对象得不到释放会造成内存泄漏 将父类中的析构函数声明为virtual虚函数 就可以解决
	Base *base2 = new Derived;  //Create Fu,Create Zi,Delete Fu 
	delete base2;
	cout << endl;
	
	//内存越界释放    有时报错
	Derived *derived2 = static_cast<Derived*>(new Base);
	delete derived2;      //Create Fu,Delete Zi,Delete Fu
	
	system("pause");
}