#include <stdio.h>

int cnt[55];

int main() {
    int n, arr[55];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i] > arr[j]) cnt[i]++;
            else if(arr[i] == arr[j] && i > j) cnt[i]++;
        }
    }
    for(int i = 0; i < n; i++) printf("%d ", cnt[i]);
}