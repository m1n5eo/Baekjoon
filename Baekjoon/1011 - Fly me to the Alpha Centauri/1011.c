#include <stdio.h>

int main() {
    int n, m, t;
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++) {
        scanf("%d %d", &n, &m);
        int k = m-n;
        for(long long int i = 1; i <= 100000; i++) {
            if(i*i >= k) {
                if(i*i-i < k) printf("%d\n", i*2-1);
                else printf("%d\n", i*2-2);
                break;
            }
        }
    }
}
