/*ģ��������3��������priority_queue<Type, Container, Functional>
 * ����Type Ϊ��������ContainerΪ�������ݵ�����Functional ΪԪ�رȽϷ�ʽ
 *�ײ��Ƕ�  ����Ԫ�����ȼ����
 * */
//��������kС����
int findKthMin1(vector<vector<int>> &matrix, unsigned int k)
{ 
	int n = matrix.size(); 
	int m = matrix[0].size(); 
	vector<vector<int>> visit(n, vector<int>(m));
	/*priority_queue<Type, Container, Functional>������Type Ϊ�������ͣ�ContainerΪ�������ݵ�������FunctionalΪԪ�رȽϷ�ʽ��Container������������ʵ�ֵ���������vector,deque�ȣ���������list��STL����Ĭ����vector��*/
   	//��ʼ����С�� 
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q; 
	q.push(make_pair(0, 0)); 
	visit[0][0] = true; 
	while (k--) 
	{ 
		pair<int, int>p = q.top(); 
		if (k == 0) 
			break; 
		q.pop(); 
		int x = p.first; 
		int y = p.second; 
		if (x + 1 < n && visit[x + 1][y] == false) 
		{ 
			visit[x + 1][y] = true;
		       	q.push(make_pair(x + 1, y)); 
		} 
		if (y + 1 < m && visit[x][y + 1] == false) 
		{ 
			visit[x][y + 1] = true;
			q.push(make_pair(x, y + 1));
		} 
	} 
	pair<int, int> p = q.top(); 
	return matrix[p.first][p.second];	
}

