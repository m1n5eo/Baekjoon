#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890
#define MAX 4444

int n, m, x, y, res = INF;
vector<vector<int>> friends(MAX, vector<int>(0));
vector<vector<bool>> relation(MAX, vector<bool>(MAX, false));

bool compare(int a, int b) {
    return a > b;
}

int main() {
    FASTIO

    cin >> n >> m;
    for(int _ = 0; _ < m; _++) {
        cin >> x >> y;
        friends[x].push_back(y);
        friends[y].push_back(x);
        relation[x][y] = true;
        relation[y][x] = true;
    }
    for(int i = 1; i <= n; i++) sort(friends[i].begin(), friends[i].end(), compare);
    for(int i = 1; i <= n; i++) {
        if(friends[i].size() >= 2) {
            int friends_size = friends[i].size();
            for(int j = 0; j < friends_size && friends[i][j] > i; j++) {
                for(int k = j+1; k < friends_size && friends[i][k] > i; k++) {
                    if(relation[i][friends[i][j]] && relation[i][friends[i][k]] && relation[friends[i][j]][friends[i][k]]) {
                        res = min(res, (int)friends[i].size() + (int)friends[friends[i][j]].size() + (int)friends[friends[i][k]].size() - 6);
                    }
                }
            }
        }
    }
    cout << (res != INF? res : -1);
}