#include <bits/stdc++.h>
using namespace std;

priority_queue<int>minq;
priority_queue<int>maxq;

int main() {
    int t, n, k;
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++) {
        scanf("%d", &n);
        printf("%d\n", n/2+1);
        for(int i = 0; i < n; i++) {
            scanf("%d", &k);
            if(minq.size() == 0) minq.push(k);
            else if(maxq.size() == 0) maxq.push(-k);
            else if(minq.size() == maxq.size()) minq.push(k);
            else maxq.push(-k);
            if(minq.size() != 0 && maxq.size() != 0 && minq.top() > -maxq.top()) {
                int a = minq.top();
                int b = -maxq.top();
                minq.pop();
                maxq.pop();
                minq.push(b);
                maxq.push(-a);
            }
            if(i%2 == 0) printf("%d ", minq.top());
        }
        printf("\n");
        while(!minq.empty()) minq.pop();
        while(!maxq.empty()) maxq.pop();
    }
}
