#include <bits/stdc++.h>
using namespace std;

int twoCount = 0, fiveCount = 0;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int k = i;
        while(k) {
            if(k%2) break;
            else {
                twoCount++;
                k /= 2;
            }
        }
        while(k) {
            if(k%5) break;
            else {
                fiveCount++;
                k /= 5;
            }
        }
    }
    printf("%d", min(twoCount, fiveCount));
}