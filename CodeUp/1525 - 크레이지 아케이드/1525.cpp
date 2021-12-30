#include <bits/stdc++.h>
using namespace std;

int t, n[111], m[111];
int arr[111][111], arr2[111][111], water[111][111];

void print() {
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }
    printf("Character Information\n");
    for(int testcase = 0; testcase < t; testcase++) {
        if(water[n[testcase]][m[testcase]]) printf("player %d dead\n", testcase+1);
        else printf("player %d survive\n", testcase+1);
    }
}

void f(int x, int y, int dis, int swX, int swY) {
    if(dis == -1 || arr[x][y] == -1) return;
    water[x][y] = 1;
    f(x+swX, y+swY, dis-1, swX, swY);
}

int main() {
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            if(arr[i][j] >= 1) {
                water[i][j] = 1;
                f(i, j, arr[i][j], 0, -1);
                f(i, j, arr[i][j], 0, 1);
                f(i, j, arr[i][j], -1, 0);
                f(i, j, arr[i][j], 1, 0);
            }
        }
    }
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            if(arr[i][j] == -1) arr2[i][j] = -1;
            else if(water[i][j] == 1) arr2[i][j] = -2;
            else arr2[i][j] = arr[i][j];
        }
    }

    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++) {
        scanf("%d %d", &n[testcase], &m[testcase]);
        if(arr2[n[testcase]][m[testcase]] != -2) arr2[n[testcase]][m[testcase]] = testcase+1;
    }
    print();
}