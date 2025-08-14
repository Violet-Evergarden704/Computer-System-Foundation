#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INSTRUCTION_LENGTH 50
#define REGISTER_COUNT 8

// 寄存器数组
int registers[REGISTER_COUNT];
// 程序计数器
int pc = 0;

// 存储指令的数组
char instructions[100][MAX_INSTRUCTION_LENGTH];
// 指令数量
int instruction_count;

void executeInstruction()
{
    char operation[10];
    char dst[3], src1[3], src2[3];
    int imm;
    sscanf(instructions[pc], "%s", operation);

    if (strcmp(operation, "ADDI") == 0)
    {
        sscanf(instructions[pc], "%*s %s %s #%d", dst, src1, &imm);
        int reg1 = dst[1] - '0';
        int reg2 = src1[1] - '0';
        registers[reg1] = registers[reg2] + imm;
        pc++;
    }
    else if (strcmp(operation, "ADD") == 0)
    {
        sscanf(instructions[pc], "%*s %s %s %s", dst, src1, src2);
        int reg1 = dst[1] - '0';
        int reg2 = src1[1] - '0';
        int reg3 = src2[1] - '0';
        registers[reg1] = registers[reg2] + registers[reg3];
        pc++;
    }
    else if (strcmp(operation, "SUB") == 0)
    {
        sscanf(instructions[pc], "%*s %s %s %s", dst, src1, src2);
        int reg1 = dst[1] - '0';
        int reg2 = src1[1] - '0';
        int reg3 = src2[1] - '0';
        registers[reg1] = registers[reg2] - registers[reg3];
        pc++;
    }
    else if (strcmp(operation, "PRT") == 0)
    {
        sscanf(instructions[pc], "%*s %s", dst);
        int reg = dst[1] - '0';
        printf("%d\n", registers[reg]);
        pc++;
    }
    else if (strcmp(operation, "J") == 0)
    {
        sscanf(instructions[pc], "%*s #%d", &imm);
        pc += imm;
    }
    else if (strcmp(operation, "SLT") == 0)
    {
        sscanf(instructions[pc], "%*s %s %s %s", dst, src1, src2);
        int reg1 = dst[1] - '0';
        int reg2 = src1[1] - '0';
        int reg3 = src2[1] - '0';
        registers[reg1] = (registers[reg3] > registers[reg2]) ? 1 : 0;
        pc++;
    }
    else if (strcmp(operation, "BEQZ") == 0)
    {
        sscanf(instructions[pc], "%*s %s #%d", src1, &imm);
        int reg = src1[1] - '0';
        if (registers[reg] == 0)
        {
            pc += imm;
        }
        else
        {
            pc++;
        }
    }
}

int main()
{
    scanf("%d", &instruction_count);
    getchar(); // 消耗换行符

    for (int i = 0; i < instruction_count; i++)
    {
        fgets(instructions[i], MAX_INSTRUCTION_LENGTH, stdin);
        instructions[i][strcspn(instructions[i], "\n")] = 0; // 去掉换行符
    }

    while (pc < instruction_count)
    {
        executeInstruction();
    }

    return 0;
}