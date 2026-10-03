#include <bits/stdc++.h>
using namespace std;

int n, cnt, arr[246999];

int main() {
    for(int i = 2; i <= 246912; i++) {
        if(arr[i] == 1) continue;
        for(int j = i+i; j <= 246912; j+=i) arr[j] = 1;
    }
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;
        cnt = 0;
        for(int i = n+1; i <= n*2; i++) {
            if(arr[i] == 0) cnt++;
        }
        printf("%d\n", cnt);
    }
}
