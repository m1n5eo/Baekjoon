#include <bits/stdc++.h>
using namespace std;

int arr[10001];

int main() {
    int n, x, xMax = -1234567890;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        arr[x]++;
        xMax = max(x, xMax);
    }
    for(int i = 1; i <= xMax; i++) {
        if(arr[i]) {
            for(int j = 0; j < arr[i]; j++) printf("%d\n", i);
        }
    }
}
