#include <stdio.h>

void cal(int num, int compan[], int cha[]) {
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < i; j++) {
            if(compan[i] < compan[j]) {
                cha[i] = cha[i] + 1;
            }
            if(compan[i] > compan[j]) {
                cha[j] = cha[j] + 1;
            }
        }
    }

    for(int i = 0; i < num; i++) printf("%d\n", cha[i]);
}

int main() {
    int n, company[2001], cham[2001];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &company[i]);
        cham[i] = 1;
    }
    cal(n, company, cham);
}