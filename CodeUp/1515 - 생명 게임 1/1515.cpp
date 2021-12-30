#include <bits/stdc++.h>
using namespace std;

int arr[33][33], cnt[33][33];

int main() {
    for(int i = 1; i <= 25; i++) {
        for(int j = 1; j <= 25; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 1; i <= 25; i++) {
        for(int j = 1; j <= 25; j++) {\
            for(int x = -1; x <= 1; x++) {
                for(int y = -1; y <= 1; y++) {
                    if(!(x == 0 && y == 0) && arr[i+x][j+y]) cnt[i][j]++;
                }
            }
        }
    }

    for(int i = 1; i <= 25; i++) {
        for(int j = 1; j <= 25; j++) {
            if(arr[i][j] == 0 && cnt[i][j] == 3) arr[i][j] = 1;
            else if(arr[i][j] == 1 && cnt[i][j] >= 4) arr[i][j] = 0;
            else if(arr[i][j] == 1 && cnt[i][j] <= 1) arr[i][j] = 0;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}