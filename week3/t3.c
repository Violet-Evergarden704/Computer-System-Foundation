#include <stdio.h>
int main(){
    int n = 0;
    scanf("%d", &n);
    int ans[16] = {0};
    if(n >= 0){
        for (int i = 0; i < 16; i++)
        {
            ans[i] = n % 2;
            n /= 2;
        }
        for (int i = 15; i >= 0; i--)
        {
            printf("%d", ans[i]);
        }
    }
    else if(n < 0){
        n = -n;
        for (int i = 0; i < 16; i++)
        {
            ans[i] = n % 2;
            n /= 2;
        }
        for (int i = 15; i >= 0; i--)
        {
            if(ans[i] == 0){
                ans[i] = 1;
            }
            else{
                ans[i] = 0;
            }
        }
        for(int i = 0; i < 16; i++){
            if(ans[i] == 0){
                ans[i] = 1;
                break;
            }
            else{
                ans[i] = 0;
            }
        }
        for(int i = 15; i >= 0; i--){
            printf("%d", ans[i]);
        }
    }
    return 0;
}