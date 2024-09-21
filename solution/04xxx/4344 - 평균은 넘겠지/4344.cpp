#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    double score[1001];
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++) {
        double cnt = 0, avg = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%lf", &score[i]);
            avg += score[i];
        }
        avg /= n;
        for(int i = 0; i < n; i++) {
            if(score[i] > avg) {
                cnt++;
            }
        }
        cnt = cnt/n*100;
        printf("%2.3f%\n", cnt);
    }
}
