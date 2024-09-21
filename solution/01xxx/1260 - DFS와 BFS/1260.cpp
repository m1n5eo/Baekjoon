#include <bits/stdc++.h>
using namespace std;

int n, m, v, a, b;
int arr[1001][1001], visit[1001];
queue <int> q;

void bfs(int idx) {
    visit[idx] = 1;
    printf("%d ", idx);
    q.push(idx);
    while(1) {
        int num = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            if (arr[num][i] == 1 && visit[i] == 0){
                visit[i] = 1;
                printf("%d ", i);
                q.push(i);
            }
        }
        if (q.empty()) break;
    }
}

void dfs(int idx) {
    visit[idx] = 1;
    printf("%d ", idx);
    for(int i = 1; i <= n; i++) {
        if(arr[idx][i] == 1 && visit[i] == 0) dfs(i);
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &v);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        arr[a][b] = arr[b][a] = 1;
    }

    dfs(v);
    printf("\n");
    for(int i = 0; i <= n; i++) visit[i] = 0;
    bfs(v);
}
