#include <stdio.h>

long long int triangle[51][51];

int f(int n, int m) {
    triangle[n][m] = (triangle[n-1][m] + triangle[n][m-1]) % 100000000;
    if(n == 50 && m == 50) return 0;
    else if(m == 50) return f(n+1, 2);
    else return f(n, m+1);
}

int main() {
    long long int r, c;
    scanf("%lld %lld", &r, &c);
    for(int i = 1; i <= 50; i++) triangle[1][i] = triangle[i][1] = 1;
    f(2, 2);
    printf("%lld", triangle[r][c]);
}