#include <bits/stdc++.h>
using namespace std;

int b, n, maxx = -1, arr[22];

void f(int idx, int sum) {
    if(b >= sum) {
        if(maxx < sum) {
            maxx = sum;
        }
    }

    for(int i = idx; i < n; i++) {
        f(i+1, sum+arr[i]);
    }
}

int main() {
    scanf("%d %d", &b, &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    f(0, 0);
    printf("%d", maxx);
}