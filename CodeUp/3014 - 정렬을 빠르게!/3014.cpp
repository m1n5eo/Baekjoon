#include <bits/stdc++.h>
using namespace std;

int cnt[100001];

int main() {
    int n, data;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        cnt[data]++;
    }
    for(int i = 0; i < 100001; i++) {
        if(cnt[i] != 0) {
            for(int print = 0; print < cnt[i]; print++) {
                printf("%d ", i);
            }
        }
    }
}