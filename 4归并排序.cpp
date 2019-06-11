#include<iostream>
#include<ctime>
#include<cstring>
#include<cstdlib>
using namespace std;
/**将a开头的长为length的数组和b开头长为right的数组合并n为数组长度，用于最后一组*/
void　Merge(int*　data,int　a,int　b,int　length,int　n){
　int　right;
　if(b+length-1 >= n-1)　right = n-b;
　else　right = length;
　int*　temp = new　int[length+right];
　int　i=0, j=0;
　while(i<=length-1 && j<=right-1){
    　if(data[a+i] <= data[b+j]){
    　    temp[i+j] = data[a+i];i++;
      }
    　else{
        temp[i+j] = data[b+j];
        j++;
      }
　}
　if(j == right){//a中还有元素，且全都比b中的大,a[i]还未使用
　  memcpy(temp + i + j, data + a + i, (length - i) * sizeof(int));
　}
  else if(i == length){
      memcpy(temp + i + j, data + b + j, (right - j)*sizeof(int));
  }
　memcpy(data+a, temp, (right + length) * sizeof(int));
　delete [] temp;
}
void　MergeSort(int*　data, int　n){
　int　step = 1;
　while(step < n){
    　for(int　i=0; i<=n-step-1; i+=2*step)
    　    Merge(data, i, i+step, step, n);
    //将i和i+step这两个有序序列进行合并
    //序列长度为step
    //当i以后的长度小于或者等于step时，退出
    　step*=2;//在按某一步长归并序列之后，步长加倍
　}
}
int　main(){
　int　n;
　cin>>n;
　int*　data = new　int[n];
　if(!data)　exit(1);
　int　k = n;
　while(k--){
　    cin>>data[n-k-1];
　}
　clock_t　s = clock();
　MergeSort(data, n);
　clock_t　e = clock();
　k=n;
　while(k--){
　    cout<<data[n-k-1]<<' ';
　}
　cout<<endl;
　cout<<"the algorithm used"<<e-s<<"miliseconds."<<endl;
　delete　data;
　return　0;
}
 
//递归算法：
#include<iostream>
using namespace std;
void merge(int *data, int start, int mid, int end, int *result)
{
    int i, j, k;
    i = start;
    j = mid + 1;                        //避免重复比较data[mid]
    k = 0;
    while (i <= mid && j <= end)        //数组data[start,mid]与数组(mid,end]均没有全部归入数组result中去
    {
        if (data[i] <= data[j])         //如果data[i]小于等于data[j]
            result[k++] = data[i++];    //则将data[i]的值赋给result[k]，之后i,k各加一，表示后移一位
        else
            result[k++] = data[j++];    //否则，将data[j]的值赋给result[k]，j,k各加一
    }
    while (i <= mid)                    //表示数组data(mid,end]已经全部归入result数组中去了，而数组data[start,mid]还有剩余
        result[k++] = data[i++];        //将数组data[start,mid]剩下的值，逐一归入数组result
    while (j <= end)                    //表示数组data[start,mid]已经全部归入到result数组中去了，而数组(mid,high]还有剩余
        result[k++] = data[j++];        //将数组a[mid,high]剩下的值，逐一归入数组result
 
    for (i = 0; i < k; i++)             //将归并后的数组的值逐一赋给数组data[start,end]
        data[start + i] = result[i];    //注意，应从data[start+i]开始赋值
}
void merge_sort(int *data, int start, int end, int *result)
{
    if (start < end)
    {
        int mid = start + (end-start) / 2;//避免溢出int
        merge_sort(data, start, mid, result);                    //对左边进行排序
        merge_sort(data, mid + 1, end, result);                  //对右边进行排序
        merge(data, start, mid, end, result);                    //把排序好的数据合并
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
// 递归法 
/* 将src[s..t]归并排序为dst[s..t] */
void MSort(int src[],int dst[],int s, int t)
{
	int m;
	int dst2[MAXSIZE+1];
	if(s==t)
		dst[s]=src[s];
	else
	{
		m=(s+t)/2;				/* 将src[s..t]平分为src[s..m]和SR[m+1..t] */
		MSort(src,dst2,s,m);		/* 递归地将src[s..m]归并为有序的dst[s..m] */
		MSort(src,dst2,m+1,t);	/* 递归地将SR[m+1..t]归并为有序的dst[m+1..t] */
		Merge(src,dst2,s,m,t);	/* 将dst[s..m]和dst[m+1..t]归并到[s..t] */
	}
}
/* 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n] */
void Merge(int src[],int dst[],int start,int part,int end)
{	//将src[start:part] src[part+1:end]合并到dst[start:n]中
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
			dst[k+l]=src[start+l];		/* 将剩余的src[i..m]复制到dst */
	}
	if(j<=end)
	{
		for(l=0;l<=end-j;l++)
			dst[k+l]=src[j+l];		/* 将剩余的Ssrc[j..n]复制到dst */
	}
}
//非递归法
void MergeSort2(SqList *L)
{
	int* saveSpace=(int*)malloc(L->length * sizeof(int));/* 申请额外空间 */
    int len=1;
	while(len<L->length)
	{
		MergePass(L->r,saveSpace,len,L->length);
		len=2*len;/* 子序列长度加倍 */
		MergePass(saveSpace,L->r,len,L->length);
		len=2*len;/* 子序列长度加倍 */       
	}
}
void MergePass(int src[],int dst[],int low,int high)
{
	int i=1;
	int j;
	while(i <= high-2*low+1)
	{/* 两两归并 */
		Merge(src,dst,i,i+low-1,i+2*low-1); //第一次将1 2两个记录归并到dst中
		i=i+2*low;        //循环3 4和5 6 及 7 8 条记录
	}
	/* 归并最后两个序列 */
	if(i<high-low+1) 
		Merge(src,dst,i,i+low-1,high);
	/* 若最后只剩下单个子序列 */
	else 
		for(j =i;j <= high;j++)
			dst[j] = src[j];
}

