#include <bits/stdc++.h>
using namespace std;

int main() {
    int time, a, b, c;
    scanf("%d", &time);
    if(time%10) printf("-1");
    else printf("%d %d %d", time/300, (time-time/300*300)/60, ((time-time/300*300)-(time-time/300*300)/60*60)/10);
}
