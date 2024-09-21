#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

int n, idx, arr[MAX], result[MAX];
bool check[MAX];
vector<int> v[MAX];

bool compare(int a, int b) {
    return arr[a] < arr[b];
}

void dfs(int x) {
    for(int i = 0; i < v[x].size(); i++) {
        if(check[v[x][i]] == false && v[x][i] == result[idx]) {
            check[v[x][i]] = true;
            idx += 1;
            dfs(v[x][i]);
        }
    }
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
        arr[result[i]] = i;
    }

    for(int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end(), compare);
    }

    check[1] = true; idx = 1;
    dfs(1);
    
    if(idx != n) cout << 0;
    else cout << 1;
}