#include <iostream>
#include <vector>
using namespace std;

int n, a, b, zero, one;
bool visited[333333];
vector<int> island[333333];

void dfs(int idx) {
    if(visited[idx] == true) return;

    visited[idx] = true;

    for(int i = 0; i < island[idx].size(); i++) {
        dfs(island[idx][i]);
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n-2; i++) {
        cin >> a >> b;

        island[a].push_back(b);
        island[b].push_back(a);
    }

    dfs(1);

    for(int i = 1; i <= n && (zero == 0 || one == 0); i++) {
        if(zero == 0 && visited[i] == false) zero = i;
        else if(one == 0 && visited[i] == true) one = i;
    }

    cout << zero << " " << one;

    return 0;
}