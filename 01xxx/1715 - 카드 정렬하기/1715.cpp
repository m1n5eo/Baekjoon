#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    int n, temp, sum = 0, hap;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        pq.push(temp);
    }
    for(int i = 1; i < n; i++) {
        hap = pq.top(); pq.pop();
        hap += pq.top(); pq.pop();
        pq.push(hap);
        sum += hap;
    }
    printf("%d", sum);
}