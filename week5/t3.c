#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int* toBinary(double n){
    int* a = malloc(320 * sizeof(int));
    for(int i = 0; i < 320; i++){
        a[i] = 0;
    }
    for(int i = 0; i < 320; i++){
        n *= 2;
        a[i] = (int)n;
        n -= a[i];
    }
    return a;
}
int main(){
    double n;
    scanf("%lf", &n);
    if(n == 0){
        for(int i = 0; i < 32; i++){
            printf("0");
        }
        return 0;
    }
    else if(n == -0){
        printf("10000000000000000000000000000000");
        return 0;
    }
    else if(isinf(n) && n > 0){
        printf("01111111100000000000000000000000");
        return 0;
    }
    else if(isinf(n) && n < 0){
        printf("11111111100000000000000000000000");
        return 0;
    }
    else if(isnan(n)){
        for(int i = 0; i < 32; i++){
            printf("1");
        }
        return 0;
    }
    
    else{
        int ans[32];
        for (int i = 0; i < 32; i++)
        {
            ans[i] = 0;
        }
        double frackpart, intpart;
        frackpart = modf(n, &intpart);
        intpart = fabs(intpart);
        int E = floor(log2(fabs(n)));
        int e = E + 127;
        int tmp[23] = {0};
        int intpartInt = intpart;
        int *binary = toBinary(frackpart);
        for (int i = 0; i < E + 1; i++)
        {
            tmp[i] = intpartInt % 2;
            intpartInt /= 2;
        }
        int tmp2[23] = {0};
        for (int i = 0; i < E + 1; i++)
        {
            tmp2[i] = tmp[i];
        }
        for (int i = 0; i < E + 1; i++)
        {
            tmp[i] = tmp2[E - i];
        }
        if (n < 0)
        {
            ans[0] = 1;
        }
        int index = 0;
        for (int i = E + 1; i < 23; i++)
        {
            tmp[i] = binary[index++];
        }
        for (int i = 8; i >= 1; i--)
        {
            ans[i] = e % 2;
            e /= 2;
        }
        if(E > 0){
            for (int i = 9; i < 9 + E; i++)
            {
                ans[i] = tmp[i - 9 + 1];
            }
            for (int i = 9 + E; i < 32; i++)
            {
                ans[i] = binary[i - 9 - E];
            }
        }
        else{
            int flag = 0;
            for (int i = 0; i < 320; i++)
            {
                if(binary[i] == 1){
                    flag = i;
                    break;
                }
            }

            for(int i = 9; i < 32; i++){
                ans[i] = binary[flag + 1 + i - 9];
            }
        }
        
        for (int i = 0; i < 32; i++)
        {
            printf("%d", ans[i]);
        }
        free(binary);
    }
    
    return 0;
}