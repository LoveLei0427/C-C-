/*iostream.h ����������������/���������Ļ�����Ϣ cin cout cerr clog����
  iomanip.h ������ʽ��I/O��������
  cin istream�����,һ�����Ӽ��� �����ض���
  cout ostream�����,һ��������ʾ�� �����ض���
  cerr ostream�����,������ʾ�� �����ض���
  clog ostream�����,���Ӵ�ӡ�� �����ض���
  ����<file2:��file2������Ϊ�������뵽����
  ����>file1 :���������н�����뵽file1��
  */
#include<iostream>
#include<stdlib.h>
using namespace std;

int main(void)
{
	//1  ԭ��cout.put(char c)
	cout.put('A'), cout.put(33 + 66),cout.put('\n');  //��������ַ�A  c������ 
	cout << "---------" << endl;
	//2  ������ʽcin.get(ch)
	char ch;
	while(cin.get(ch))   //get��������>> ���ǰ����ո��  ������123 xy  ��ԭ�����
		cout.put(ch);    //����Ctrl+Z�ӻس������ļ�������EOF ����
	cout << "---------" << endl;
	//3  cin.getline(�ַ�������ַ�ָ��,�ַ�����,��ֹ�ַ�)����������ȡn-1���ַ� ���ڽ�β��'\n'��β
	char line[10];
	cin.getline(line, 10, 'l');  //����9���ַ���������'l'���� 'l'������
	cout << line;
	cout << "---------" << endl;
	system("pause");
}