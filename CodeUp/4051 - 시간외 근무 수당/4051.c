#include <stdio.h>

int main() {
    double start, end, time = 0, money;
    for(int i = 0; i < 5; i++) {
        scanf("%lf %lf", &start, &end);
        if(end - start >= 1 && end - start < 5) {
            time = time + end - start - 1;
        }
        else if(end - start >= 5)
            time = time + 4;
    }

    money = time * 10000;

    if(time >= 15) {
        money = money - money*5/100;
    }
    else if(time <= 5) {
         money = money + money*5/100;
    }

    printf("%.0lf", money);
}