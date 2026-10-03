#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k = 0, p, cnt;
    int arr[100001], a[100001], b[100001];
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        k += arr[i];
    }
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]);
        if(a[i] > b[i]) swap(a[i], b[i]);
    }

    for(int i = 0; i < m; i++) {
        cnt = 0, p = k;
        if(b[i]-a[i]+1 < n/2) {
            for(int x = a[i]; x <= b[i]; x++) cnt = cnt + arr[x];
            printf("%d\n", cnt);
        }
        else {
            for(int x = 1; x < a[i]; x++) p = p - arr[x];
            for(int x = b[i]+1; x <= n; x++) p = p - arr[x];
            printf("%d\n", p);
        }
    }
}
