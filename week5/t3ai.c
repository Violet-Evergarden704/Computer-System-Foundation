#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
// 将浮点数转换为32位IEEE-754表示
int float_to_ieee754(float f)
{
    int result;
    memcpy(&result, &f, sizeof(float));
    return result;
}

// 打印32位二进制表示
void print_binary(int num)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main()
{
    double n;
    scanf("%lf", &n);
    // 转换为IEEE-754表示
    int ieee754 = float_to_ieee754(n);
    print_binary(ieee754);
    return 0;
}