#include <bits/stdc++.h>
using namespace std;

int main() {
    int n[5];
    scanf("%d %d %d", &n[0], &n[1], &n[2]);
    sort(n, n+3);

    printf("%d", n[1]);
}
