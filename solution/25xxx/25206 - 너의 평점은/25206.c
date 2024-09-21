#include <stdio.h>
#include <string.h>

char str[111], rank[11];
double score, cnt, sum;

int main() {
    for(int i = 0; i < 20; i++) {
        scanf("%s %lf %s", str, &score, rank);
        cnt += score;
        if(!strcmp(rank, "A+")) sum += score*4.5;
        else if(!strcmp(rank, "A0")) sum += score*4.0;
        else if(!strcmp(rank, "B+")) sum += score*3.5;
        else if(!strcmp(rank, "B0")) sum += score*3.0;
        else if(!strcmp(rank, "C+")) sum += score*2.5;
        else if(!strcmp(rank, "C0")) sum += score*2.0;
        else if(!strcmp(rank, "D+")) sum += score*1.5;
        else if(!strcmp(rank, "D0")) sum += score*1.0;
        else if(!strcmp(rank, "F")) sum += score*0.0;
        else cnt -= score;
    }
    printf("%.6lf", sum/cnt);
}