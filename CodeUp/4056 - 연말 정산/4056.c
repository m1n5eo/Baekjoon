#include <stdio.h>

int main() {
    int money;
    scanf("%d", &money);
    if(money <= 500) printf("%d", money*70/100);
    else if(money > 500 && money <= 1500)  printf("%d", 350+(money-500)*40/100);
    else if(money > 1500 && money <= 4500) printf("%d", 750+(money-1500)*15/100);
    else if(money > 4500 && money <= 10000) printf("%d", 1200+(money-4500)*5/100);
    else if(money > 10000) printf("%d", 1475+(money-10000)*2/100);
}