#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) printf(" ");
        for(int j = 1; j <= i*2-1; j++) {
            if(j%2 == 1) printf("*");
            else if(j%2 == 0)printf(" ");
        }
        printf("\n");
    }
}
