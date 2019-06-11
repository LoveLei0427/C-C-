#include<iostream>
#include<ctime>
#include<cstring>
#include<cstdlib>
using namespace std;
/**��a��ͷ�ĳ�Ϊlength�������b��ͷ��Ϊright������ϲ�nΪ���鳤�ȣ��������һ��*/
void��Merge(int*��data,int��a,int��b,int��length,int��n){
��int��right;
��if(b+length-1 >= n-1)��right = n-b;
��else��right = length;
��int*��temp = new��int[length+right];
��int��i=0, j=0;
��while(i<=length-1 && j<=right-1){
    ��if(data[a+i] <= data[b+j]){
    ��    temp[i+j] = data[a+i];i++;
      }
    ��else{
        temp[i+j] = data[b+j];
        j++;
      }
��}
��if(j == right){//a�л���Ԫ�أ���ȫ����b�еĴ�,a[i]��δʹ��
��  memcpy(temp + i + j, data + a + i, (length - i) * sizeof(int));
��}
  else if(i == length){
      memcpy(temp + i + j, data + b + j, (right - j)*sizeof(int));
  }
��memcpy(data+a, temp, (right + length) * sizeof(int));
��delete [] temp;
}
void��MergeSort(int*��data, int��n){
��int��step = 1;
��while(step < n){
    ��for(int��i=0; i<=n-step-1; i+=2*step)
    ��    Merge(data, i, i+step, step, n);
    //��i��i+step�������������н��кϲ�
    //���г���Ϊstep
    //��i�Ժ�ĳ���С�ڻ��ߵ���stepʱ���˳�
    ��step*=2;//�ڰ�ĳһ�����鲢����֮�󣬲����ӱ�
��}
}
int��main(){
��int��n;
��cin>>n;
��int*��data = new��int[n];
��if(!data)��exit(1);
��int��k = n;
��while(k--){
��    cin>>data[n-k-1];
��}
��clock_t��s = clock();
��MergeSort(data, n);
��clock_t��e = clock();
��k=n;
��while(k--){
��    cout<<data[n-k-1]<<' ';
��}
��cout<<endl;
��cout<<"the algorithm used"<<e-s<<"miliseconds."<<endl;
��delete��data;
��return��0;
}
 
//�ݹ��㷨��
#include<iostream>
using namespace std;
void merge(int *data, int start, int mid, int end, int *result)
{
    int i, j, k;
    i = start;
    j = mid + 1;                        //�����ظ��Ƚ�data[mid]
    k = 0;
    while (i <= mid && j <= end)        //����data[start,mid]������(mid,end]��û��ȫ����������result��ȥ
    {
        if (data[i] <= data[j])         //���data[i]С�ڵ���data[j]
            result[k++] = data[i++];    //��data[i]��ֵ����result[k]��֮��i,k����һ����ʾ����һλ
        else
            result[k++] = data[j++];    //���򣬽�data[j]��ֵ����result[k]��j,k����һ
    }
    while (i <= mid)                    //��ʾ����data(mid,end]�Ѿ�ȫ������result������ȥ�ˣ�������data[start,mid]����ʣ��
        result[k++] = data[i++];        //������data[start,mid]ʣ�µ�ֵ����һ��������result
    while (j <= end)                    //��ʾ����data[start,mid]�Ѿ�ȫ�����뵽result������ȥ�ˣ�������(mid,high]����ʣ��
        result[k++] = data[j++];        //������a[mid,high]ʣ�µ�ֵ����һ��������result
 
    for (i = 0; i < k; i++)             //���鲢��������ֵ��һ��������data[start,end]
        data[start + i] = result[i];    //ע�⣬Ӧ��data[start+i]��ʼ��ֵ
}
void merge_sort(int *data, int start, int end, int *result)
{
    if (start < end)
    {
        int mid = start + (end-start) / 2;//�������int
        merge_sort(data, start, mid, result);                    //����߽�������
        merge_sort(data, mid + 1, end, result);                  //���ұ߽�������
        merge(data, start, mid, end, result);                    //������õ����ݺϲ�
    }
}
void amalgamation(int *data1, int *data2, int *result)
{
    for (int i = 0; i < 10; i++)
        result[i] = data1[i];
    for (int i = 0; i < 10; i++)
        result[i + 10] = data2[i];
}
int main()
{
    int data1[10] = { 1,7,6,4,9,14,19,100,55,10 };
    int data2[10] = { 2,6,8,99,45,63,102,556,10,41 };
    int *result = new int[20];                              
    int *result1 = new int[20];
    amalgamation(data1, data2, result);
    for (int i = 0; i < 20; ++i)
        cout << result[i] << "  ";
    cout << endl;
    merge_sort(result, 0, 19, result1);
    for (int i = 0; i < 20; ++i)
        cout << result[i] << "  ";
    delete[]result;
    delete[]result1;
    return 0;
}
//----------------------------------------------------------
// �ݹ鷨 
/* ��src[s..t]�鲢����Ϊdst[s..t] */
void MSort(int src[],int dst[],int s, int t)
{
	int m;
	int dst2[MAXSIZE+1];
	if(s==t)
		dst[s]=src[s];
	else
	{
		m=(s+t)/2;				/* ��src[s..t]ƽ��Ϊsrc[s..m]��SR[m+1..t] */
		MSort(src,dst2,s,m);		/* �ݹ�ؽ�src[s..m]�鲢Ϊ�����dst[s..m] */
		MSort(src,dst2,m+1,t);	/* �ݹ�ؽ�SR[m+1..t]�鲢Ϊ�����dst[m+1..t] */
		Merge(src,dst2,s,m,t);	/* ��dst[s..m]��dst[m+1..t]�鲢��[s..t] */
	}
}
/* �������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n] */
void Merge(int src[],int dst[],int start,int part,int end)
{	//��src[start:part] src[part+1:end]�ϲ���dst[start:n]��
	int j,k,l;
	for(j=part+1,k=start;start<=part && j<=end;k++)	
	{
		if (src[start]<src[j])
			dst[k]=src[start++];
		else
			dst[k]=src[j++];
	}
	if(start<=part)
	{
		for(l=0;l<=part-start;l++)
			dst[k+l]=src[start+l];		/* ��ʣ���src[i..m]���Ƶ�dst */
	}
	if(j<=end)
	{
		for(l=0;l<=end-j;l++)
			dst[k+l]=src[j+l];		/* ��ʣ���Ssrc[j..n]���Ƶ�dst */
	}
}
//�ǵݹ鷨
void MergeSort2(SqList *L)
{
	int* saveSpace=(int*)malloc(L->length * sizeof(int));/* �������ռ� */
    int len=1;
	while(len<L->length)
	{
		MergePass(L->r,saveSpace,len,L->length);
		len=2*len;/* �����г��ȼӱ� */
		MergePass(saveSpace,L->r,len,L->length);
		len=2*len;/* �����г��ȼӱ� */       
	}
}
void MergePass(int src[],int dst[],int low,int high)
{
	int i=1;
	int j;
	while(i <= high-2*low+1)
	{/* �����鲢 */
		Merge(src,dst,i,i+low-1,i+2*low-1); //��һ�ν�1 2������¼�鲢��dst��
		i=i+2*low;        //ѭ��3 4��5 6 �� 7 8 ����¼
	}
	/* �鲢����������� */
	if(i<high-low+1) 
		Merge(src,dst,i,i+low-1,high);
	/* �����ֻʣ�µ��������� */
	else 
		for(j =i;j <= high;j++)
			dst[j] = src[j];
}

