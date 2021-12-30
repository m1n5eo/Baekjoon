#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, cnt = 0, arr[100001];
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);

    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = i; j <= n; j++) {
            sum += arr[j];
            if(sum == k) {cnt++; break;}
            else if(sum > k) break;
        }
    }

    printf("%d", cnt);
}