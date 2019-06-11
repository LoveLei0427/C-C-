//线性表顺序存储 关键码有序
int BinarySearching(int *myarray, int length, int key){
	int low = 0;
	int high = length-1;
	int middle = 0;
	while(low<=high){
		
		middle = int((low+high)/2);
		if(key == myarray[middle]){
			return middle;
		}
		else if(key < myarray[middle]){
			high =middle - 1;
		}
		else{
			low = middle + 1;
		}
	}
	return -1;
}
//递归
int BinarySearching(int *myarray, int start, int end, int key){
	if(start > end)
		return -1;
	int middle = int((start+end)/2;
	if(key == myarray[middle]){
		return middle;
	}
	else if(key < myarray[middle]){
		return BinarySearching(myarray,start,middle-1,key);
	}
	else{
		return BinarySearching(myarray,middle+1,end,key);
	}
}
