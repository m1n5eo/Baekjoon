#include <bits/stdc++.h>
using namespace std;

int main() {
    int PrimeNum[10001] = {2, 2, }; // 아직 확인하지 않았으면 0 / 소수면 1 / 소수가 아니면 2
    for(int i = 2; i <= 10000; i++) {
        if(PrimeNum[i] == 0) {
            PrimeNum[i] = 1;
            for(int j = i+i; j <= 10000; j+=i) PrimeNum[j] = 2;
        }
    }

    int n, m, sum = 0, MinPrimeNum = 1234567890;
    scanf("%d %d", &n, &m);
    for(int i = n; i <= m; i++) {
        if(PrimeNum[i] == 1 && MinPrimeNum == 1234567890) MinPrimeNum = i;
        if(PrimeNum[i] == 1) sum += i;
    }
    printf("%d\n%d", sum, MinPrimeNum);
}