#include <stdlib.h>
#include <stdio.h>
#include <time.h> //使用当前时钟做种子

int main()
{
    FILE *file=fopen("nums.txt","w");
    int i;
    srand((unsigned)time(NULL)); //初始化随机数
    for (i = 0; i < 154761445; i++)     //打印出10个随机数
        fprintf(file," %d\n", rand());
}