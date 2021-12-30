#include <bits/stdc++.h>
using namespace std;

int f(int a, int b) {
    for(int i = b; ; i+=b) {
        if(i%a == 0) return i;
    }
}

int main() {
    int t, a, b;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d %d", &a, &b);
        if(a > b) swap(a, b);
        printf("%d\n", f(a, b));
    }
}
