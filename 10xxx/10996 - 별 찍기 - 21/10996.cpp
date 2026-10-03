#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n*2; i++) {
        if(i%2 == 1) {
            for(int j = 1; j <= n; j++) {
                if(j%2 == 1) printf("*");
                else printf(" ");
            }
            printf("\n");
        }
        else if(i%2 == 0) {
            for(int j = 1; j <= n; j++) {
                if(j%2 == 1) printf(" ");
                else printf("*");
            }
            printf("\n");
        }
    }
}
