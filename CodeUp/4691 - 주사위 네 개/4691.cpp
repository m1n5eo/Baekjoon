#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, dice[5], sum[1002], maxx = -1234567890;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) sum[i] = 0;
    for(int t = 0; t < n; t++) {
        for(int i = 1; i <= 4; i++) scanf("%d", &dice[i]);
        sort(dice+1, dice+5);
        if(dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4]) {
            sum[t] = sum[t] + (50000+dice[1]*5000);
        }
        else if(dice[1] == dice[2] && dice[2] == dice[3] && dice[3] != dice[4]) {
            sum[t] = sum[t] + (10000 + dice[2]*1000);
        }
        else if(dice[1] != dice[2] && dice[2] == dice[3] && dice[3] == dice[4]) {
            sum[t] = sum[t] + (10000 + dice[2]*1000);
        }
        else if(dice[1] == dice[2] && dice[2] != dice[3] && dice[3] == dice[4]) {
            sum[t] = sum[t] + (2000 + dice[1]*500 + dice[3]*500);
        }
        else if(dice[1] == dice[2]) sum[t] = sum[t] + (1000 + dice[1]*100);
        else if(dice[2] == dice[3]) sum[t] = sum[t] + (1000 + dice[2]*100);
        else if(dice[3] == dice[4]) sum[t] = sum[t] + (1000 + dice[3]*100);
        else {
            sum[t] = sum[t] + dice[4]*100;
        }
        if(maxx < sum[t]) {
            maxx = sum[t];
        }
    }
    printf("%d", maxx);
}