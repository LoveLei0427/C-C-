#include<iostream>
#include<string>
#include<stdlib.h>
void main()
{
	//R"()"����ȥ��ת���ַ�����ֹ��Ϊ·��������򲻿������
	std::string path=R"("C:\Users\Administrator\Desktop\�α�.png")";
	system(path.c_str());
	system("pause");
}