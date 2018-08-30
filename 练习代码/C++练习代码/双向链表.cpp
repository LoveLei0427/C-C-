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
		cout << "��ţ�" << num << "������" << name <<
			"�Ա�" << sex << "�ɼ���" << grade << endl;
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
		cout << "��������" << endl;
		cout << "��ţ�"; cin >> m.num;
		cout << "������"; cin >> m.name;
		cout << "�Ա�"; cin >> m.sex;
		cout << "�ɼ���"; cin >> m.grade;
	}
	void InsertAfter()
	{
		int i,n;
		data a;
		Node *p;
		p = new Node;
		cout << "����Ҫ����ڼ���Ԫ�صĺ���" << endl;
		cin >>n;
		Pri(a);
		p->x= a;
		current = head;
		if (current->next == NULL)
		{
			cout << "����Ϊ��" << endl;
			cout << "������һ�����" << endl;
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
			cout << "����" << endl;
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
		cout << "����Ҫ����ڼ���Ԫ�ص�ǰ��" << endl;
		cin >> n;
		Pri(a);
		p->x = a;
		current = head;
		if (z==0)
		{
			cout << "����Ϊ��,��Ԫ��" << endl;
			cout << "������һ�����" << endl;
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
			cout << "����Ϊ�գ�" << endl;
		}
		else cout << "�����ѽ���������" <<z<<"���ڵ�"<< endl;
	}
	void GetCount()
	{
		cout << "����Ϊ��" <<  endl;
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
		cout << "����Ҫ�õ��ڼ���Ԫ��" << endl;
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
		cout << "����Ҫ�޸ĵڼ���Ԫ��" << endl;
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
			cout << "�޸ĺ������Ϊ��" ;
			current->x.print();
		}
		else cout << "ERROR" << endl;
	}
	void RemoveAt()
	{
		Node*p;
		int i,n;
		cout << "����Ҫɾ���ڼ���Ԫ��" << endl;
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
			cout << "����Ϊ��" << endl;
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
			cout << "ջΪ�գ�" << endl;
		}
		else cout << "ջ�ѽ���������" << m << "���ڵ�" << endl;
	}
	void GetCount()
	{
		cout << "ջΪ��" << endl;
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
			cout << "����Ϊ�գ�" << endl;
		}
		else cout << "�����ѽ���������" << m << "���ڵ�" << endl;
	}
	void GetCount()
	{
		cout << "����Ϊ��" << endl;
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
		cout << "                    ����ѡ��" << endl;
		cout << "a                   �����ʼ��" << endl;
		cout << "s                   �������״��" << endl;
		cout << "d                   ����ǰԪ��" << endl;
		cout << "f                   �����Ԫ��" << endl;
		cout << "g                   �õ�ָ��Ԫ��" << endl;
		cout << "h                   �޸�ָ��Ԫ��" << endl;
		cout << "j                   ɾ��ָ��Ԫ��" << endl;
		cout << "z                   �������" << endl;
		cout << "x                   ɾ������" << endl;
		cout << "****************************************************" << endl;
		cout << "     ѡ����:   " ;
		cin >> n;
		switch (n)
		{
		case 'a':
			L1; 
			cout << "��ʼ�����" << endl; break;
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