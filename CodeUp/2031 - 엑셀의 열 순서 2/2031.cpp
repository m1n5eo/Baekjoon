#include <bits/stdc++.h>
using namespace std;

char str[11];

int main() {
    long long int res = 0;
    int multi = 1;
    scanf("%s", str);
    for(int i = strlen(str)-1; i >= 0; i--) {
        res += multi*(str[i]-64);
        multi *= 26;
    }
    printf("%lld", res);
}