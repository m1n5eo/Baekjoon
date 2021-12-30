#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k = 1;
    int arr[55][55];
    scanf("%d", &n);
    int x = 0, y = n/2;
    while(k <= n*n) {
        arr[x][y] = k;
        if(k%n == 0) {
            x++;
            if(x > n-1) x-=n;
        }
        else {
            x--; y++;
            if(x < 0) x+=n;
            if(y > n-1) y-=n;
        }
        k++;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}