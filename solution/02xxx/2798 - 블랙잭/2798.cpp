#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, arr[103], maxx = -1234567890;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                if(arr[i]+arr[j]+arr[k] <= m && arr[i]+arr[j]+arr[k] > maxx) {
                    maxx = arr[i]+arr[j]+arr[k];
                }
            }
        }
    }

    printf("%d", maxx);
}
