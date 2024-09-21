#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

int n, m;
vector<int> v;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);
        pq.push({temp, i});
    }

    cin >> m;

    for(int i = 0; i < m; i++) {
        int mode, a, b;
        cin >> mode;

        if(mode == 1) {
            cin >> a >> b;
            
            pq.push({b, a-1});
            v[a-1] = b;
        }
        else if(mode == 2) {
            while(true) {
                if(v[pq.top().second] == pq.top().first) {
                    cout << pq.top().second+1 << "\n";
                    break;
                }
                else pq.pop();
            }
        }
    }
}