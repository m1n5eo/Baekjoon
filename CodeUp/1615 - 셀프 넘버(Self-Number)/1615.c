#include <stdio.h>

int self[5001];

int check (int num) {
    int sum = num;
    while(num != 0) {
        sum = sum + (num % 10);
        num = num / 10;
    }
    return sum;
}

int main() {
    int n, m, dap = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= 5000; i++) {
        self[i] = check(i);
    }

    for(int i = n; i <= m; i++) {
        for(int j = 1; j <= 5000; j++) {
            if(self[j] == i) {
                break;
            }
            else if(j == 5000) {
                dap = dap + i;
            }
        }
    }
    printf("%d", dap);
}