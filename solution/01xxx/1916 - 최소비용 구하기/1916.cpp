#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define INF 2100000000
#define MAX 1111

int main() {
    FASTIO
    
    lli n, m, a, b, c;

    cin >> n;
    cin >> m;

    vector<vector<lli>> bus(n+1, vector<lli>(n+1, INF));
    vector<bool> visit(n+1, false);
    vector<lli> cost(n+1, INF);

    for(lli _ = 0; _ < m; _++) {
        cin >> a >> b >> c;
        bus[a][b] = min(bus[a][b], c);
    }

    cin >> a >> b;

    for(lli i = 1; i <= n; i++) {
        bus[i][i] = 0;
        cost[i] = bus[a][i];
    }

    visit[a] = true;

    for(lli _ = 0; _ < n; _++) {
        lli small = INF, index = 0;
        
        for(lli i = 1; i <= n; i++) {
            if(visit[i] == false && cost[i] <= small) {
                small = cost[i];
                index = i;
            }
        }

        if(index == 0) break;

        visit[index] = true;

        for(lli i = 1; i <= n; i++) {
            if(visit[i] == false) {
                if(cost[index] + bus[index][i] < cost[i]) {
                    cost[i] = cost[index] + bus[index][i];
                }
            }
        }
    }

    cout << cost[b];
}