#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, maxx = -1234567890;
    for(int i = 1; i <= 9; i++) {
        scanf("%d", &n);
        if(n > maxx) {
            maxx = n;
            k = i;
        }
    }
    printf("%d\n%d", maxx, k);
}
