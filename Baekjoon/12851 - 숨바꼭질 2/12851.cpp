#include <bits/stdc++.h> ///bj.1697
using namespace std;

int n, k, immi = 1234567890;
int sec[222222], chk[222222], cnt[222222];

queue <int> q;

int main() {
    scanf("%d %d", &n, &k);
    q.push(n);
    sec[n] = 0;
    chk[n] = 1;
    cnt[n] = 1;
    while(q.empty() == 0) {
        int pos = q.front();
        q.pop();
        if(pos-1 >= 0) {
            if(chk[pos-1] == 0){
                chk[pos-1] = 1;
                sec[pos-1] = sec[pos]+1;
                q.push(pos-1);
                cnt[pos-1] = cnt[pos];
            }
            else if(sec[pos-1] == sec[pos]+1) cnt[pos-1] += cnt[pos];
        }
        if(pos+1 <= 100000) {
            if(chk[pos+1] == 0) {
                chk[pos+1] = 1;
                sec[pos+1] = sec[pos]+1;
                q.push(pos+1);
                cnt[pos+1] = cnt[pos];
            }
            else if(sec[pos+1] == sec[pos]+1) cnt[pos+1] += cnt[pos];
        }
        if(pos*2 <= 100000) {
            if(chk[pos*2] == 0) {
                chk[pos*2] = 1;
                sec[pos*2] = sec[pos]+1;
                q.push(pos*2);
                cnt[pos*2] = cnt[pos];
            }
            else if(sec[pos*2] == sec[pos]+1) cnt[pos*2] += cnt[pos];
        }
    }
    //for(int i = 0; i <= k; i++) printf("%d", cnt[i]);
    //printf("\n");
    printf("%d\n%d", sec[k], cnt[k]);
}
