#define MAXSIZE 1024

typedef struct{
	
	int myarray[MAXSIZE];
	int length;
}SqList;

void Swap(SqList *L, int i, int j){
	int temp = L->myarray[i];
	L->myarray[i] = L->myarray[j];
	L->myarray[j] = L->myarray[i];
}

void PrintNum(SqList *L){
	int i;
	for(i = 1; i < L.length; ++i)
		cout << L->myarray[i] << endl;
	cout<<L->myarray[i];
}

//1、原始
void BubbleSort1(SqList *L){
	int i,j;
	for(i = 1; i < L->lenght; ++i){
		for(j = i + 1; j <= L->lenght; ++j){
			if(L->myarray[i] < L->myarray[j]){
				Swap(L,i,j);
			}
		}
	}
}
//2、优化
void BubbleSort2(SqList *L){
	int i,j;
	for(i = 1; i < L->lenght; ++i){
		for(j = L->length-1; j >= i; j--){
			if(L->myarray[j] > L->myarray[j+1]){
				Swap(L,j+1,j);
			}
		}
	}
}
//3、改进
void BubbleSort3(SqList *L){
	int i,j;
	bool flag = TRUE;
	for(i = 1; i < L->length && flag;i++){
		flag = FALSE;
		for(j = L-length -1; j >= i; j--){
			if(L->myarray[j]>L->myarray[j+1]){
				Swap(L,j,j+1);
				flag = TRUE;
			}
		}
	}
}