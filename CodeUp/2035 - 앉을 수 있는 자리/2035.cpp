#include <bits/stdc++.h>
using namespace std;

int arr[10001];

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    for(int i = 1; i <= n; i++) {
        if(!arr[i-1] && !arr[i] && !arr[i+1]) cnt++;
    }
    printf("%d", cnt);
}