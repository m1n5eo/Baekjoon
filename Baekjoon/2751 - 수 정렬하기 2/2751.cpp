#include <bits/stdc++.h>
using namespace std;

priority_queue<int>q;

int main() {
    int n, k;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        q.push(-k);
    }
    for(int i = 0; i < n; i++) {
        printf("%d\n", -q.top());
        q.pop();
    }
}