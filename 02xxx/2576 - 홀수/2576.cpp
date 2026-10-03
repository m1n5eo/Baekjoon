#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0, minNum = 1234567890;
    for(int i = 0; i < 7; i++) {
        scanf("%d", &n);
        if(n%2) {
            sum += n;
            minNum = min(minNum, n);
        }
    }
    if(sum) printf("%d\n%d", sum, minNum);
    else printf("-1");
}
