#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, arr[1003] = {0, 1, 3, };
    scanf("%d", &n);
    for(int i = 3; i <= n; i++) {
        arr[i] = (arr[i-2]*2+arr[i-1])%10007;
    }
    printf("%d", arr[n]);
}
