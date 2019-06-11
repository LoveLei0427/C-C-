int getMaxValue(const int* myarray, int rows, int cols){
    if(valuse == nullptr || rows <= 0 || cols <= 0){
	return 0;
    }
    int *max_value = new int[cols];
    for(int i = 0; i < rows; ++i){
	for(int j = 0; j < cols; ++j){
	    int left = 0;
	    int up = 0;
            if(i > 0){
	        up = max_value[j];
	    }	    
	    if(j > 0){
	        left = max_value[j-1];
	    }
	    max_value[j]=std::max(left,up)+myarray[i*cols+j];
	}
    }
    int max_result = max_value[cols-1];    
    delete[] max_value;
    return max_result;
}
