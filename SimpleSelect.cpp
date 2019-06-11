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

void SimpleSelect(SqList *L){
	int i,j,min;
	for(i = 1; i < L->lenght; ++i){
		min = i;
		for(j = i + 1; j <= L->lenght; ++j){
			if(L->myarray[min] > L->myarray[j]){
				min = j;
			}
		}
		if(i!=min){
			Swap(L,i,min);
		}
	}
}