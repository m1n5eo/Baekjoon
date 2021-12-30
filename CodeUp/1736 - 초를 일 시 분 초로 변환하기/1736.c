#include <stdio.h>

int main() {
    int day, hour, minute, second;
    scanf("%d", &second);
    day = second / 86400;
    second = second - ( day*86400 );
    hour = second / 3600;
    second = second - ( hour*3600 );
    minute = second / 60;
    second = second - ( minute*60 );
    printf("%d %d %d %d", day, hour, minute, second);
}