#include <stdio.h>

int main() {

    long long int hi[80001],n,i,j;
    long long int cnt = 0,s=0;
    scanf("%lld", &n);
    for(i = 0; i < n; i++) scanf("%lld", &hi[i]);

    for( i = 0; i < n-1; i++) {
            cnt=0;
        for(j = i+1; j < n; j++) {
            if(hi[i] <= hi[j]) break;
            cnt = cnt + 1;
        }
    s+=cnt;
    }
    printf("%lld", s);
    return 0;
}