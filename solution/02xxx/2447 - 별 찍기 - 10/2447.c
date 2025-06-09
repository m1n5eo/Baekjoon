#include <stdio.h>

#define MAX 2222

int n;
char s[MAX][MAX];

void star(int x1, int y1, int x2, int y2) {
    if(x1+1 == x2 && y1+1 == y2) {
        s[x1][y1] = '*';
        return;
    }

    int midx1 = x1 + (x2 - x1) / 3;
    int midx2 = midx1 + (x2 - x1) / 3;
    int midy1 = y1 + (y2 - y1) / 3;
    int midy2 = midy1 + (y2 - y1) / 3;

    star(x1, y1, midx1, midy1);
    star(x1, midy1, midx1, midy2);
    star(x1, midy2, midx1, y2);
    star(midx1, y1, midx2, midy1);

    for(int i = midx1; i < midx2; i++) {
        for(int j = midy1; j < midy2; j++) {
            s[i][j] = ' ';
        }
    }

    star(midx1, midy2, midx2, y2);
    star(midx2, y1, x2, midy1);
    star(midx2, midy1, x2, midy2);
    star(midx2, midy2, x2, y2);

    return;
}

int main() {
    scanf("%d", &n);
    star(0, 0, n, n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c", s[i][j]);
        }
        printf("\n");
    }
}