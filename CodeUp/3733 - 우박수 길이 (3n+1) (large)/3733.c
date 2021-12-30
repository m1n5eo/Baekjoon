#include <stdio.h>

int n, m, maxnum, max = -1, aa, i = 0;
int save[10000003] = {0, 1,};

int check(long long int num) {
    if(num > 10000000) {
        if(num % 2 == 0) return check(num/2) + 1;
        else if(num % 2 == 1) return check(num*3+1) + 1;
    }
    else if(save[num]) return save[num];
    else if(num % 2 == 0) return save[num] = check(num/2) + 1;
    else if(num % 2 == 1) return save[num] = check(num*3+1) + 1;
}

void f(int n, int m) {
    for(long long int i = n; i <= m; i++) {
        aa = check(i);
        if(max < aa) {
            max = aa;
            maxnum = i;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    f(n, m);
    printf("%d %d", maxnum, max);
    return 0;
}