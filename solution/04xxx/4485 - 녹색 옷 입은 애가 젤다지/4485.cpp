#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

struct type {
    int x, y, d;
};

struct compare {
    bool operator() (type &a, type &b) {
        if(a.d != b.d) return a.d > b.d;
        else if(a.x != b.x) return a.x > b.x;
        else return a.y > b.y;
    }
};

int n, temp, result;
vector<vector<int>> rupee, dist;
priority_queue<type, vector<type>, compare> pq;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int main() {
    FASTIO

    for(int tc = 1; cin >> n && n != 0; tc++) {
        for(int i = 0; i < n; i++) {
            rupee.push_back(vector<int>(0));
            dist.push_back(vector<int>(0));

            for(int j = 0; j < n; j++) {
                cin >> temp;

                rupee[i].push_back(temp);
                dist[i].push_back(INF);
            }
        }

        pq.push({0, 0, rupee[0][0]});
        dist[0][0] = rupee[0][0];

        while(pq.size()) {
            type now = pq.top();
            pq.pop();

            if(now.x == n-1 && now.y == n-1) {
                result = now.d;
                break;
            }

            for(int k = 0; k < 4; k++) {
                type next = {now.x + dx[k], now.y + dy[k], now.d};

                if(0 <= next.x && next.x < n && 0 <= next.y && next.y < n) {
                    next.d += rupee[next.x][next.y];

                    if(next.d < dist[next.x][next.y]) {
                        dist[next.x][next.y] = next.d;
                        pq.push({next.x, next.y, next.d});
                    }
                }
            }
        }

        cout << "Problem " << tc << ": " << result << "\n";

        rupee.clear();
        dist.clear();
        while(!pq.empty()) pq.pop();
    }
}