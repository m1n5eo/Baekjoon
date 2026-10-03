#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 222

int n, m;
vector<vector<int>> cow(MAX);
vector<int> a(MAX, -1), b(MAX, -1);
vector<bool> visited;

bool dfs(int x) {
    visited[x] = true;
    for(int y : cow[x]) {
        if(b[y] == -1 || (!visited[b[y]] && dfs(b[y]))) {
            a[x] = y;
            b[y] = x;
            return true;
        }
    }
    return false;
}

int solution() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            int temp; cin >> temp;
            cow[i].push_back(temp-1);
        }
    }

    int ret = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == -1) {
            visited = vector<bool>(MAX, false);
            if(dfs(i)) ret += 1;
        }
    }
    return ret;
}

int main() {
    FASTIO
    cout << solution();
}