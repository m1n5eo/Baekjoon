#include <bits/stdc++.h>
using namespace std;

int n, k;
int sec[222222], chk[222222];

queue <int> q;

int main() {
    scanf("%d %d", &n, &k);
    q.push(n);
    sec[n] = 0;
    chk[n] = 1;
    while(q.empty() == 0) {
        int pos = q.front();
        q.pop();
        if(pos*2 <= 100000 && chk[pos*2] == 0) {
            chk[pos*2] = 1;
            sec[pos*2] = sec[pos];
            q.push(pos*2);
        }
        if(pos-1 >= 0 && chk[pos-1] == 0) {
            chk[pos-1] = 1;
            sec[pos-1] = sec[pos]+1;
            q.push(pos-1);
        }
        if(pos+1 <= 100000 && chk[pos+1] == 0) {
            chk[pos+1] = 1;
            sec[pos+1] = sec[pos]+1;
            q.push(pos+1);
        }
    }
    printf("%d", sec[k]);
}
