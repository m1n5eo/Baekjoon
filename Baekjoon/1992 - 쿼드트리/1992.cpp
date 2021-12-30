#include <bits/stdc++.h>
using namespace std;

int n, pan[66][66];

void func(int x, int y, int num) {
    if(num == 1) {
        printf("%d", pan[x][y]);
        return;
    }
    int cnt = 0;
    for(int i = x; i < x+num; i++) {
        for(int j = y; j < y+num; j++) {
            if(pan[i][j] == 0) cnt++;
        }
    }
    if(cnt == num*num) printf("0");
    else if(cnt == 0) printf("1");
    else {
        printf("(");
        func(x, y, num/2);
        func(x, y+num/2, num/2);
        func(x+num/2, y, num/2);
        func(x+num/2, y+num/2, num/2);
        printf(")");
    }
    return;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d", &pan[i][j]);
        }
    }
    func(0, 0, n);
}