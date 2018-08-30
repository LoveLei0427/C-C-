#include"stdio.h"
int main()
{
  int score,n;
  scanf("%d",&score);
  if(score<60) n=0;
  else n=1+(score-60)/10;
  switch (n)
  {
  case 0: putchar('E');break;
  case 1: putchar('D');break;
  case 2: putchar('C');break;
  case 3: putchar('B');break;
  case 4: 
  case 5: putchar('A');break;
  default: putchar('\a')
  }
	return 0;
}