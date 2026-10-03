#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000

struct type {
    int start, end, dist;
};

double cal(double a, double b, double d) {
    double n = min(a, b), gap = max(a, b) - min(a, b);
    return max(a, b) + (d-gap)/2;
}

double solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> fw(n+1, vector<int>(n+1, INF));
    vector<type> graph;
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph.push_back({a, b, c});
        fw[a][b] = min(fw[a][b], c);
        fw[b][a] = min(fw[b][a], c);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j || j == k || k == i) continue;
                fw[i][j] = min(fw[i][j], fw[i][k]+fw[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++) fw[i][i] = 0;

    double ret = INF;
    for(int s = 1; s <= n; s++) {
        double find = 0;
        for(int i = 0; i < m; i++) find = max(find, cal(fw[s][graph[i].start], fw[s][graph[i].end], graph[i].dist));
        ret = min(ret, find);
    }
    return ret;
}

int main() {
    FASTIO
    cout << fixed << setprecision(1);
    cout << solve();
}