//�ȷ�ת�������ӣ��ٷ�תÿ�������е�ÿ������
void Reverse(char *begin,char *end){
	if(begin==nullptr||end==nullptr){
		return ;
	}
	while(begin<end){
		char temp = *begin;
		*begin = *end;
		*end = temp;
		begin++;
		end++;
	}
}

char *ReverseSentence(char *data){
	if(data==nullptr){
		return nullptr;
	}
	char *begin = data;
	char *end = data;
	while(*data!='\0'){
		end++;
	}
	end--;
	//��ת��������
	Reverse(begin,end);
	begin = end = data;
	while(*begin!='\0'){
		if(*begin==''){
			begin++;
			end++;
		}else if(*end==''||*end=='\0'){
			Reverse(begin,--end);
			begin == ++end;
		}else{
			end++;
		}
	}
	return data;
}