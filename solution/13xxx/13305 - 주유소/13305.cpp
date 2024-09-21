#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, dis[100001], cost[100001];
    long long int sum = 0;
    scanf("%lld", &n);
    for(int i = 0; i < n-1; i++) scanf("%d", &dis[i]);
    for(int i = 0; i < n; i++) scanf("%d", &cost[i]);
    int mincost = cost[0];
    for(int i = 0; i < n-1; i++) {
        sum += (long long int)mincost*(long long int)dis[i];
        mincost = min(mincost, cost[i+1]);
    }
    printf("%lld", sum);
}
