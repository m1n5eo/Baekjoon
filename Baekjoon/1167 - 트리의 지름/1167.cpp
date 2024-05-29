#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n, parent, child, length, start_point, max_distance;
bool visited[111111];
vector<pair<int, int>> node[111111];

void dfs(int point, int distance) {
    if(visited[point] == true) return;

    visited[point] = true;

    if(max_distance < distance) {
        max_distance = distance;
        start_point = point;
    }

    for(int i = 0; i < node[point].size(); i++) {
        dfs(node[point][i].first, distance+node[point][i].second);
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> parent;
        while(true) {
            cin >> child;
            if(child == -1) {
                break;
            }
            cin >> length;

            node[parent].push_back({child, length});
        }
    }

    dfs(1, 0);

    for(int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    dfs(start_point, 0);

    cout << max_distance;

    return 0;
}