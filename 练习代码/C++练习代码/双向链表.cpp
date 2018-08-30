#include <iostream>
#include <string>
using namespace std;
class data{
public:	
	int num;
	string name;
	int grade;
	string sex;
	data()
	{
		num = 0; name = "";
		grade = 0; sex = "";
	}
	data(int x, string y, int z, string s)
	{
		num = x; name = y;
		grade = z; sex = s;
	}
	void print()
	{
		cout << "编号：" << num << "姓名：" << name <<
			"性别：" << sex << "成绩：" << grade << endl;
	}
};
class Node:public data{
public:
	data  x;
	Node *prior;
	Node *next;
	Node()
	{
		data x(0, "", 0, "" );
		prior = next = NULL;
	}
	Node(int x, string y, int z, string s) :x(x, y, z, s)
	{
		prior = next = NULL;
	}
};
class List{
	int z;
protected:
	Node *current;
	Node *head;
	Node *tail;
public:
	List() 
	{
		head = new Node;
		tail = head;
		head->next = NULL;
		head->prior = head;
		z = 0;
	}
	void Pri(data &m)
	{
		cout << "输入数据" << endl;
		cout << "编号："; cin >> m.num;
		cout << "姓名："; cin >> m.name;
		cout << "性别："; cin >> m.sex;
		cout << "成绩："; cin >> m.grade;
	}
	void InsertAfter()
	{
		int i,n;
		data a;
		Node *p;
		p = new Node;
		cout << "输入要插入第几个元素的后面" << endl;
		cin >>n;
		Pri(a);
		p->x= a;
		current = head;
		if (current->next == NULL)
		{
			cout << "链表为空" << endl;
			cout << "建立第一个结点" << endl;
		}
		else for (i = 0; i < n; i++)
		{
			current = current->next;
		}
		if (z==0)
		{
			p->next = current->next;
			current->next = p;
		}
		else if (n==z)
		{
			p->next = current->next;
			p->prior = current;
			current->next = p;
		}
		else if (n<z && n>0)
		{
			p->next = current->next;
			p->prior = p->next->prior;
			current->next = p;
			p->next->prior = current->next;
		}
		else
		{
			cout << "错误" << endl;
		}
		while (current->next != NULL)
		{
			current = current->next;
		}
		tail = current;
		++z;
	}
	void InsertBefore()
	{
		int i,n;
		data a;
		Node *p;
		p = new Node;
		cout << "输入要插入第几个元素的前面" << endl;
		cin >> n;
		Pri(a);
		p->x = a;
		current = head;
		if (z==0)
		{
			cout << "链表为空,无元素" << endl;
			cout << "建立第一个结点" << endl;
		}
		else 
		{
			for (i = 1; i < n; i++)
			{
				current = current->next;
			}
		}
		if (z==0)
		{
			p->next = current->next;
			current->next = p;
		}
		else if (z>=n&&n==1)
		{
			p->next = current->next;
			current->next->prior = p;
			current->next = p;
		}
		else if (1<n && n<=z)
		{
			p->next = current->next;
			p->prior = p->next->prior;
			current->next = p;
			p->next->prior = current->next;
	
		}
		else
		{
			cout << "ERROR" << endl;
		}
		while (current->next != NULL)
		{
			current = current->next;
		}
		tail = current;
		++z;
	}
	void RemoveHead()
	{
		Node *p;
		p = head;
		head = head->next;
		delete p;
	}
	void RemoveTail()
	{
		Node *p;
		p = tail;
		tail = tail->prior;
		delete p;
	}
	void AddHead()
	{
		data p;
		Pri(p);
		head->x=p;
		head->next->prior=head;
	}
	void RemoveAll()
	{
		Node*p;
		current = head->next;
		while (current != NULL)
		{
			p = current;
			current = current->next;
			delete p;
		}
	}
	void IsEmpty()
	{
		if (z==0)
		{
			cout << "链表为空！" << endl;
		}
		else cout << "链表已建立，共有" <<z<<"个节点"<< endl;
	}
	void GetCount()
	{
		cout << "链表为：" <<  endl;
		Node*p;
		p = head->next;
		while (p != NULL)
		{
			p->x.print();
			p = p->next;
		}
	}
	void GetAt()
	{
		int i,n;
		cout << "输入要得到第几个元素" << endl;
		cin >> n;
		current = head;
		if (z >= n)
		{
			for (i = 0; i < n; i++)
			{
				current = current->next;
			}
			current->x.print();
		}
		else cout << "ERROR" << endl;
	}
	void SetAt()
	{
		int i,n;
		data a;
		cout << "输入要修改第几个元素" << endl;
		cin >> n;
		current = head;
		if (z >= n)
		{
			for (i = 0; i < n; i++)
			{
				current = current->next;
			}
			Pri(a);
			current->x = a;
			cout << "修改后的数据为：" ;
			current->x.print();
		}
		else cout << "ERROR" << endl;
	}
	void RemoveAt()
	{
		Node*p;
		int i,n;
		cout << "输入要删除第几个元素" << endl;
		cin >> n;
		current = head;
		if (z != 0)
		{
			for (i = 1; i < n; i++)
			{
				current = current->next;
			}
		}
		p = current->next;
		if (z == 0)
		{
			cout << "链表为空" << endl;
		}
		else if ((z == n) || (z >= n && n == 1))
		{
			current->next = current->next->next;
		}
		else if (n < z&&n>1)
		{
			current->next = current->next->next;
			current->next->prior = current;
		}
		else cout << "ERROR" << endl;
		delete p;
	}	
	data GetHead()
	{
		return head->x;
	}
	data GetTail()
	{
		return tail->x;
	}
	~List()
	{
		delete head;
	}
};
class Set :public List
{
public:
	
};
class Stack :public List
{
	int m;
public:
	Stack()
	{
		head = new Node;
		tail = head;
		m = 0;
	}
	void Insert()
	{
		data a;
		Node *p;
		p = new Node;
		Pri(a);
		p->x = a;
		head = p;
		p->next = tail;
		++m;
	}
	void IsEmpty()
	{
		if (m == 0)
		{
			cout << "栈为空！" << endl;
		}
		else cout << "栈已建立，共有" << m << "个节点" << endl;
	}
	void GetCount()
	{
		cout << "栈为：" << endl;
		Node*p;
		p = head;
		while (p != NULL)
		{
			p->x.print();
			p = p->next;
		}
	}
	void Remove()
	{
		Node *p;
		p = head;
		head=head->next;
		delete p;
	}
	~Stack()
	{
		delete head;
	}
};
class Queue :public List
{
	int m;
public:
	Queue()
	{
		head = new Node;
		tail = head;
		m = 0;
	}
	void IsEmpty()
	{
		if (m == 0)
		{
			cout << "队列为空！" << endl;
		}
		else cout << "队列已建立，共有" << m << "个节点" << endl;
	}
	void GetCount()
	{
		cout << "队列为：" << endl;
		Node*p;
		p = head->next;
		while (p != NULL)
		{
			p->x.print();
			p = p->next;
		}
	}
};
int main()
{
	char n;
	List L1;
	Stack s;
	while (1)
	{	
		cout << "***************************************************" << endl;
		cout << "                    功能选项" << endl;
		cout << "a                   链表初始化" << endl;
		cout << "s                   检测链表状况" << endl;
		cout << "d                   插入前元素" << endl;
		cout << "f                   插入后元素" << endl;
		cout << "g                   得到指定元素" << endl;
		cout << "h                   修改指定元素" << endl;
		cout << "j                   删除指定元素" << endl;
		cout << "z                   输出链表" << endl;
		cout << "x                   删除链表" << endl;
		cout << "****************************************************" << endl;
		cout << "     选择功能:   " ;
		cin >> n;
		switch (n)
		{
		case 'a':
			L1; 
			cout << "初始化完成" << endl; break;
		case 's':
			L1.IsEmpty(); break;
		case 'd':
			L1.InsertBefore(); break;
		case 'f':
			L1.InsertAfter(); break;
		case 'g':
			L1.GetAt(); break;
		case'h':
			L1.SetAt(); break; 
		case'j':
			L1.RemoveAt(); break;
		case'z':
			L1.GetCount(); break;
		case'x':
			L1.RemoveAll(); break;
		case 'm':
			s; s.IsEmpty();
			s.Insert(); s.Insert(); s.IsEmpty(); s.GetCount(); s.RemoveAll();
		default:
			cout << "ERROR" << endl; break;
		}
	}
	return 0;
}