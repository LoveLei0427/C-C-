#define MAXSIZE 1024

typedef struct{
	
	int myarray[MAXSIZE];
	int length;
}SqList;

void Swap(SqList *L, int i, int j){
	int temp = L->myarray[i];
	L->myarray[i] = myarray[j];
	L->myarray[j] = myarray[i];
}

void PrintNum(SqList *L){
	int i;
	for(i = 1; i < L.length; ++i)
		cout << L->myarray[i] << endl;
	cout<<L->myarray[i];
}






void QuickSort(SqList *L){
	QSort(L,1,L->length);
}
void QSort(SqList *L, int low, int high){
	int pivot;
	if(low < high){
		pivot = Partition(L,low,high);
		QSort(L,low,pivot-1);
		QSort(L,pivot+1,high);
	}
}
int Partition(SqList *L, int low, int high){
	int pivotkey = L->myarray[low];
	while(low < high){
		while(low < high && L->myarray[high] >= pivotkey){
			high--;
		}
		Swap(L,low,high);
		while(low < high && L->myarray[low] <= pivotykey){
			low++;
		}
		Swap(L,low,high);
	}
	return low;
}
