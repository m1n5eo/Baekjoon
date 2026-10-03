#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    float sum = 0, arr[1001], maxx = -1234567890;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        arr[i] = (float)k;
        maxx = max(maxx, arr[i]);
    }

    for(int i = 0; i < n; i++) {
        arr[i] = arr[i]/maxx*100;
        sum = sum + arr[i];
    }

    printf("%f", sum/n);
}
