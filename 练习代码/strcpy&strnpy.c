#include <stdio.h>
#include <assert.h>
char *my_strcpy(char *dst,const char *src);
void * my_memcpy(void *dst,const void *src,unsigned int count);
int main(void)
{
    char *strSrc = "hello world!";
    char strDest[20] = {0};
    char strDect[20] = {0};
    printf("strSrc = %s\n", strSrc);
    my_strcpy(strDest, strSrc);
    printf("strDest = %s\n", strDest);
    my_memcpy(strDect, strSrc, 3);
    printf("strDect = %s\n", strDect);

}
char *my_strcpy(char *dst,const char *src)
{
    assert(dst != NULL);
    assert(src != NULL);
    char *ret = dst;
    //memcpy(dst,src,strlen(src)+1);
    while ((*dst++ = *src++) != '\0');
    return ret;
}

void * my_memcpy(void *dst,const void *src,unsigned int count)
{
     assert(dst);
     assert(src);
     void * ret = dst;
     if (dst <= src || (char *)dst >= ((char *)src + count))//源地址和目的地址不重叠，低字节向高字节拷贝
     {
         while(count--)
         {
             *(char *)dst = *(char *)src;
             dst = (char *)dst + 1;
             src = (char *)src + 1;
         }
     }
     else						//源地址和目的地址重叠，高字节向低字节拷贝
     {
         dst = (char *)dst + count - 1;
         src = (char *)src + count - 1;
         while(count--)
         {
             *(char *)dst = *(char *)src;
             dst = (char *)dst - 1;
             src = (char *)src - 1;
         }
    }
    return ret;
}