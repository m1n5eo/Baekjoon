#include <bits/stdc++.h>
using namespace std;

int t, n, k, visited[1111111];
char ch;

int main() {
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++) {
        scanf("%d", &n);
        priority_queue<pair<int,int>> maxheap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        for(int i = 0; i < n; i++) {
            scanf(" %c %d", &ch, &k);
            if(ch == 'I') {
                minheap.push({k, i});
                maxheap.push({k, i});
                visited[i] = 1;
            }
            else if(ch == 'D') {
                if(k == -1) {
                    while(minheap.size() && !visited[minheap.top().second]) minheap.pop();
                    if(minheap.size()) {
                        visited[minheap.top().second] = 0;
                        minheap.pop();
                    }
                }
                else if(k == 1) {
                    while(maxheap.size() && !visited[maxheap.top().second]) maxheap.pop();
                    if(maxheap.size()) {
                        visited[maxheap.top().second] = 0;
                        maxheap.pop();
                    }
                }
            }
        }
        while(maxheap.size() && !visited[maxheap.top().second]) maxheap.pop();
        while(minheap.size() && !visited[minheap.top().second]) minheap.pop();
        if(minheap.size() && maxheap.size()) printf("%d %d\n", maxheap.top().first, minheap.top().first);
        else printf("EMPTY\n");
    }
}