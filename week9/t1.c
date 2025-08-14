#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 获取寄存器字符串（如 "R0"）
void printRegister(int *code, int start)
{
    int value = 0;
    for (int i = start; i < start + 5; i++)
    {
        value += code[i] << (start + 4 - i);
    }
    printf("R%d", value);
}

// 获取16位有符号立即数
int getImmediate(int *code, int start)
{
    int value = 0;
    for (int i = 0; i < 16; i++)
    {
        value = (value << 1) | code[start + i];
    }
    // 符号扩展
    if (value & 0x8000)
    {
        value |= 0xFFFF0000;
    }
    return value;
}

// 检查是否为R型指令
int isRType(int *code)
{
    for (int i = 0; i < 6; i++)
    {
        if (code[i] != 0)
            return 0;
    }
    return 1;
}

// 检查是否为ADD指令（funct = 0x20）
int isADD(int *code)
{
    int funct = 0;
    for (int i = 26; i < 32; i++)
    {
        funct = (funct << 1) | code[i];
    }
    return (funct == 0x20);
}

// 获取opcode（6位）
int getOpcode(int *code)
{
    int opcode = 0;
    for (int i = 0; i < 6; i++)
    {
        opcode = (opcode << 1) | code[i];
    }
    return opcode;
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int code[32];
        for (int i = 0; i < 32; i++)
        {
            scanf("%1d", &code[i]); // 逐位读取
        }

        if (isRType(code))
        {
            if (isADD(code))
            {
                printf("ADD ");
            }
            else
            {
                printf("AND ");
            }
            printRegister(code, 16);
            printf(" ");
            printRegister(code, 6);
            printf(" ");
            printRegister(code, 11);
            printf("\n");
        }
        else
        {
            int opcode = getOpcode(code);
            if (opcode == 0x08)
            { // ADDI
                printf("ADDI ");
            }
            else if (opcode == 0x0C)
            { // ANDI
                printf("ANDI ");
            }
            printRegister(code, 11);
            printf(" ");
            printRegister(code, 6);
            printf(" #%d\n", getImmediate(code, 16));
        }
    }

    return 0;
}