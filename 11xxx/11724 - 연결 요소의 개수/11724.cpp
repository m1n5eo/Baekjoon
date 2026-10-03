#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, p = 2;
int arr[1003][1003], visit[1003];

void f(int x) {
    visit[x] = 1;
    for(int i = 1; i <= n; i++) {
        if(arr[x][i] == 1 && visit[i] == 0) {
            f(i);
        }
    }
    return;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for(int i = 1; i <= n; i++) {
        if(visit[i] == 0) {
            f(i);
            p=p+1;
        }
    }
    printf("%d", p-2);
}