#include <stdio.h>

int main() {
    int cnt = 0;
    char pan[11][11];
    for(int i = 0; i < 8; i++) {
        scanf("%s", pan[i]);
    }

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(i % 2 == 0 && j % 2 == 0 && pan[i][j] == 'F') cnt = cnt + 1;
            else if(i % 2 == 1 && j % 2 == 1 && pan[i][j] == 'F') cnt = cnt + 1;
        }
    }

    printf("%d", cnt);
}