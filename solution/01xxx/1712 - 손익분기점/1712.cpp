#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(b >= c) {
        printf("-1");
        return 0;
    }
    printf("%d", a/(c-b)+1);
}
