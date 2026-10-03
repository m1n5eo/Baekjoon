#include <stdio.h>

int main() {
    int t;

    scanf("%d", &t);

    for(int testcase = 1; testcase <= t; testcase++) {
        int n, m, cnt = 0;

        scanf("%d %d", &n, &m);

        for(int a = 1; a < n; a++) {
            for(int b = a+1; b < n; b++) {
                int bunmo = a*a + b*b + m;
                int bunja = a*b;

                if(bunmo%bunja == 0) cnt += 1;
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}