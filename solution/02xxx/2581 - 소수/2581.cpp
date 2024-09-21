#include <bits/stdc++.h>
using namespace std;

int prime[10001] = {2, 2};

void CheckPrime(int num) {
    prime[num] = 1;
    for(int i = num*2; i <= 10000; i+=num) {
        prime[i] = 2;
    }
}

int main() {
    for(int i = 2; i <= 10000; i++) {
        if(prime[i] == 0) {
            CheckPrime(i);
        }
    }

    int n, m, sum = 0, minn = 1234567890;
    scanf("%d %d", &n, &m);
    for(int i = n; i <= m; i++) {
        if(prime[i] == 1) {
            sum += i;
            minn = min(minn, i);
        }
    }
    if(sum == 0) printf("-1");
    else printf("%d\n%d", sum, minn);
}
