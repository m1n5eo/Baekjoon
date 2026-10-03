#include <bits/stdc++.h>
using namespace std;

int PrimeNumber[1001] = {2, 2, }; /// 0.아직판별X  1.소수  2.소수아님

int f(int num) {
    for(int i = 2; i < num; i++) {
        if(num%i == 0) return 2;
    }
    for(int i = num*2; i <= 1000; i+=num) {
        PrimeNumber[i] = 2;
    }
    return 1;
}

int main() {
    for(int i = 2; i <= 1000; i++) {
        if(PrimeNumber[i] == 0) {
            PrimeNumber[i] = f(i);
        }
    }
    //for(int i = 1; i <= 1000; i++) printf("%d ", PrimeNumber[i]);

    int n, m, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        if(PrimeNumber[m] == 1) cnt++;
    }

    printf("%d", cnt);
}
