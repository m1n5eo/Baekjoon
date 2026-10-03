#include <stdio.h>
#include <string.h>

int main() {
    char str[111];
    double score;
    scanf("%s", str);

    if(str[0] == 'A') score = 4.0;
    else if(str[0] == 'B') score = 3.0;
    else if(str[0] == 'C') score = 2.0;
    else if(str[0] == 'D') score = 1.0;
    else if(str[0] == 'F') score = 0.0;

    if(str[1] == '+') score += 0.3;
    else if(str[1] == '-') score -= 0.3;

    printf("%.1f", score);
}