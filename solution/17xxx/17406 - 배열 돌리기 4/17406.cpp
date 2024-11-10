#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000
#define MAX 55

struct type {
    int rr, cc, ss;
};

int n, m, k, r, c, s, result = INF;
vector<vector<int>> arr(MAX, vector<int>(MAX, 0)), rtn;
vector<type> order, arrange;
vector<bool> check(MAX, false);

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void Find() {
    for(int i = 1; i <= n; i++) {
        int sum = 0;

        for(int j = 1; j <= m; j++) {
            sum += rtn[i][j];
        }

        result = min(result, sum);
    }
}

vector<vector<int>> rotation(int a, int b, int size) {
    vector<vector<int>> next = rtn;

    for(int t = size; t >= 1; t--) {
        int sw = 0, x = a-t, y = b-t;

        while(true) {
            int nx = x+dx[sw], ny = y+dy[sw];

            if(!(a-t <= nx && nx <= a+t && b-t <= ny && ny <= b+t)) {
                sw = (sw+1)%4;
                nx = x+dx[sw], ny = y+dy[sw];
            }

            next[nx][ny] = rtn[x][y];
            x = nx, y = ny;

            if(x == a-t && y == b-t) {
                break;
            }
        }
    }

    return next;
}

void backtracking(int cnt) {
    if(cnt == k) {
        rtn = arr;

        for(int i = 0; i < k; i++) {
            rtn = rotation(arrange[i].rr, arrange[i].cc, arrange[i].ss);
        }

        Find();
        return;
    }

    for(int i = 0; i < k; i++) {
        if(check[i] == false) {
            arrange.push_back(order[i]);
            check[i] = true;

            backtracking(cnt+1);

            arrange.erase(arrange.begin() + cnt);
            check[i] = false;
        }
    }
}

int main() {
    FASTIO
    
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int _ = 0; _ < k; _++) {
        cin >> r >> c >> s;
        order.push_back({r, c, s});
    }

    backtracking(0);

    cout << result;
}