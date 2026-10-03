#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, arr[1003], LIS[1003];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        LIS[i] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] < arr[j]) {
                if(LIS[i]+1 > LIS[j]) LIS[j] = LIS[i]+1;
            }
        }
    }
    sort(LIS, LIS+n);
    printf("%d", LIS[n-1]);
}
