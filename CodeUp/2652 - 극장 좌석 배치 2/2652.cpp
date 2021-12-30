#include <bits/stdc++.h>
using namespace std;

int n, k, cnt = 0;

void f(int seat, int people, int sw) { // sw1 = O, sw0 = X
    if(seat == n) {
        if(people == k) cnt++;
        return;
    }
    if(sw == 0) {
        f(seat+1, people+1, 1);
        f(seat+1, people, 0);
    }
    else if(sw == 1) {
        f(seat+1, people, 0);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    f(1, 1, 1);
    f(1, 0, 0);
    printf("%d", cnt);
}