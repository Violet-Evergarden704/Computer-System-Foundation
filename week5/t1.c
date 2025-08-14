#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    gets(str);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i] != ' '){
            printf("%c", str[i]);
        }
    }
    return 0;
}