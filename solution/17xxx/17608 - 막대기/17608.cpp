#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, arr[100001];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int maxx = -1234567890, cnt = 0;
    for(int i = n-1; i >= 0; i--) {
        if(maxx < arr[i]) {
            maxx = arr[i];
            cnt++;
        }
    }
    printf("%d", cnt);
}
