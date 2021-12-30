#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int a, b, v;
    scanf("%lld %lld %lld", &a, &b, &v);
    if((v-a)%(a-b) == 0) {
        printf("%lld", (v-a)/(a-b)+1);
    }
    else {
        printf("%lld", (v-a)/(a-b)+2);
    }
}
