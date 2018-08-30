#include <stdio.h>
#define R 21
int main ()
{
        int i, j;    
        for(i=0; i<R; i++)
        {
                /*根据行数 计算当前行应该输出 多少个空格*/
                j=abs(R/2-i);  
                /*如果为0 则不输出空格*/
                if(j) printf("%*c", j, ' ');
                /*打印左边的星号*/
                printf("*");
                /*根据行数i计算应该空多少个空格*/
                j=((R/2-j+1))*2-1;
                /*前两行和倒数两行 不用输出空格*/
                if(i>=1 && i<=R-2) printf("%*c", j-2, ' ');
                /*第一行和倒数第一行不用输出星号*/
                if(i>0 && i<R-1) printf("*");
                /*每次循环换行*/
                printf("\n");
        }
}
