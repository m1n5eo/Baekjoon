#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

vector<int> dx = {0, -1, 0};
vector<int> dy = {-1, 0, 1};

bool empty_castle(vector<vector<int>> castle) {
    int n = castle.size(), m = castle[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(castle[i][j] == 1) return false;
        }
    }
    return true;
}

vector<vector<int>> next_castle(vector<vector<int>> castle) {
    int n = castle.size(), m = castle[0].size();
    vector<vector<int>> ret(n, vector<int>(m, 0));
    for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            if(castle[i][j] == 1) {
                ret[i+1][j] = 1;
            }
        }
    }
    return ret;
}

int solve() {
    int n, m, dist;
    cin >> n >> m >> dist;
    vector<vector<int>> castle(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> castle[i][j];
        }
    }

    int ret = 0;
    vector<vector<int>> init = castle;
    for(int i = 0; i < m; i++) {
        for(int j = i+1; j < m; j++) {
            for(int k = j+1; k < m; k++) {
                int cnt = 0;
                while(!empty_castle(castle)) {
                    bool sw = true;
                    set<pair<int, int>> shot;
                    vector<vector<bool>> visit(n+1, vector<bool>(m, false));
                    queue<pair<int, int>> q;
                    q.push({n, i});
                    while(!q.empty() && sw) {
                        pair<int, int> now = q.front();
                        q.pop();
                        for(int kdx = 0; kdx < 3; kdx++) {
                            pair<int, int> next = {now.first+dx[kdx], now.second+dy[kdx]};
                            if(!(0 <= next.first && next.first < n && 0 <= next.second && next.second < m)) continue;
                            else if(abs(n-next.first) + abs(i-next.second) > dist) {
                                sw = false;
                                break;
                            }
                            else if(visit[next.first][next.second] == true) continue;
                            else if(castle[next.first][next.second] == 1) {
                                visit[next.first][next.second] = true;
                                shot.insert(next);
                                sw = false;
                                break;
                            }
                            else if(castle[next.first][next.second] == 0) {
                                visit[next.first][next.second] = true;
                                q.push(next);
                            }
                        }
                    }

                    sw = true;
                    visit = vector<vector<bool>>(n+1, vector<bool>(m, false));
                    while(!q.empty()) q.pop();
                    q.push({n, j});
                    while(!q.empty() && sw) {
                        pair<int, int> now = q.front();
                        q.pop();
                        for(int kdx = 0; kdx < 3; kdx++) {
                            pair<int, int> next = {now.first+dx[kdx], now.second+dy[kdx]};
                            if(!(0 <= next.first && next.first < n && 0 <= next.second && next.second < m)) continue;
                            else if(abs(n-next.first) + abs(j-next.second) > dist) {
                                sw = false;
                                break;
                            }
                            else if(visit[next.first][next.second] == true) continue;
                            else if(castle[next.first][next.second] == 1) {
                                visit[next.first][next.second] = true;
                                shot.insert(next);
                                sw = false;
                                break;
                            }
                            else if(castle[next.first][next.second] == 0) {
                                visit[next.first][next.second] = true;
                                q.push(next);
                            }
                        }
                    }

                    sw = true;
                    visit = vector<vector<bool>>(n+1, vector<bool>(m, false));
                    while(!q.empty()) q.pop();
                    q.push({n, k});
                    while(!q.empty() && sw) {
                        pair<int, int> now = q.front();
                        q.pop();
                        for(int kdx = 0; kdx < 3; kdx++) {
                            pair<int, int> next = {now.first+dx[kdx], now.second+dy[kdx]};
                            if(!(0 <= next.first && next.first < n && 0 <= next.second && next.second < m)) continue;
                            else if(abs(n-next.first) + abs(k-next.second) > dist) {
                                sw = false;
                                break;
                            }
                            else if(visit[next.first][next.second] == true) continue;
                            else if(castle[next.first][next.second] == 1) {
                                visit[next.first][next.second] = true;
                                shot.insert(next);
                                sw = false;
                                break;
                            }
                            else if(castle[next.first][next.second] == 0) {
                                visit[next.first][next.second] = true;
                                q.push(next);
                            }
                        }
                    }

                    for(pair<int, int> s : shot) castle[s.first][s.second] = 0;
                    cnt += shot.size();
                    castle = next_castle(castle);
                }
                ret = max(ret, cnt);
                castle = init;
            }
        }
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}