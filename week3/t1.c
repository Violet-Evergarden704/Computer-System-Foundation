#include <stdio.h>
int main(){
    int input = 0;
    scanf("%d",&input);
    int ans[8];
    int a = input;
    for(int i = 0;i < 8;i++){
        ans[i]=a % 2;
        a = a / 2;
    }
    int answer = 0;
    for(int i=0;i<8;i++){
        if(ans[i]==1)answer++;
    }
    printf("%d",answer);
    return 0;
}