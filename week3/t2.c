#include <stdio.h>
int main() {
    int n = 0;
    scanf("%x", &n);
    int ans[4] = {0};
    for (int i = 0; i < 4; i++) {
        ans[i] = n % 8;
        n /= 8;
    }
    int pos=0;
    for(int i = 3; i >= 0; i--) {
        if(ans[i] != 0) {
            pos = i;
            break;
        }
    }
    for(int i = pos+1; i >= 0; i--) {
        printf("%d", ans[i]);
    }
    return 0;
}