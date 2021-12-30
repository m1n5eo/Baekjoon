#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i;
    scanf("%d", &n);
    printf("{");
    for(i = n; i < n*2-1; i++) printf("%d, ", i);
    printf("%d}", n*2-1);
}