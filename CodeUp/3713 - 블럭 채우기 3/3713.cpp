#include <bits/stdc++.h>
using namespace std;

int arr[10003] = {0, 1, 3,};

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 3; i <= n; i++) {
        arr[i] = (arr[i-1] + arr[i-2] + arr[i-2]) % 100007;
    }
    printf("%d", arr[n]);
}