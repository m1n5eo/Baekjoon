#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0;
    for(int i = 0; i < 5; i++) {
        scanf("%d", &n);
        if(n < 40) n = 40;
        sum = sum + n;
    }
    printf("%d", sum/5);
}
