#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int k = n/3;
    for(int i = 0; i <= k; i++) {
        if((n-i*3)%5 == 0) {
            printf("%d", i+(n-i*3)/5);
            return 0;
        }
    }
    printf("-1");
}
