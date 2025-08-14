#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char str[100];
    gets(str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            printf("%c", toupper(str[i]));
        }
        else
        {
            printf(" ");
        }
    }
    return 0;
}