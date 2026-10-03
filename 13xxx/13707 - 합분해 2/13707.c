#include <stdio.h>

int arr[5555][5555];

int main() {
    for(int i = 1; i <= 5000; i++) {
        for(int j = 1; j <= 5000; j++) {
            if(i == 1) arr[1][j] = j;
            else if(j == 1) arr[i][1] = 1;
            else arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % 1000000000;
        }
    }
    
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", arr[n][k]);
}