#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        if(i%2 == 1) {
            for(int j = 1; j <= n*2-1; j++) {
                if(j%2 == 1) printf("*");
                else printf(" ");
            }
        }
        else if(i%2 == 0) {
            for(int j = 1; j <= n*2; j++) {
                if(j%2 == 0) printf("*");
                else printf(" ");
            }
        }
        printf("\n");
    }
}
