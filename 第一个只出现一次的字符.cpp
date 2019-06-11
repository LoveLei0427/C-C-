char FirstNotRepeating(char *pString){
	if(pString==nullptr)
		return '\0';
	const int size = 256;
	unsigned int hashTable[size];
	for(unsigned int i = 0; i < size; ++i){
		hashTable[i] = 0;
	}
	char *phashkey = pString;
	while(*(phashkey)!='\0'){
		hashTable[*(phashkey++)]++;
	}
	phashkey = pString;
	while(*phashkey!='\0'){
		if(hashTable[*phashkey]==1){
			return *phashkey;
		}
		phashkey++;
	}
	return '\0';
}