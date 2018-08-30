#include<iostream>
#include<bitset>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
	//将十进制数255转换为8位的二进制
	bitset<8>bb(255);
	for (int i = 7; i >=0; i--){
		cout << bb[i]<<endl; //正常输出
	}
	//若是i=0;i<8;i++ 则是逆序输出
	system("pause");
}