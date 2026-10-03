#include <bits/stdc++.h>
using namespace std;

int n, k, cnt = 0;
priority_queue<int>pq;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        if(k > 0) {
            pq.push(-k);
            cnt++;
        }
        else if(k == 0) {
            if(cnt == 0) {
                printf("0\n");
                continue;
            }
            printf("%d\n", -pq.top());
            pq.pop();
            cnt--;
        }
    }
}
