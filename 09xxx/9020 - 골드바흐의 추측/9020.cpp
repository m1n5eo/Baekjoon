#include <bits/stdc++.h>
using namespace std;

int prime[10001] = {2, 2}; /// 0.확인안함 1.소수 2.소수아님

void CheckPrime(int num) {
    prime[num] = 1;
    for(int i = num*2; i <= 10000; i+=num) prime[i] = 2;
}

int main() {
    for(int i = 2; i <= 10000; i++) {
        if(prime[i] == 0) CheckPrime(i);
    }

    int t, n;
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++) {
        scanf("%d", &n);
        int k = n/2;
        while(1) {
            if(prime[k] == 1 && prime[n-k] == 1) {
                printf("%d %d\n", k, n-k);
                break;
            }
            k--;
        }
    }
}
