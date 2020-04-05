#include <stdio.h>
#include <strings.h>
#include<limits.h>


//char 一个字节 char* char数组
typedef unsigned char *bytes_pointer;

void show_bytes(bytes_pointer start, size_t len)
{
    //printf("sizeof(bytes_pointer) %lu\t",sizeof(bytes_pointer));
    size_t i;
    for (size_t i = 0; i < len; i++)
    {
        printf("%.2x-", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    show_bytes((bytes_pointer)&x, sizeof(int));
}

void show_float(float x)
{
   show_bytes((bytes_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((bytes_pointer)&x, sizeof(void *));
}

void test_show_bytes(int val){
    int ival = val;
    float fval = (float)val;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main(){
    //4个字节 0x00003039
    //大端法
    test_show_bytes(12345);
    const char * s="abcdef";
    const char * s1="gh";
    //内存泄漏
    show_bytes ((bytes_pointer)s,strlen(s)+3);

    putchar(1231231232);
    //size_t a = 1213;

    return 0;
}
