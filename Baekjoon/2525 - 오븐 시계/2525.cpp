#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d", &a, &b);
    scanf("%d", &c);
    int k = a*60+b+c;
    printf("%d %d", k/60%24, k%60);
}
