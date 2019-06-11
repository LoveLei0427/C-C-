/*模板申明带3个参数：priority_queue<Type, Container, Functional>
 * 其中Type 为数据类型Container为保存数据的容器Functional 为元素比较方式
 *底层是堆  堆首元素优先级最高
 * */
//排序矩阵第k小的数
int findKthMin1(vector<vector<int>> &matrix, unsigned int k)
{ 
	int n = matrix.size(); 
	int m = matrix[0].size(); 
	vector<vector<int>> visit(n, vector<int>(m));
	/*priority_queue<Type, Container, Functional>，其中Type 为数据类型，Container为保存数据的容器，Functional为元素比较方式。Container必须是用数组实现的容器，如vector,deque等，但不能用list。STL里面默认是vector。*/
   	//初始化最小堆 
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

