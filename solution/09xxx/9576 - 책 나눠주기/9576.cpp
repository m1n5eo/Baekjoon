#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

int n, m;
vector<pair<int, int>> range;
vector<int> a, b;
vector<bool> visited;

void init() {
    range.clear();
    a = vector<int>(MAX, -1);
    b = vector<int>(MAX, -1);
}

bool dfs(int x) {
    visited[x] = true;
    for(int y = range[x].first; y <= range[x].second; y++) {
        if(b[y] == -1 || (!visited[b[y]] && dfs(b[y]))) {
            a[x] = y;
            b[y] = x;
            return true;
        }
    }
    return false;
}

int solution() {
    init();
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        range.push_back({a-1, b-1});
    }

    int ret = 0;
    for(int i = 0; i < m; i++) {
        if(a[i] == -1) {
            visited = vector<bool>(MAX, false);
            if(dfs(i)) ret += 1;
        }
    }
    return ret;
}

int main() {
    FASTIO
    int tc; cin >> tc;
    while(tc--) cout << solution() << "\n";
}