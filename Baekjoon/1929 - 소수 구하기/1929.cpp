#include <bits/stdc++.h>
using namespace std;

int prime[1000001] = {2, 2};

void CheckPrime(int num) {
    prime[num] = 1;
    for(int i = num*2; i <= 1000000; i+=num) {
        prime[i] = 2;
    }
}

int main() {
    for(int i = 2; i <= 1000000; i++) {
        if(prime[i] == 0) {
            CheckPrime(i);
        }
    }

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = n; i <= m; i++) {
        if(prime[i] == 1) printf("%d\n", i);
    }
}
