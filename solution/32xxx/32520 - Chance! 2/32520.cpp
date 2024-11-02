#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>
#define MAX 1111

int n, number, cnt = 0;
pii a, b;
vector<int> result(4, -1);
vector<vector<vector<bool>>> visit(MAX, vector<vector<bool>>(MAX, vector<bool>(4, false)));
queue<pii> bfs;

int main() {
    FASTIO

    cin >> a.first >> a.second;
    cin >> b.first >> b.second;

    bfs.push({a.first, a.second});
    visit[a.first+500][a.second+500][0] = true;

    if(a == b) {
        result[0] = cnt;
    }

    while(bfs.size()) {
        int bfs_size = bfs.size();
        cnt += 1;

        for(int _ = 0; _ < bfs_size; _++) {
            pii now = bfs.front();
            bfs.pop();

            pii next = {now.first+1, now.second};
            if(abs(next.first) <= 500) {
                if(visit[next.first+500][next.second+500][cnt%4] == false) {
                    visit[next.first+500][next.second+500][cnt%4] = true;

                    if(next.first == b.first && next.second == b.second) {
                        if(result[cnt%4] == -1) {
                            result[cnt%4] = cnt;
                            bfs.push({next});
                        }
                    }
                    else {
                        bfs.push({next});
                    }
                }
            }

            next = {now.first*2, now.second*2};
            if(abs(next.first) <= 500 && abs(next.second) <= 500) {
                if(visit[next.first+500][next.second+500][cnt%4] == false) {
                    visit[next.first+500][next.second+500][cnt%4] = true;

                    if(next.first == b.first && next.second == b.second) {
                        if(result[cnt%4] == -1) {
                            result[cnt%4] = cnt;
                            bfs.push({next});
                        }
                    }
                    else {
                        bfs.push({next});
                    }
                }
            }

            next = {-now.second, now.first};
            if(abs(next.second) <= 500) {
                if(visit[next.first+500][next.second+500][cnt%4] == false) {
                    visit[next.first+500][next.second+500][cnt%4] = true;

                    if(next.first == b.first && next.second == b.second) {
                        if(result[cnt%4] == -1) {
                            result[cnt%4] = cnt;
                            bfs.push({next});
                        }
                    }
                    else {
                        bfs.push({next});
                    }
                }
            }
        }
    }

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> number;

        if(result[number%4] != -1 && result[number%4] <= number) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}