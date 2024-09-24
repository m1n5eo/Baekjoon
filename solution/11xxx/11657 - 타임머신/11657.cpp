#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define INF 1234567890123456

struct type {
    lli start, end, cost;
};

int main() {
    FASTIO

    lli n, m, a, b, c;

    cin >> n >> m;

    vector<lli> distance(n+1, INF);
    vector<type> route;

    for(lli _ = 0; _ < m; _++) {
        cin >> a >> b >> c;
        route.push_back({a, b, c});
    }

    distance[1] = 0;

    for(lli round = 0; round < n; round++) {
        for(lli i = 0; i < m; i++) {
            lli now = route[i].start;
            lli next = route[i].end;
            lli Cost = route[i].cost;

            if(distance[now] != INF && distance[next] > distance[now] + Cost) {
                distance[next] = distance[now] + Cost;

                if(round == n-1) {
                    cout << -1;
                    exit(0);
                }
            }
        }
    }

    for(lli i = 2; i <= n; i++) {
        if(distance[i] != INF) cout << distance[i] << "\n";
        else cout << -1 << "\n";
    }
}