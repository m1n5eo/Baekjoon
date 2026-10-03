#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

int n, check[MAX], result[MAX];
bool visit[MAX];
vector<int> v[MAX];
queue<int> bfs;

bool compare(int a, int b) {
    return check[a] < check[b];
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        cin >> result[i];
        check[result[i]] = i;
    }

    for(int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end(), compare);
    }
    
    bfs.push(1);
    visit[1] = true;

    int idx = 1;

    while(bfs.size()) {
        int x = bfs.front();

        bfs.pop();

        for(int i = 0; i < v[x].size(); i++) {
            if(visit[v[x][i]] == false) {
                bfs.push(v[x][i]);
                visit[v[x][i]] = true;

                if(result[idx] == v[x][i]) idx += 1;
            }
        }
    }

    if(idx == n) cout << 1;
    else cout << 0;
}