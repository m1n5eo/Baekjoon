#include <stdio.h>

#define MAX 222

int t, n, result[MAX], prime[MAX] = {1, 1, };

int main() {
    for(int i = 2; i < MAX; i++) {
        if(prime[i] == 0) {
            for(int j = i*2; j < MAX; j+=i) {
                prime[j] = 1;
            }
        }
    }

    for(int i = 1; i < MAX; i++) {
        for(int j = 1; j < MAX; j++) {
            if(i+j < MAX && prime[i] == 0 && prime[j] == 0) {
                result[i+j] = 1;
            }
        }
    }

    scanf("%d", &t);

    for(int tc = 0; tc < t; tc++) {
        scanf("%d", &n);

        if(result[n] == 0) printf("No\n");
        else printf("Yes\n");
    }
}