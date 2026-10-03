#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 222

vector<vector<int>> graph(MAX);
vector<int> a(MAX, -1), b(MAX, -1);
vector<bool> visited;

bool dfs(int x) {
    visited[x] = true;
    for(int y : graph[x]) {
        if(b[y] == -1 || (!visited[b[y]] && dfs(b[y]))) {
            a[x] = y;
            b[y] = x;
            return true;
        }
    }
    return false;
}

int solution() {
    int n, m;
    cin >> n >> m;
    vector<int> tshirt;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        tshirt.push_back(temp);
    }
    vector<int> collar;
    for(int i = 0; i < m; i++) {
        int temp; cin >> temp;
        collar.push_back(temp);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(tshirt[i] <= collar[j]*2 && collar[j]*4 <= tshirt[i]*3) graph[i].push_back(j);
            else if(tshirt[i] <= collar[j] && collar[j]*4 <= tshirt[i]*5) graph[i].push_back(j);
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