#include <bits/stdc++.h>
using namespace std;

int n, k = 2, arr[11] = {0, 1, 2, 2};

int main() {
    scanf("%d", &n);
    for(int i = 4; i <= n; i++) {
        if(k != i-1) k += 2;
        else if(k == i-1) k = 2;
    }
    if(n < 4) printf("%d", arr[n]);
    else printf("%d", k);
}
