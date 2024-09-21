#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k = 1, i = 1;
    scanf("%d", &n);
    while(n > k) {
        k = k + i*6;
        i++;
    }
    printf("%d", i);
}
