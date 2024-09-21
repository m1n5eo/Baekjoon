#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2100000000

#define level first
#define index second

int t;

int main() {
    FASTIO

    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        int n, k;
        priority_queue<pair<int, int>> pq[11];
        vector<pair<int, int>> v;
        
        cin >> n >> k;

        for(int i = 0; i < n; i++) {
            int p, a;

            cin >> p >> a;
            
            v.push_back({p, a});
        }

        for(int i = 0; i < k; i++) {
            pq[v[i].first].push({v[i].second, i});
        }

        int result = 0;

        for(int h = 0; h <= n-k; h++) {
            int sum = 0;

            for(int i = 1; i <= 9; i++) {
                while(pq[i].size()) {
                    if(h <= pq[i].top().index && pq[i].top().index < h+k) break;
                    pq[i].pop();
                }

                if(pq[i].size() == 0) {
                    sum = -INF;
                    break;
                }
                else {
                    sum += pq[i].top().level;
                }
            }
            
            result = max(result, sum);

            int next = h+k;
            if(next < n) {
                pq[v[next].first].push({v[next].second, next});
            }
        }

        cout << result << "\n";
    }
}