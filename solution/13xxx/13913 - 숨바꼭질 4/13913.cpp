#include <bits/stdc++.h>
using namespace std;

int n, k, immi = 1234567890;
int sec[222222], chk[222222], arr[222222];

queue <int> q;

int main() {
    scanf("%d %d", &n, &k);
    q.push(n);
    sec[n] = 0;
    chk[n] = 1;
    while(q.empty() == 0) {
        int pos = q.front();
        q.pop();
        if(pos-1 >= 0 && chk[pos-1] == 0) {
            chk[pos-1] = 1;
            sec[pos-1] = sec[pos]+1;
            q.push(pos-1);
            arr[pos-1] = pos;
        }
        if(pos+1 <= 100000 && chk[pos+1] == 0) {
            chk[pos+1] = 1;
            sec[pos+1] = sec[pos]+1;
            q.push(pos+1);
            arr[pos+1] = pos;
        }
        if(pos*2 <= 100000 && chk[pos*2] == 0) {
            chk[pos*2] = 1;
            sec[pos*2] = sec[pos]+1;
            q.push(pos*2);
            arr[pos*2] = pos;
        }
    }
    /*for(int i = 1; i <= 50; i++) {
        printf("%d ", arr[i]);
        if(i%10==0) printf("\n");
    }
    printf("\n");*/
    printf("%d\n", sec[k]);

    stack <int> s;
    s.push(k);
    int h = k;
    for(int i = 0; i < sec[k]; i++) {
        s.push(arr[h]);
        h = arr[h];
    }
    for(int i = 0; i <= sec[k]; i++) {
        printf("%d ", s.top());
        s.pop();
    }
}
