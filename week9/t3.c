#include <stdio.h>
#include <string.h>

typedef struct Command
{
    char type[5];
    char dst[3];
    char src1[3];
    char src2[3];
    int imm;
} command;

int n, pc;
int R[8];
int main(void)
{
    command commands[10];
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        commands[i].imm = 0;
        char c;
        int index = 0;
        while ((c = getchar()) != ' ' && c != '\n' && c != EOF)
        {
            commands[i].type[index++] = c;
        }
        commands[i].type[index] = '\0';
        if (strcmp(commands[i].type, "J") == 0)
        {
            while (c != '#' && c != EOF)
            {
                c = getchar();
            }
            scanf("%d", &commands[i].imm);
            while (c != '\n' && c != EOF)
            {
                c = getchar();
            }
        }
        else if (strcmp(commands[i].type, "PRT") == 0 || strcmp(commands[i].type, "BEQZ") == 0)
        {
            index = 0;
            while ((c = getchar()) != '\n' && c != EOF && c != ' ' && c != '#')
            {
                commands[i].src1[index++] = c;
            }
            commands[i].src1[index] = '\0';
            if (strcmp(commands[i].type, "BEQZ") == 0)
            {
                while (c != '#' && c != EOF)
                {
                    c = getchar();
                }
                scanf("%d", &commands[i].imm);
                while (c != '\n' && c != EOF)
                {
                    c = getchar();
                }
            }
        }
        else
        {
            index = 0;
            while ((c = getchar()) != ' ' && c != EOF)
            {
                commands[i].dst[index++] = c;
            }
            commands[i].dst[index] = '\0';
            index = 0;
            while ((c = getchar()) != ' ' && c != EOF)
            {
                commands[i].src1[index++] = c;
            }
            commands[i].src1[index] = '\0';
            if (strcmp(commands[i].type, "ADDI") == 0)
            {
                while (c != '#' && c != EOF)
                {
                    c = getchar();
                }
                scanf("%d", &commands[i].imm);
                while (c != '\n' && c != EOF)
                {
                    c = getchar();
                }
            }
            else
            {
                index = 0;
                while ((c = getchar()) != '\n' && c != EOF)
                {
                    commands[i].src2[index++] = c;
                }
                commands[i].src2[index] = '\0';
                while (c != '\n' && c != EOF)
                {
                    c = getchar();
                }
            }
        }
    }

    while (pc < n)
    {
        if (strcmp(commands[pc].type, "J") == 0)
        {
            pc += commands[pc].imm;
            continue;
        }
        else if (strcmp(commands[pc].type, "PRT") == 0)
        {
            printf("%d\n", R[commands[pc].src1[1] - '0']);
        }
        else if (strcmp(commands[pc].type, "BEQZ") == 0)
        {
            if (R[commands[pc].src1[1] - '0'] == 0)
            {
                pc += commands[pc].imm;
                continue;
            }
        }
        else if (strcmp(commands[pc].type, "ADDI") == 0)
        {
            R[commands[pc].dst[1] - '0'] = R[commands[pc].src1[1] - '0'] + commands[pc].imm;
        }
        else if (strcmp(commands[pc].type, "SLT") == 0)
        {
            R[commands[pc].dst[1] - '0'] = (R[commands[pc].src2[1] - '0'] > R[commands[pc].src1[1] - '0']) ? 1 : 0;
        }
        else if (strcmp(commands[pc].type, "ADD") == 0)
        {
            R[commands[pc].dst[1] - '0'] = R[commands[pc].src1[1] - '0'] + R[commands[pc].src2[1] - '0'];
        }
        else if (strcmp(commands[pc].type, "SUB") == 0)
        {
            R[commands[pc].dst[1] - '0'] = R[commands[pc].src1[1] - '0'] - R[commands[pc].src2[1] - '0'];
        }
        pc++;
    }
    return 0;
}
