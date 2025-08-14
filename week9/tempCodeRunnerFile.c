#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INSTRUCTION_LENGTH 50

// 寄存器数组
int registers[8];
int pc;

void executeInstruction(void)
{
    char operation[10];
    char dst[3], src1[3], src2[3];
    int imm;
    scanf("%s%s", operation, dst);
    if (strcmp(operation, "ADDI") == 0)
    {
        scanf("%s", src1);
        getchar(); // Consume the newline character
        getchar(); // Consume the '#' character
        scanf("%d", &imm);
        int reg1 = dst[1] - '0';
        int reg2 = src1[1] - '0';
        registers[reg1] = registers[reg2] + imm;
        pc++;
    }
    else if (strcmp(operation, "ADD") == 0)
    {
        scanf("%s", src1);
        scanf("%s", src2);
        int reg1 = dst[1] - '0';
        int reg2 = src1[1] - '0';
        int reg3 = src2[1] - '0';
        registers[reg1] = registers[reg2] + registers[reg3];
        pc++;
    }
    else if (strcmp(operation, "SUB") == 0)
    {
        scanf("%s", src1);
        scanf("%s", src2);
        int reg1 = dst[1] - '0';
        int reg2 = src1[1] - '0';
        int reg3 = src2[1] - '0';
        registers[reg1] = registers[reg2] - registers[reg3];
        pc++;
    }
    else if (strcmp(operation, "PRT") == 0)
    {
        int reg = dst[1] - '0';
        printf("%d\n", registers[reg]);
        pc++;
    }
    else if(strcmp(operation, "J") == 0)
    {
        imm = dst[1] - '0';
        pc += imm;
    }
    else if (strcmp(operation, "SLT") == 0)
    {
        scanf("%s", src1);
        scanf("%s", src2);
        int reg1 = dst[1] - '0';
        int reg2 = src1[1] - '0';
        int reg3 = src2[1] - '0';
        registers[reg1] = (registers[reg3] > registers[reg2]) ? 1 : 0;
        pc++;
    }
    else if (strcmp(operation, "BEQZ") == 0)
    {
        scanf("%s", src1);
        imm = src1[1] - '0';
        int reg = dst[1] - '0';
        if(registers[reg] == 0)
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
    int n;
    scanf("%d", &n);
    getchar();
    while (pc < n)
    {
        executeInstruction();
    }
    return 0;
}