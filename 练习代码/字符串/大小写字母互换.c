#include<stdio.h>
#include<windows.h>
int main()
{		
	while(1)
	{
		char ch = getchar();
		if(ch>='A'&&ch<='Z')  
		{
			ch = ch + 32;
			putchar(ch);
		}
		else if(ch>='a'&&ch<='z')  
		{
			ch = ch - 32;
			putchar(ch);
		}
	}
	system("pause...");
}

»òÕß£º		char ch = getchar();
		(ch>='A'&&ch<='Z') ? (ch = ch + 32) : ((ch>='a'&&ch<='z') ? (ch -= 32) : ch);	
		putchar(ch);		