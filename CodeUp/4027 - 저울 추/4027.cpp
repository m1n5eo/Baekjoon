#include <bits/stdc++.h>

using namespace std;

int pluss[11], minuss[11];

int main() {
    int n, k, i = 0, j = 0, ca = 0, cb = 0;
    scanf("%d", &n);
    if(n % 3 == 1) pluss[i++] = 1;
    else if(n % 3 == 2) minuss[j++] = 1;

    if(2 <= n % 9 && n % 9 <= 4) pluss[i++] = 3;
    else if(5 <= n % 9 && n % 9 <= 7) minuss[j++] = 3;

    if(5 <= n % 27 && n % 27 <= 13) pluss[i++] = 9;
    else if(14 <= n % 27 && n % 27 <= 22) minuss[j++] = 9;

    if(14 <= n % 81 && n % 81 <= 40) pluss[i++] = 27;
    else if(41 <= n % 81 && n % 81 <= 67) minuss[j++] = 27;

    if(41 <= n % 243 && n % 243 <= 121) pluss[i++] = 81;
    else if(122 <= n % 243 && n % 243 <= 202) minuss[j++] = 81;

    if(122 <= n % 729 && n % 729 <= 364) pluss[i++] = 243;
    else if(365 <= n % 729 && n % 729 <= 607) minuss[j++] = 243;

    if(365 <= n % 2187 && n % 2187 <= 1003) pluss[i++] = 729;

    for(int a = 0; a < i; a++) ca = ca + pluss[a];
    for(int b = 0; b < j; b++) cb = cb + minuss[b];

    if(ca < cb) {
        printf("%d ", n);
        for(int a = 0; a < i; a++) printf("%d ", pluss[a]);
        printf("0 ");
        for(int b = 0; b < j; b++) printf("%d ", minuss[b]);
    }
    else {
        printf("%d ", n);
        for(int b = 0; b < j; b++) printf("%d ", minuss[b]);
        printf("0 ");
        for(int a = 0; a < i; a++) printf("%d ", pluss[a]);
    }
}