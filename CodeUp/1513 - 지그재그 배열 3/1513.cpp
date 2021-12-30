#include <bits/stdc++.h>
using namespace std;

int arr[111][111];

int main() {
    int n, cnt = 1, k;
    scanf("%d", &n);

    if(n%2 == 0) k = (n+1)*(n/2);
    else if(n%2 == 1) k = n*(n/2+1);

    int x = n-1, y = 0, sw = 0;
    while(cnt != k+1) {
        arr[x][y] = cnt;
        if(!sw) {
            x--; y++;
            if(y > n-1) {
                x+=2; y-=1; sw=1;
            }
        }
        else {
            x++; y--;
            if(x > n-1) {
                x-=1; y+=2; sw=0;
            }
        }
        cnt++;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}