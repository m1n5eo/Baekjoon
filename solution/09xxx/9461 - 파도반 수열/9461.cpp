#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int arr[101] = {0, 1, 1, 1, };
    for(int i = 4; i <= 100; i++) {
        arr[i] = arr[i-2] + arr[i-3];
    }

    int n, t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%lld\n", arr[n]);
    }
}
