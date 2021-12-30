#include <bits/stdc++.h>
using namespace std;

int n, sw = 0;

void f(int k, int last, int arr[]) {
    if(sw == 1) return;
    if(k == n+1) {
        for(int i = 1; i <= n; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
        sw = 1;
        return;
    }
    int c = 0;
    arr[k] = last;
    for(int i = 1; i <= k/2; i++) {
        for(int j = 1; j <= i; j++) {
            if(arr[k-j+1] == arr[k-i-j+1]) c++;
        }
        if(c == i) return;
        c = 0;
    }

    f(k+1, 1, arr);
    f(k+1, 2, arr);
    f(k+1, 3, arr);
}

int main() {
    int arr[88];
    scanf("%d", &n);
    f(1, 1, arr);
    if(sw == 1) return 0;

    f(1, 2, arr);
    if(sw == 1) return 0;

    f(1, 3, arr);
}