#include <bits/stdc++.h>
using namespace std;

int atm[1003];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &atm[i]);
    sort(atm, atm+n);
    for(int i = 0; i < 2; i++) {
        for(int i = 1; i < n; i++) atm[i] = atm[i] + atm[i-1];
    }
    printf("%d", atm[n-1]);
}
