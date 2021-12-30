#include <bits/stdc++.h>
using namespace std;

int n, r;

int f(int num, int ro) {
    if(num > 0 && ro == 1) return num;
    else if(num == ro) return 1;
    else if(num < ro) return 0;
    else return f(num-1, ro-1) + f(num-1, ro);
}

int main() {
    scanf("%d %d", &n, &r);
    if(n < r) printf("0");
    else if(n == r) printf("1");
    else printf("%d", f(n, r));
}