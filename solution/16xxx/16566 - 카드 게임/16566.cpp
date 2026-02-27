#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

vector<int> solution() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> minsu(m), chulsu(k);
    for(int i = 0; i < m; i++) cin >> minsu[i];
    for(int i = 0; i < k; i++) cin >> chulsu[i];

    vector<int> ret;
    vector<bool> visited(m, false);
    sort(minsu.begin(), minsu.end());
    for(int cs : chulsu) {
        int idx = upper_bound(minsu.begin(), minsu.end(), cs) - minsu.begin();
        while(visited[idx]) idx += 1;
        visited[idx] = true;
        ret.push_back(minsu[idx]);
    }
    return ret;
}

int main() {
    FASTIO
    for(int s : solution()) cout << s << " ";
}