# include<stdio.h>

int main()
{
    int a = 1;
    int b = 2;
    // 向下分配地址，栈顶是低地址
    printf("%p\n%p",&a,&b);
}