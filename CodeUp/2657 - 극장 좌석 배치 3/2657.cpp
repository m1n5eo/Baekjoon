#include <bits/stdc++.h>
using namespace std;

int n, k, cnt = 0;

void f(int seatnum, int sw, int seat, int people) {
    if(people > k) return;
    else if(seatnum == n) {
        if(people != k) return;
        else if(sw == 1 && seat == 1) return;
        cnt = cnt + 1;
        return;
    }

    if(sw == 1 && seat == 1) {
        f(seatnum+1, seat, 0, people);
    }
    else if(sw == 1 && seat == 0) {
        f(seatnum+1, seat, 0, people);
        f(seatnum+1, seat, 1, people+1);
    }
    else if(sw == 0 && seat == 1) {
        f(seatnum+1, seat, 0, people);
        f(seatnum+1, seat, 1, people+1);
    }
    else if(sw == 0 && seat == 0) {
        f(seatnum+1, seat, 0, people);
        f(seatnum+1, seat, 1, people+1);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    f(1, 1, 1, 1);
    f(1, 1, 0, 0);
    printf("%d", cnt);
}