/*iostream.h 包含操作所有输入/输出流所需的基本信息 cin cout cerr clog对象
  iomanip.h 包含格式化I/O操作算子
  cin istream类对象,一般连接键盘 可以重定向
  cout ostream类对象,一般连接显示器 可以重定向
  cerr ostream类对象,连接显示器 不可重定向
  clog ostream类对象,连接打印机 不可重定向
  程序<file2:将file2内容作为输入输入到程序
  程序>file1 :将程序运行结果输入到file1中
  */
#include<iostream>
#include<stdlib.h>
using namespace std;

int main(void)
{
	//1  原型cout.put(char c)
	cout.put('A'), cout.put(33 + 66),cout.put('\n');  //输出单个字符A  c并换行 
	cout << "---------" << endl;
	//2  常用形式cin.get(ch)
	char ch;
	while(cin.get(ch))   //get函数类似>> 但是包含空格符  如输入123 xy  则原样输出
		cout.put(ch);    //输入Ctrl+Z加回车则是文件结束符EOF 结束
	cout << "---------" << endl;
	//3  cin.getline(字符数组或字符指针,字符个数,终止字符)从输入流读取n-1个字符 并在结尾以'\n'结尾
	char line[10];
	cin.getline(line, 10, 'l');  //读入9个字符或者遇到'l'结束 'l'不读出
	cout << line;
	cout << "---------" << endl;
	system("pause");
}