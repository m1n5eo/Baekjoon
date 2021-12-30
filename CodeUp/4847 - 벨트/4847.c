#include <stdio.h>

int main()
{
    int i, m, cnt = 0;
    int ba[1002], bba[1002], belt[1002];
    scanf ("%d", &m);
    for (i = 1; i <= m; i++) {
        scanf ("%d %d %d", &ba[i], &bba[i], &belt[i]);
        if (belt[i] == 1) {
            cnt++;
        }
    }
    printf ("%d ", cnt % 2);
    if (ba[1] != 1) {
        bba[1] = bba[1] / ba[1];
        ba[1] = ba[1] / ba[1];
    }
    int a = 0, b = 0;
    for (i = 2; i <= m; i++) {
        if (ba[i] < bba[i-1]) {
            b = bba[i-1] / ba[i];
            ba[i] = ba[i] * b;
            bba[i] = bba[i] * b;
            b = 0;
        }
        else if (ba[i] > bba[i-1]) {
            a = ba[i] / bba[i-1];
            ba[i] = ba[i] / a;
            bba[i] = bba[i] / a;
            a = 0;
        }
    }
    printf ("%d", bba[m]);
    return 0;
}