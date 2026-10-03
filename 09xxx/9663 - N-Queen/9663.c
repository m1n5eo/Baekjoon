#include <stdio.h> // 1 0 0 2 10 4 40 92 352 724 2680

#define MAX 22

int n, result = 0;
int col[MAX], row[MAX], diagonal[2][MAX*2];

void queen(int cnt) {
    if(cnt == n) {
        result += 1;
        return;
    }

    col[cnt] = 1;
    for(int i = 0; i < n; i++) {
        if(row[i] == 0 && diagonal[0][i+cnt] == 0 && diagonal[1][cnt-i+7] == 0) {
            row[i] = 1;
            diagonal[0][i+cnt] = 1;
            diagonal[1][cnt-i+7] = 1;

            queen(cnt+1);

            row[i] = 0;
            diagonal[0][i+cnt] = 0;
            diagonal[1][cnt-i+7] = 0;
        }
    }
    col[cnt] = 0;
}

int main() {
    scanf("%d", &n);
    queen(0);
    printf("%d", result);
}