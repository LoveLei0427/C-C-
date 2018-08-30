#include"stdio.h"
#include"string.h"
int main()
{
	char str1[25]={"000000beautiful girl."};
	char str2[]={"hello!"};
	printf("%s",strncpy(str1,str2,6));
	printf("\n");
	return 0;
}