#include <bits/stdc++.h>
using namespace std;

struct rankData{
    int paper, talk;
};

bool compare(rankData &a, rankData &b) {
    return a.paper < b.paper;
}

int main() {
    struct rankData arr[100001];
    int t, n;
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d %d", &arr[i].paper, &arr[i].talk);
        sort(arr, arr+n, compare);
        int cnt = 1, mintalk = arr[0].talk;
        for(int i = 1; i < n; i++) {
            if(mintalk > arr[i].talk) {
                mintalk = arr[i].talk;
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}
