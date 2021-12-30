#include <bits/stdc++.h>
using namespace std;

int arr[1003] = {0, 1, };

int main() {
    int n, k, cnt = 0;
    scanf("%d %d", &n, &k);

    for(int i = 2; i <= n; i++) {
        if(arr[i] == 0) {
            for(int j = i; j <= n; j=j+i) {
                if(arr[j] == 0) cnt = cnt + 1;
                arr[j] = 1;
                if(cnt == k) {
                    printf("%d", j);
                    return 0;
                }
            }
        }
    }
}
