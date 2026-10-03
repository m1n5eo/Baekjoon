#include <stdio.h>

#define MAX 1111

int t, prime[MAX] = {1, 1, };

int main() {
    for(int i = 2; i*i < MAX; i++) {
        if(prime[i] == 0) {
            for(int j = i*2; j < MAX; j+=i) {
                prime[j] = 1;
            }
        }
    }
    
    scanf("%d", &t);

    for(int testcase = 1; testcase <= t; testcase++) {
        int n, stop_point = 1;

        scanf("%d", &n);

        for(int i = 2; i <= 1000 && stop_point; i++) {
            for(int j = 2; j <= 1000 && stop_point; j++) {
                if(2 <= n-i-j && n-i-j <= 1000) {
                    if(prime[i] == 0 && prime[j] == 0 && prime[n-i-j] == 0) {
                        printf("%d %d %d\n", i, j, n-i-j);
                        stop_point = 0;
                        break;
                    }
                }
            }
        }

        if(stop_point == 1) printf("0\n");
    }
}