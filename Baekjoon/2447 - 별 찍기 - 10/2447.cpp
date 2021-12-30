#include <bits/stdc++.h>
using namespace std;

char arr[6666][6666];

void star(int n, int i, int j) {
    if(n/3 == 0) arr[i][j] = '*';
    if((i/n)%3 == 1 && (j/n)%3 == 1) {
        arr[i][j] = ' ';
    }
    else {
        if(n/3 == 0) arr[i][j] = '*';
        else star(n/3, i, j);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            star(n, i, j);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}
