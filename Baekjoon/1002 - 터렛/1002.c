#include <stdio.h>

int main() {
    int t, x[2], y[2], r[2], maxr;
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++) {
        scanf("%d %d %d %d %d %d", &x[1], &y[1], &r[1], &x[0], &y[0], &r[0]);
        if(x[1] == x[0] && y[1] == y[0]) {
            if(r[1] == r[0]) printf("-1\n");
            else if(r[1] != r[0]) printf("0\n");
            continue;
        }
        maxr = r[1]>r[0]? 1:0;
        int d = (x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0]);

        if(r[maxr]*r[maxr] <= d) {
            if((r[1]+r[0])*(r[1]+r[0]) > d) {
                printf("2\n");
                continue;
            }
            else if((r[1]+r[0])*(r[1]+r[0]) == d) {
                printf("1\n");
                continue;
            }
            else {
                printf("0\n");
                continue;
            }
        }
        else {
            if((r[maxr]-r[1-maxr])*(r[maxr]-r[1-maxr]) == d) {
                printf("1\n");
                continue;
            }
            else if((r[maxr]-r[1-maxr])*(r[maxr]-r[1-maxr]) < d) {
                printf("2\n");
                continue;
            }
            else {
                printf("0\n");
                continue;
            }
        }
    }
}