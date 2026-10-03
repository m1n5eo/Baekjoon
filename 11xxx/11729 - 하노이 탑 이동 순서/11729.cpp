#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int from, int by, int to) {
    if(n == 1) {
        printf("%d %d\n", from, to);
        return;
    }
    hanoi(n-1, from, to, by);
    hanoi(1, from, by, to);
    hanoi(n-1, by, from, to);
}

int main() {
    int n;
    scanf("%d", &n);
    float temp = pow(2, n)-1;
    int k = (int)temp;
    printf("%d\n", k);
    hanoi(n, 1, 2, 3);
}
