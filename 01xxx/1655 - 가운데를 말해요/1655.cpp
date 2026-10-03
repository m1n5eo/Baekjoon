#include <bits/stdc++.h>
using namespace std;

int n, k, a, b;
priority_queue<int>minq;
priority_queue<int>maxq;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        if(minq.size() == 0) minq.push(k);
        else if(maxq.size() == 0) maxq.push(-k);
        else if(minq.size() <= maxq.size()) minq.push(k);
        else maxq.push(-k);
        if(minq.size() != 0 && maxq.size()!= 0 && minq.top() > -maxq.top()) {
            a = minq.top();
            b = -maxq.top();
            minq.pop();
            maxq.pop();
            minq.push(b);
            maxq.push(-a);
        }
        printf("%d", minq.top());
        //if(i != 0) printf(" %d", maxq.top());
        printf("\n");
    }
}
