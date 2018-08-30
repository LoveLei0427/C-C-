#include<iostream>
#include<string>
#include<stdlib.h>
void main()
{
	//R"()"可以去掉转义字符，防止因为路径错误而打不开的情况
	std::string path=R"("C:\Users\Administrator\Desktop\课表.png")";
	system(path.c_str());
	system("pause");
}